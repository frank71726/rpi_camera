/*
 * softPwm.h:
 *	Provide 2 channels of software driven PWM.
 *	Copyright (c) 2012 Gordon Henderson
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
#ifndef __SOFTPWM_H__
#define __SOFTPWM_H__

#ifdef __cplusplus
extern "C" {
#endif
/*
MAX_PINS:
This is more than the number of Pi pins because we can actually softPwm
pins that are on GPIO expanders. It's not that efficient and more than 1 or
2 pins on e.g. (SPI) mcp23s17 won't really be that effective, however...
*/
#define	MAX_PINS	1024

/*
   The PWM Frequency is derived from the "pulse time" below. Essentially,
   the frequency is a function of the range and this pulse time.
   The total period will be range * pulse time in µS, so a pulse time
   of 100 and a range of 100 gives a period of 100 * 100 = 10,000 µS
   which is a frequency of 100Hz.

   It's possible to get a higher frequency by lowering the pulse time,
   however CPU uage will skyrocket as wiringPi uses a hard-loop to time
   periods under 100µS - this is because the Linux timer calls are just
   accurate at all, and have an overhead.

   Another way to increase the frequency is to reduce the range - however
   that reduces the overall output accuracy...
   */
#define	PULSE_TIME	100

#define	NUM_PWM	  1
#define PWM_0     3/* pin2, gpio27*/
extern int  softPwmCreate (int pin, int value, int range) ;
extern void softPwmWrite  (int pin, int value) ;
extern void softPwmStop   (int pin) ;

pthread_mutex_t lock_pwm;
volatile int pwm_num[MAX_PINS];

#ifdef __cplusplus
}
#endif

#endif
