#include "stdint.h"
#ifndef MPU6050_H
#define MPU6050_H

//DONE!!

#include <Arduino.h>

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"


#define EXTERNAL_INTERRUPT0 0  // used for MPU6050 interrupt signal; attached to ExInt0 on pin2 of Arduino

//ISR attached to pin2|ExInt0.
void dmpDataReady();

//Settung up DMP of MPU6050; Digital Motion Processor, provides accurate readings of accelerations, angles...etc
void mpu_setup();
//Function to constantly update mpu readings from DMP
void mpu_update();
//Returning required angles to be input for PID
float return_pitch(); //around Y
float return_roll(); //around X
float return_yaw(); //around Z

#endif /* MPU6050_H */