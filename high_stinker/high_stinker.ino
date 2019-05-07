/*
 The High Stinker
 The High Stinker gives you the chance to test your fart potency.
 The average human can produce over 100ml of methane per day.
 How much have you got?
*/

int led = 13; // LED pin
int gas_sensor = 0; // Sensor pin
float m = -0.318; // Slope
float b = 1.133; // Y-Intercept
float R0 = 11.820; // Sensor Resistance in fresh air
   
void setup() {
  Serial.begin(9600);

  pinMode(led, OUTPUT); // Set LED as output
  digitalWrite(led, LOW); // Turn LED off
  pinMode(gas_sensor, INPUT); // Set gas sensor as input

  /*
  Serial.println("Calibrating sensor");
  R0 = calibrate(gas_sensor);
  Serial.print("R0 value: ");
  Serial.println(R0);
  */
}

void loop() {
  float sensorValue = analogRead(gas_sensor);
  float sensor_volt = sensorValue * (5.0 / 1023.0); // Convert analog values to voltage
  float RS_gas = ((5.0 * 10.0) / sensor_volt) - 10.0; // Get value of RS in a gas
  float ratio = RS_gas / R0;

  double ppm_log = (log10(ratio) - b) / m; // Get ppm value in linear scale according to the the ratio value
  double ppm = pow(10, ppm_log); // Convert ppm value to log scale
  double percentage = ppm / 10000; // Convert to percentage

  Serial.print("Methane value: ");
  Serial.print(ppm);
  Serial.println(" ppm");

  if (ppm > 2.0) {
    digitalWrite(led, HIGH); //Turn LED on
  } else {
    digitalWrite(led, LOW);
  }
}
