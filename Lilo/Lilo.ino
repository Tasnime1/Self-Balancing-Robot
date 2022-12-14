#include "App.h"

void setup() {
  Serial.begin(115200);
  App_init();
}

void loop() {
  App_start();
  //App_test();
}
