#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <wiringPi.h>
#include <piFace.h>
#include "fr_softServo.h"
#include "./wiringPi_lib/softPwm.h"

/* Use 200 as the pin-base for the PiFace board, and pick a pin*/
/*	for the LED that's not connected to a relay*/
#define	PIFACE  	200

#define	MAX_LEDS	8
#define MAX_BUT     3

pthread_mutex_t lock;
static volatile int speed_num;
static volatile pthread_t threads ;
static volatile pthread_t threads1 ;

/*
 * 1. Blinking piface output 2,3,4,5,6,7 leds,
 * 2. It will change blinking speed when button 1 is pushed.
 * */
static PI_THREAD (blink_thread)
{
    int speed[5]={ 500, 400, 300, 200, 100 };
    int num;
    int* i=(int*)dummy;
    i++;

    if(pthread_mutex_init(&(lock), NULL) != 0)
        printf("The following error occured %s ", strerror(errno));

    pthread_mutex_lock(&lock);
    speed_num = 0;
    pthread_mutex_unlock(&lock);

    printf("+++ blinking thread is starting +++\n");
    /* Setup the PiFace board*/
    piFaceSetup (PIFACE) ;

    while(1)
    {
        for(num=2; num< MAX_LEDS; num++)
        {
            digitalWrite ((PIFACE+num), HIGH) ;
            delay (speed[speed_num]) ;
        }
        for(num=2; num< MAX_LEDS; num++)
        {
            digitalWrite ((PIFACE+num), LOW) ;
            delay (speed[speed_num]) ;
        }
    }

    return NULL;
}

/*
 * Non-using interrupt to detect GPIO.
 * */
static PI_THREAD (input_thread)
{
    int flag[MAX_BUT]={ 0 };
    int j;
    int* i=(int*)dummy;
    i++;

    while(1)
    {
        for(j=0; j<3; j++)
        {
            if((digitalRead(PIFACE+j) == 0) && (flag[j] == 0))
            {
                flag[j] = 1;
                switch(j)
                {
                    case 0:
                        printf("---Button S1 is pushed---\n");
                        pthread_mutex_lock(&lock);
                        if(++speed_num >= 5)
                            speed_num = 0;
                        pthread_mutex_unlock(&lock);
                        break;
                    case 1:
                        printf("---Button S2 is pushed---\n");
                        pthread_mutex_lock(&lock_servo);
                        if(++servo_num[SERVO_0] > 2)
                            servo_num[SERVO_0] = 0;
                        printf("servo_num = %d\n", servo_num[0]);
                        pthread_mutex_unlock(&lock_servo);
                        break;
                    case 2:
                        printf("---Button S3 is pushed---\n");
                        pthread_mutex_lock(&lock_pwm);
                        if(++pwm_num[PWM_0] >= 8)
                            pwm_num[PWM_0] = 0;
                        printf("pwm_num = %d\n", pwm_num[PWM_0]);
                        pthread_mutex_unlock(&lock_pwm);
                        break;
                    default:
                        break;
                }
            }
            else if((digitalRead(PIFACE+j) == 1) && (flag[j] == 1))
                flag[j] = 0;
        }
    }

    return NULL;
}

void buttonSetup(void)
{
    pthread_t myThread ;

    pinMode(0, OUTPUT);/*button 0 math into gpio0 to change piface output 8 leds*/
    digitalWrite (0, HIGH) ;
    pinMode(2, OUTPUT);/*button 1 math into gpio2 to change servo angle.*/
    digitalWrite (2, HIGH) ;
    pinMode(4, OUTPUT);/*buootn 2 math into gpio4 to change pwm duty cycle.*/
    digitalWrite (4, HIGH) ;
    pinMode(5, INPUT);/*isr_buootn math into gpio5 to trigger interrupt.*/
    pullUpDnControl (5, PUD_UP);

    if((pthread_create (&myThread, NULL, blink_thread, NULL)) != 0)
        printf("The following error occured %s ", strerror(errno));
    else
        threads = myThread ;

    delay (100) ;

    if((pthread_create (&myThread, NULL, input_thread, NULL)) != 0)
        printf("The following error occured %s ", strerror(errno));
    else
        threads1 = myThread ;
}


void blinkthreadStop (void)
{
    int num;

    pthread_cancel (threads) ;
    pthread_join   (threads, NULL) ;

    for(num=2; num<= MAX_LEDS; num++)
        digitalWrite ((PIFACE+num), LOW) ;
}
