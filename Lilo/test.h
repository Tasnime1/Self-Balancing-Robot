#ifndef TEST_H
#define TEST_H

//ULTRASONIC SENSOR TEST LEFT!

#include <Arduino.h>

#include "motors.h"
#include "mpu6050.h"
#include "ultrasonic.h"
#include "pid.h"

//Testing all drivers here
void test_motors();
void test_mpu6050();
void test_ultrasonic();
void test_pid(float input);

#endif /* TEST_H */