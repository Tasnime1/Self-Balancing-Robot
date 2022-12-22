/************************************************************************************************
*            FILE: MPU6050.H
*          DRIVER: MPU6050
*     DESCRIPTION: HEADER file for all MPU6050-related functions prototypes and constants
*
************************************************************************************************/

#ifndef MPU6050_H
#define MPU6050_H


/*- INCLUDES
************************************************************************************************/

#include <Arduino.h>

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"


/*- CONSTANTS
************************************************************************************************/
#define EXTERNAL_INTERRUPT0 0  // used for MPU6050 interrupt signal; attached to ExInt0 on pin2 of Arduino

/*- ISR attached to pin2|ExInt0
************************************************************************************************/

void dmpDataReady();


/*- FUNCTIONS PROTOTYPES
************************************************************************************************/

//Settung up DMP of MPU6050; Digital Motion Processor, provides accurate readings of accelerations, angles...etc
void mpu_setup();
//Function to constantly update mpu readings from DMP
void mpu_update();

//Returning required angles to be input for PID
float return_pitch(); //around Y

#endif /* MPU6050_H */