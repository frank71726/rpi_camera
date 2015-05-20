/*
 * mcp23017.c:
 *	Extend wiringPi with the MCP 23017 I2C GPIO expander chip
 *	Copyright (c) 2013 Gordon Henderson
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as
 *    published by the Free Software Foundation, either version 3 of the
 *    License, or (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with wiringPi.
 *    If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#include "wiringPi.h"
#include "wiringPiI2C.h"
#include "mcp23x0817.h"

#include "mcp23017.h"

/*
 * globalCounter:
 *	Global variable to count interrupts
 *	Should be declared volatile to make sure the compiler doesn't cache it.
 */
static volatile int globalCounter;


static volatile pthread_t thread_is24c16;
/*
 * myPinMode:
 *********************************************************************************
 */

static void myPinMode (struct wiringPiNodeStruct *node, int pin, int mode)
{
  int mask, old, reg ;

  pin -= node->pinBase ;

  if (pin < 8)		/* Bank A*/
    reg  = MCP23x17_IODIRA ;
  else
  {
    reg  = MCP23x17_IODIRB ;
    pin &= 0x07 ;
  }

  mask = 1 << pin ;
  old  = wiringPiI2CReadReg8 (node->fd, reg) ;

  if (mode == OUTPUT)
    old &= (~mask) ;
  else
    old |=   mask ;

  wiringPiI2CWriteReg8 (node->fd, reg, old) ;
}


/*
 * myPullUpDnControl:
 *********************************************************************************
 */

static void myPullUpDnControl (struct wiringPiNodeStruct *node, int pin, int mode)
{
  int mask, old, reg ;

  pin -= node->pinBase ;

  if (pin < 8)		/* Bank A*/
    reg  = MCP23x17_GPPUA ;
  else
  {
    reg  = MCP23x17_GPPUB ;
    pin &= 0x07 ;
  }

  mask = 1 << pin ;
  old  = wiringPiI2CReadReg8 (node->fd, reg) ;

  if (mode == PUD_UP)
    old |=   mask ;
  else
    old &= (~mask) ;

  wiringPiI2CWriteReg8 (node->fd, reg, old) ;
}


/*
 * myDigitalWrite:
 *********************************************************************************
 */

static void myDigitalWrite (struct wiringPiNodeStruct *node, int pin, int value)
{
  int bit, old ;

  pin -= node->pinBase ;	/* Pin now 0-15*/

  bit = 1 << (pin & 7) ;

  if (pin < 8)			/* Bank A*/
  {
    old = node->data2 ;

    if (value == LOW)
      old &= (~bit) ;
    else
      old |=   bit ;

    wiringPiI2CWriteReg8 (node->fd, MCP23x17_GPIOA, old) ;
    node->data2 = old ;
  }
  else				/* Bank B*/
  {
    old = node->data3 ;

    if (value == LOW)
      old &= (~bit) ;
    else
      old |=   bit ;

    wiringPiI2CWriteReg8 (node->fd, MCP23x17_GPIOB, old) ;
    node->data3 = old ;
  }
}


/*
 * myDigitalRead:
 *********************************************************************************
 */

static int myDigitalRead (struct wiringPiNodeStruct *node, int pin)
{
  int mask, value, gpio ;

  pin -= node->pinBase ;

  if (pin < 8)		/* Bank A*/
    gpio  = MCP23x17_GPIOA ;
  else
  {
    gpio  = MCP23x17_GPIOB ;
    pin  &= 0x07 ;
  }

  mask  = 1 << pin ;
  value = wiringPiI2CReadReg8 (node->fd, gpio) ;

  if ((value & mask) == 0)
    return LOW ;
  else
    return HIGH ;
}

/*
 * myI2CWrite:
 *********************************************************************************
 */

static void myI2CWrite (struct wiringPiNodeStruct *node, int reg, int value)
{
    wiringPiI2CWriteReg8 (node->fd, reg, value) ;
}
/*
 * myI2CRead:
 *********************************************************************************
 */

