#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

#include "wiringPi.h"
#include "fr_softServo.h"


static int pinMap     [MAX_SERVOS] ;	/* Keep track of our pins*/
static int pulseWidth [MAX_SERVOS] ;	/* microseconds*/

static PI_THREAD (fr_softServoThread)
{
    int width_value[3]={ 1100, 1500, 1900 };
    int lastDelay, pin, servo ;
    struct timeval  tNow, tStart, tPeriod, tGap, tTotal ;
    struct timespec tNs ;
    int myDelays [MAX_SERVOS] ;
    int myPins   [MAX_SERVOS] ;
    int* i=(int*)dummy;
    i++;

    tTotal.tv_sec  =    0 ;
    tTotal.tv_usec = 20000 ;

    piHiPri (50) ;

    while(1)
    {
        gettimeofday (&tStart, NULL) ;

        for (servo = 0 ; servo < MAX_SERVOS ; ++servo)
        {
            pulseWidth[servo] = width_value[servo_num[servo]];
        }

        memcpy (myDelays, pulseWidth, sizeof (myDelays)) ;
        memcpy (myPins,   pinMap,     sizeof (myPins)) ;

        /* All on*/
        lastDelay = 0 ;
        for (servo = 0 ; servo < MAX_SERVOS ; ++servo)
        {
            if ((pin = myPins [servo]) == -1)
                continue ;

            digitalWrite (pin, HIGH) ;
            myDelays [servo] = myDelays [servo] - lastDelay ;/* setting delay time. */
            lastDelay += myDelays [servo] ;
        }

        /* Now loop, turning them all off as required*/
        for (servo = 0 ; servo < MAX_SERVOS ; ++servo)
        {
            if ((pin = myPins [servo]) == -1)
                continue ;

            delayMicroseconds (myDelays [servo]) ;
            digitalWrite (pin, LOW) ;
        }

        /* Wait until the end of an 8mS time-slot*/
        gettimeofday (&tNow, NULL) ;
        timersub (&tNow, &tStart, &tPeriod) ;
        timersub (&tTotal, &tPeriod, &tGap) ;
        tNs.tv_sec  = tGap.tv_sec ;
        tNs.tv_nsec = tGap.tv_usec * 1000 ;
        nanosleep (&tNs, NULL) ;
    }

    return NULL ;
}

/*
 * fr_softServoSetup:
 *	Setup the software servo system
 *********************************************************************************
 */

int fr_softServoSetup (int p7)
{
    int servo ;

    if (p7 != -1) { pinMode (p7, OUTPUT) ; digitalWrite (p7, LOW) ; }

    pinMap[0] = p7 ;

    for (servo = 0 ; servo < MAX_SERVOS ; ++servo)
    {
        pulseWidth [servo] = 1500 ;		/* Mid point*/
        pthread_mutex_lock(&lock_servo);
        servo_num[servo] = 1;
        pthread_mutex_unlock(&lock_servo);
    }

    return piThreadCreate (fr_softServoThread) ;
}
