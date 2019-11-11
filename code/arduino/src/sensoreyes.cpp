#include "sensoreyes.h"

#define echoPin 10 // Echo Pin
#define trigPin D0 // Trigger Pin

void SensorEyes::init() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  distance=0;
}

void SensorEyes::measureDistance() {
  long indistance = 0;
  int success = 0;
  for (int i=0; i<3; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    if (duration < 100000)
    indistance += duration/58.2;
    success++;
  }
  if (success > 0) {
    distance = indistance/success;
  }
}

long SensorEyes::getDistance() {
  return distance;
}

bool SensorEyes::distanceAvailable() {
  return (distance!=0);
}
