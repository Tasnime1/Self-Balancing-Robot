#ifndef PID_H
#define PID_H

#include <Arduino.h>

#include"PID_v2.h"

void PID_setup();
void PID_run(float in);
float get_pid_output();

#endif /* PID_H */