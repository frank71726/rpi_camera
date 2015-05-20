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
#include "./wiringPi_lib/mcp23017.h"
#include "./wiringPi_lib/softPwm.h"
#include "button.h"
#include "fr_softServo.h"

#define IS24C16_BASE 150

int main (int argc, char *argv [])
{
    /* int num, i;*/
    /* error: unused parameter 'argc' [-Werror=unused-parameter]*/
    /*error: unused parameter 'argv' [-Werror=unused-parameter] */
    while(argc)
    {
        printf("argc=%d", argc);
        printf("argv=%s\n",argv[argc--] );
    }

    printf ("Raspberry Pi Perpherial ......\n") ;
    printf ("==============================\n") ;

    wiringPiSetup() ;

    buttonSetup();
    wiringPiISR (5, INT_EDGE_FALLING, &myInterrupt5) ;/* pin5  is setted for isr */
    fr_softServoSetup (7) ;/* gpio4, pin7*/
    softPwmCreate (3, 0, 100) ;/*gpio22, pin3*/

    is24c16Setup (IS24C16_BASE, 0x50);

    while(1)
    {
    }

    blinkthreadStop();

    return 0 ;
}

