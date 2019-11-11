#ifndef sensoreyes_h
#define sensoreyes_h

#include <Arduino.h>

// Simple readout for the sensor eyes, supporting the HC-SR04 on D0 and GIOP10
class SensorEyes {
  public:
    // Initialize the sensor, opening the GPIOs
    void init();
    // Returns the last measured distance
    long getDistance();
    // Is a valid distance available
    bool distanceAvailable();
    // Do a measurement
    void measureDistance();
  private:
    long distance;
};

#endif