static char myI2CRead (struct wiringPiNodeStruct *node, int reg)
{
    int value;

    value = wiringPiI2CReadReg8 (node->fd, reg) ;
    return value;
}

/*
 * myInterrupt:
 *********************************************************************************
 */
void myInterrupt5 (void) { ++globalCounter ; }

static PI_THREAD (is24c16_thread)
{
    int gotOne ;
    int myCounter;
    int num, i;
    int* j=(int*)dummy;
    j++;

    i = 0;
    globalCounter = myCounter = 0 ;

    while(1)
    {
        gotOne = 0 ;
        printf ("Waiting ISR PIN5... ") ; fflush (stdout) ;

        while(1)
        {
                if (globalCounter != myCounter)
                {
                    printf (" Int on pin %d: Counter: %5d\n", 5, globalCounter) ;
                    myCounter = globalCounter ;
                    ++gotOne ;
                }

            if (gotOne != 0)
                break ;
        }

        printf("+++ IS24C16 test starting +++\n");

        if(i==0)
            printf("IS24C16 start writing 0xaa from 0 to 2048\n");
        else
            printf("IS24C16 start writing 0x55 from 0 to 2048\n");

        for(num=0; num<2048; num++)
        {
            printf(".");
            if(i==0)
                fr_i2cWrite(150, num, 0xaa);
            else
                fr_i2cWrite(150, num, 0x55);
            delay (10) ;/* write cycle time*/
        }
        printf("\n");

        printf("      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");
        for(num=0; num<2048; num++)
        {
            if(((num+1) % 16) == 1)
                printf("%03x: %02x ", num/16, fr_i2cRead(150, num));
            else if(((num+1) % 16) == 0)
                printf("%02x\n",fr_i2cRead(150, num));
            else
                printf("%02x ",fr_i2cRead(150, num));
            delay (1) ;
        }
        printf("\n+++ IS24C16 test stop +++\n");
        if(++i > 1)
            i=0;
        printf("\n================STOP========================%d\n",i);
    }
    return NULL;
}
/*
 * mcp23017Setup:
 *	Create a new instance of an MCP23017 I2C GPIO interface. We know it
 *	has 16 pins, so all we need to know here is the I2C address and the
 *	user-defined pin base.
 *********************************************************************************
 */
int is24c16Setup (const int pinBase, const int i2cAddress)
{
    pthread_t myThread ;
  int fd ;
  struct wiringPiNodeStruct *node ;

  if ((fd = wiringPiI2CSetup (i2cAddress)) < 0)
    return fd ;

  node = wiringPiNewNode (pinBase, 1) ;

  node->fd              = fd ;
  node->i2cRead         = myI2CRead;
  node->i2cWrite        = myI2CWrite ;

   if((pthread_create (&myThread, NULL, is24c16_thread, NULL)) != 0)
        printf("The following error occured %s ", strerror(errno));
    else
        thread_is24c16 = myThread ;

  return 0 ;
}
int mcp23017Setup (const int pinBase, const int i2cAddress)
{
  int fd ;
  struct wiringPiNodeStruct *node ;

  if ((fd = wiringPiI2CSetup (i2cAddress)) < 0)
    return fd ;

  wiringPiI2CWriteReg8 (fd, MCP23x17_IOCON, IOCON_INIT) ;

  node = wiringPiNewNode (pinBase, 16) ;

  node->fd              = fd ;
  node->pinMode         = myPinMode ;
  node->pullUpDnControl = myPullUpDnControl ;
  node->digitalRead     = myDigitalRead ;
  node->digitalWrite    = myDigitalWrite ;
  node->data2           = wiringPiI2CReadReg8 (fd, MCP23x17_OLATA) ;
  node->data3           = wiringPiI2CReadReg8 (fd, MCP23x17_OLATB) ;

  return 0 ;
}
