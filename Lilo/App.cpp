#include "Arduino.h"
#include "HardwareSerial.h"
#include "App.h"

//DRIVERS' INITIALIZATION
void App_init(void) {
  PID_setup();
  mpu_setup();
  //initialize_ultrasonic();
  motors_setup();
}

//PROGRAM FLOW/DRIVER FUNCTION
void App_start(void) {
  //frequently update MPU readings
  mpu_update();      
  //getting latest inclination angle from MPU sensor
  float input = return_pitch();
  //no mpu data - performing PID calculations and output to motors
  //Running PID Algorithm on new inputs


  PID_run(input);
  //Getting PID output values to be sent to motors
  float output = get_pid_output();


  //Debugging.
  //Serial.println(output);
  //Finally Sending output signal to motors in order to balance
  //if (abs(input) > 5)
  move(output);

  Serial.print("Input is: ");
  Serial.println(input);
  // Serial.print("yaw: ");
  // Serial.println(return_yaw());
  // Serial.print("pitch: ");
  // Serial.println(return_pitch());
  // Serial.print("roll: ");
  // Serial.println(return_roll());
  Serial.println(output); 

}

void App_test(void) {
  //UNCOMMENT ONE AT A TIME TO TEST A CERTAIN DRIVER; mpu6050, motors or PID Controller
  //Motors speed control test through serial monitor
  //test_motors();

  //Inclination angle test
  //test_mpu6050();

  //PID output test; input should be taken from mpu first then sent to PID to be tested
  //float input = get_pid_output();
  //test_pid(input);
  
  //test ultrasonic
  test_ultrasonic();
}
