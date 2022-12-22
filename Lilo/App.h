/************************************************************************************************
*            FILE: APP.H
*          DRIVER: APP
*     DESCRIPTION: Header file for all APPLICATION-related functions prototypes and constants
*
************************************************************************************************/

#ifndef APP_H
#define APP_H


/*- INCLUDES
************************************************************************************************/
#include <Arduino.h>

#include "mpu6050.h"
#include "pid.h"
#include "motors.h"

#include "test.h"


/*- FUNCTIONS' PROTOTYES
************************************************************************************************/
void App_init(void);
void App_start(void);
void App_test(void);


#endif /* APP.H */