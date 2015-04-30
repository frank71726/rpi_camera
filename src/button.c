#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <wiringPi.h>
#include <piFace.h>
#include "fr_softServo.h"

/* Use 200 as the pin-base for the PiFace board, and pick a pin*/
/*	for the LED that's not connected to a relay*/
#define	PIFACE	200

#define	MAX_PINS	8

pthread_mutex_t lock;
static volatile int speed_num;
static volatile pthread_t threads ;
static volatile pthread_t threads1 ;


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



    printf("+++ blinking thread starting ++++++++++++++++++++++++++++++\n");
    /* Setup the PiFace board*/
    piFaceSetup (PIFACE) ;

    for (;;)
    {
        for(num=2; num< MAX_PINS; num++)
        {
            digitalWrite ((PIFACE+num), HIGH) ;
            delay (speed[speed_num]) ;
        }
        for(num=2; num< MAX_PINS; num++)
        {
            digitalWrite ((PIFACE+num), LOW) ;
            delay (speed[speed_num]) ;
        }
    }

    return NULL;
}

static PI_THREAD (input_thread)
{
    int flag[2]={ 0 };
    int j;
    int* i=(int*)dummy;
    i++;

    while(1)
    {
        for(j=0; j<2; j++)
        {
            if((digitalRead(PIFACE+j) == 0) && (flag[j] == 0))
            {
                flag[j] = 1;
                switch(j)
                {
                    case 0:
                        printf("Button S1 is pushed\n");
                        pthread_mutex_lock(&lock);
                        if(++speed_num >= 5)
                            speed_num = 0;
                        pthread_mutex_unlock(&lock);
                        break;
                    case 1:
                        printf("Button S2 is pushed\n");
                        pthread_mutex_lock(&lock_servo);
                        if(++servo_num[0] > 2)
                            servo_num[0] = 0;
                        printf("servo_num = %d\n", servo_num[0]);
                        pthread_mutex_unlock(&lock_servo);

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

void blinkSetup(void)
{
    pthread_t myThread ;

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

    for(num=2; num<= MAX_PINS; num++)
        digitalWrite ((PIFACE+num), LOW) ;
}
