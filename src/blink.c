/*
 * blink.c:
 *	Simple "blink" test for the PiFace interface board.
 *
 * Copyright (c) 2012-2013 Gordon Henderson. <projects@drogon.net>
 ***********************************************************************
 * This file is part of wiringPi:
 *	https://projects.drogon.net/raspberry-pi/wiringpi/
 *
 *    wiringPi is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    wiringPi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#include <stdio.h>
#include <pthread.h>
#include <wiringPi.h>
#include <piFace.h>
#include <mcp23017.h>
#include "button.h"
#include "fr_softServo.h"


#define IS24C16_BASE 150

int main (int argc, char *argv [])
{
    int num, i;
    /* error: unused parameter 'argc' [-Werror=unused-parameter]*/
    /*error: unused parameter 'argv' [-Werror=unused-parameter] */
    while(argc)
    {
        printf("argc=%d", argc);
        printf("argv=%s\n",argv[argc--] );
    }

    printf ("Raspberry Pi PiFace Blink\n") ;
    printf ("=========================\n") ;

    wiringPiSetup() ;

    pinMode(0, OUTPUT);
    digitalWrite (0, HIGH) ;
    pinMode(2, OUTPUT);
    digitalWrite (2, HIGH) ;

    blinkSetup();
    fr_softServoSetup (1) ;/* gpio18, pin1*/


    printf("+++ IS24C16 test starting +++\n");
    is24c16Setup (IS24C16_BASE, 0x50);

    for(i=0; i<2; i++)
    {
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

    }
    printf("\n================STOP========================\n");
    while(1);
    blinkthreadStop();

    return 0 ;
}


