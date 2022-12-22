/************************************************************************************************
*            FILE: TEST.CPP
*          DRIVER: TEST
*     DESCRIPTION: Source file for all TEST-related functions declarations
*
************************************************************************************************/


/*- INCLUDES
************************************************************************************************/
#include "test.h"



/*- FUNCTOINS DECLARATIONS
************************************************************************************************/

//Speed control test and input is from serial monitor
void test_motors()
{
  if(Serial.available())         
  { 
    int speed=Serial.parseInt();  //Receive speed from serial monitor
    move(speed); //send speed to motors
  }
  else
  {
    stop();
  }
  //Uncomment to test motors in a certain direction, also add delays and test compound movements
  //moveForward();
  //moveBackward();
}

//Printing inclination angle to check it's working
void test_mpu6050()
{
  mpu_update();
  Serial.println(return_pitch());    
}

//Printing PID output to check it's actually working and computing results
void test_pid(float input)
{
  PID_run(input);
  Serial.println(get_pid_output());
}