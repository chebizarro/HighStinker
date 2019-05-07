
/*
 The High Stinker
 The High Stinker gives you the chance to test your fart potency.
 The average human can produce over 100ml of methane per day.
*/

float calibrate(int sensor) {
  float sensorValue;
  int steps = 500;
  for (int x = 0; x < steps; x++) {
    sensorValue = sensorValue + analogRead(sensor); // Add analog values of sensor 500 times
  }
  sensorValue = sensorValue / float(steps); // Take average of readings
  float sensor_volt = sensorValue * (5.0 / 1023.0); // Convert average to voltage
  float RS_air = ((5.0 * 10.0) / sensor_volt) - 10.0; // Calculate RS in fresh air
  return RS_air / 4.4;
}
