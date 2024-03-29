/************************************************************************************************
*            FILE: MOTORS.H
*          DRIVER: MOTORS
*     DESCRIPTION: HEADER file for all MOTOR-related functions prototypes and constants
*
************************************************************************************************/

#ifndef MOTORS_H
#define MOTORS_H


/*- INCLUDES
************************************************************************************************/
#include <Arduino.h>


/*- CONSTANTS
************************************************************************************************/

// Right motor connections
#define PIN_ENA 3 //must be a PWM Pin | Speed Control.
#define PIN_IN1 4 //motion control
#define PIN_IN2 5 //motion control

// Left motor connections
#define PIN_ENB 9 //must be a PWM Pin | Speed Control.
#define PIN_IN3 7 //motion control
#define PIN_IN4 8 //motion control

//Defining motor output limits
#define minimumSpeed 20 //motors barely work at such a low speed
#define maximumSpeed 255 //maximum output for motors

#define speedFactorA  0.6
#define speedFactorB 0.5


/*- FUNCTIONS PROTOTYPES
************************************************************************************************/

//Initializing motors' input and enable pins
void motors_setup(void);

//Speed control functoin according to sent output speed from PID Controller
void move(int speed);

//Testing functions for motors to move forward, backward and stop
void moveForward();
void moveBackward();
void stop();


#endif /* MOTORS_H */