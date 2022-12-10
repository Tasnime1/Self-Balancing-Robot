#include "pid.h"

//DONE!!
//but you know tuning parameters is never done:")

//PID Initialization
double Kp = 0.25, Ki = 0.002, Kd = 0.0025;

//where it balances around y-axis; pitch angle*180/pi
double input, output, setpoint= 0;  
//creating an instance of PID to start using it
PID PID(&input, &output, &setpoint, Kp, Ki, Kd, PID::Direct);

void PID_setup()
{
  //By default it's manual so you have to change it
  PID.SetMode(AUTOMATIC);
  //Run PID to get a new output every 10 milliseconds
  PID.SetSampleTime(10);
  //By default it's from 0->255, so change it to indicate inclination direction as well as speed
  PID.SetOutputLimits(-120, 120); 
}

//Running PID Algorithm on output from mpu sensor; inclination angle
void PID_run(float in)
{
  input = in;
  PID.Compute();
}

//returning output to be sent to motors; output here is a speed ranging from -255->255, NEGATIVE JUST INDICATES DIRECTION and to be processed in motors' code
float get_pid_output()
{
  return output;
}
