/************************************************************************************************
*            FILE: MOTORS.CPP
*          DRIVER: MOTORS
*     DESCRIPTION: Source file for all MOTOR-related functions declarations
*
************************************************************************************************/


/*- INCLUDES
************************************************************************************************/
#include "Arduino.h"
#include "motors.h"


/*- STATIC VARIABLES
************************************************************************************************/
static int currentSpeed, currentDirection;


/*- FUNCTIONS' DECLARATION
************************************************************************************************/
void motors_setup()
{
  // Motor A initialization
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_ENA, OUTPUT); //must be a PWM Pin; speed control

  // Motor B initialization
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT); //must be a PWM Pin; speed control
}

void move(int speed)
{
  int direction = 1;
    //if speed sent is in opposite direction then change variables accordingly to indicate right motor direction
    if (speed < 0)
    {
        direction = -1;
        speed= -1*speed;
    }
    //ensures speed is with range(20~255) or according to what's define as minimumSpeed
    speed = max(speed, minimumSpeed); //maximize over minimum speed
    speed = min(speed, maximumSpeed); //minimize over maximum speed
    
    //if speed sent to motors is similar to current speed then simply do nothing; code optimization
    if ((speed == currentSpeed) && (direction==currentDirection)) return;

    //setting speed sent to both wheels
    analogWrite(PIN_ENA, speed * speedFactorA);
    analogWrite(PIN_ENB, speed * speedFactorB);

    //detecting right ouptut direction on motor input pins through (direction) variable
    if(direction<0)
    {
      digitalWrite(PIN_IN1, LOW);
      digitalWrite(PIN_IN2, HIGH);
      digitalWrite(PIN_IN3, LOW);
      digitalWrite(PIN_IN4, HIGH);
    }
    else
    {
      digitalWrite(PIN_IN1, HIGH);
      digitalWrite(PIN_IN2, LOW);
      digitalWrite(PIN_IN3, HIGH);
      digitalWrite(PIN_IN4, LOW);
    }

    //saving current speed and direction for later use/comparison
    currentSpeed = speed;
    currentDirection = direction;
}

//*********************************************************NO DELAYS ADDED AFTER EACH MOTION, USER-PREFERENCE..****************************************************
void moveForward()
{ 
  //Setting motors in full speed and forward direction
  analogWrite(PIN_ENA, maximumSpeed);
  analogWrite(PIN_ENB, maximumSpeed);

  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
}

void moveBackward()
{
  //Setting motors in full speed and backward direction
  analogWrite(PIN_ENA, maximumSpeed);
  analogWrite(PIN_ENB, maximumSpeed);

  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
}

void stop()
{
  //Stopping motors through applying same output voltage on both; either both inputs HIGH or LOW
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, LOW);
}
