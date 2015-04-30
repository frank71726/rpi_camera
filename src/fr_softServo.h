#ifndef __FR_SOFTSERVO_H_
#define __FR_SOFTSERVO_H_

#ifdef __cplusplus
extern "C" {
#endif

#define	MAX_SERVOS	1
pthread_mutex_t lock_servo;

extern int fr_softServoSetup(int);

volatile int servo_num[MAX_SERVOS];
#ifdef __cplusplus
}
#endif

#endif
