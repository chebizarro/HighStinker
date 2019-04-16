
/*
 The High Stinker
 The High Stinker gives you the chance to test your fart potency.
 The average human can produce over 100ml of methane per day.
*/

float calibrate() {
  float sensor_volt;
  float RS_air; 
  float result;
  float sensorValue;

  for (int x = 0 ; x < 500 ; x++) {
    sensorValue = sensorValue + analogRead(A0); // Add analog values of sensor 500 times
  }
  
  sensorValue = sensorValue / 500.0; // Take average of readings
  sensor_volt = sensorValue * (5.0 / 1023.0); // Convert average to voltage
  RS_air = ((5.0 * 10.0) / sensor_volt) - 10.0; // Calculate RS in fresh air
  result = RS_air / 4.4; // Calculate results

  return result;
}
