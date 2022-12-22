/************************************************************************************************
*            FILE: APP.CPP
*          DRIVER: APP
*     DESCRIPTION: Source file for all APPLICATION-related functions declarations
*
************************************************************************************************/


/*- INCLUDES
************************************************************************************************/
#include "Arduino.h"
#include "HardwareSerial.h"
#include "App.h"


/*- FUNCTIONS' DECLARATION
************************************************************************************************/
void App_init(void) {
  PID_setup();
  mpu_setup();
  motors_setup();
}

/**************************************
/*- DRIVER FUNCTION FOR WHOLE PROGRAM
***************************************/
void App_start(void) {
  
  //frequently update MPU readings
  mpu_update();

  //getting latest inclination angle from MPU sensor
  float input = return_pitch();
  
  //Running PID Algorithm on new inputs
  PID_run(input);

  //Getting PID output values to be sent to motors
  float output = get_pid_output();

  //Sending output speed from PID to motors
  move(output);
}


/******************************************
/*- TEST FUNCTION FOR ONE DRIVER AT A TIME
*******************************************/
void App_test(void) {
  
  //Motors speed control test through serial monitor
  test_motors();

  //Inclination angle test
  //test_mpu6050();

  //PID output test; input should be taken from mpu first then sent to PID to be tested
  //float input = get_pid_output();
  //test_pid(input);

}
