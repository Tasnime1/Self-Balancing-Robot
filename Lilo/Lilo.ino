#include "App.h"

void setup() {
  Serial.begin(9600);
  App_init();
}

void loop() {
  App_start();
  //App_test();
}
