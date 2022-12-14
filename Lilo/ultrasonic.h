#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

#define echoPin 10 // attach pin x to pin Echo of HC-SR04
#define trigPin 11 //attach pin y to pin Trig of HC-SR04

void initialize_ultrasonic();
long calc_distance_ultrasonic();


#endif /* ULTRASONIC_H */