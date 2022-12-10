#include "HardwareSerial.h"
#include "test.h"

//ULTRASONIC SENSOR TEST LEFT!

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

void test_ultrasonic()
{
  Serial.print("Distance is: ");
  Serial.print(calc_distance_ultrasonic());
  Serial.println("cm");
}

//Printing PID output to check it's actually working and computing results
void test_pid(float input)
{
  PID_run(input);
  Serial.println(get_pid_output());
}