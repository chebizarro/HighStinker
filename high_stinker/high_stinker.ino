/*
 The High Stinker
 The High Stinker gives you the chance to test your fart potency.
 The average human can produce over 100ml of methane per day.
*/

int led = 10; // LED pin
int gas_sensor = A0; // Sensor pin
float m = -0.318; // Slope
float b = 1.133; // Y-Intercept
float R0 = 11.820; // Sensor Resistance in fresh air

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // Set LED as output
  digitalWrite(led, LOW); // Turn LED off
  pinMode(gas_sensor, INPUT); // Set gas sensor as input
  R0 = calibrate();
}

void loop() {
  float sensor_volt;
  float RS_gas;
  float ratio;
  float sensorValue = analogRead(gas_sensor);
  sensor_volt = sensorValue * (5.0 / 1023.0); // Convert analog values to voltage
  RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; // Get value of RS in a gas
  ratio = RS_gas / R0;

  double ppm_log = (log10(ratio) - b) / m; // Get ppm value in linear scale according to the the ratio value
  double ppm = pow(10, ppm_log); // Convert ppm value to log scale
  double percentage = ppm / 10000; // Convert to percentage

  if (ppm > 2000) {
    digitalWrite(led, HIGH); //Turn LED on
  } else {
    digitalWrite(led, LOW);
  }
}
