
/************************************************************************************************
*            FILE: TEST.H
*          DRIVER: TEST
*     DESCRIPTION: Header file for all TEST-related functions prototypes and constants
*
************************************************************************************************/

#ifndef TEST_H
#define TEST_H

/*- INCLUDES
************************************************************************************************/
#include <Arduino.h>

#include "motors.h"
#include "mpu6050.h"
#include "pid.h"


/*- FUNCTIONS' PROTOTYPES
************************************************************************************************/

//Testing all drivers here
void test_motors();
void test_mpu6050();
void test_pid(float input);

#endif /* TEST_H */