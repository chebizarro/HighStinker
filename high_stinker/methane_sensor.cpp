#include <Arduino.h>
#include "methane_sensor.h"

MethaneSensor::MethaneSensor(int input):
mInput(input),
mR0(.0),
mSlope(-0.318),
mYIntercept(1.133) {  }

void MethaneSensor::init() {
  pinMode(mInput, INPUT); // Set gas sensor as input
  calibrate();
}

void MethaneSensor::calibrate() {

  float sensorValue;
  int steps = 500;

  for (int x = 0; x < steps; x++) {
    sensorValue = sensorValue + analogRead(mInput); // Add analog values of sensor 500 times
  }
  
  sensorValue = sensorValue / float(steps); // Take average of readings
  float sensor_volt = sensorValue * (5.0 / 1023.0); // Convert average to voltage
  float RS_air = ((5.0 * 10.0) / sensor_volt) - 10.0; // Calculate RS in fresh air
  
  mR0 = RS_air / 4.4;

}


float MethaneSensor::get_value() {

  float sensorValue = analogRead(mInput);
  float sensor_volt = sensorValue * (5.0 / 1023.0); // Convert analog values to voltage
  float RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; // Get value of RS in a gas
  float ratio = RS_gas / mR0;
  double ppm_log = (log10(ratio) - mYIntercept) / mSlope; // Get ppm value in linear scale according to the the ratio value
  double ppm = pow(10, ppm_log); // Convert ppm value to log scale
  double percentage = ppm / 10000; // Convert to percentage

  return float(ppm);

}
