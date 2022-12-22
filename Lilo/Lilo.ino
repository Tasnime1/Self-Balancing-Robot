/************************************************************************************************
*            FILE: LILO
*          DRIVER: ARDUINO
*     DESCRIPTION: Main (.ino) file where all the program starts.
*
************************************************************************************************/


/*- INCLUDES
************************************************************************************************/
#include "App.h"

void setup() {
  Serial.begin(115200);
  App_init();
}

void loop() {
  //Driver Function where all program logic runs
  App_start();

  //For testing specific drivers
  //App_test();
}
