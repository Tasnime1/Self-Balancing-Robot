/************************************************************************************************
*            FILE: PID.H
*          DRIVER: PID
*     DESCRIPTION: Header file for all PID-related functions prototypes and constants
*
************************************************************************************************/

#ifndef PID_H
#define PID_H


/*- INCLUDES
************************************************************************************************/
#include <Arduino.h>

#include"PID_v2.h"



/*- FUNCTIONS' PROTOTYPES
************************************************************************************************/
void PID_setup();
void PID_run(float in);
float get_pid_output();

#endif /* PID_H */