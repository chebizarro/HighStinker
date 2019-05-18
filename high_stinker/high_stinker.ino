/*
 The High Stinker
 The High Stinker gives you the chance to test your fart potency.
 The average human can produce over 100ml of methane per day.
 How much have you got?
*/
#include <FastLED.h>
#include "methane_sensor.h"
#include "hydrogen_sensor.h"
#include "rotating_light.h"
#include "pumps.h"

#define BAUD_RATE       9600

#define PUMPS           3
#define ROTATING_LIGHT  4
#define LED01           5
#define LED02           6
#define METHANE_SENSOR  8
#define HYDROGEN_SENSOR 9
#define RESET_BUTTON    13

#define METHANE_HIGH    2000
#define METHANE_MED     2000
#define METHANE_LOW     2000

#define HYDROGEN_HIGH   2000
#define HYDROGEN_MED    2000
#define HYDROGEN_LOW    2000

#define NUM_LEDS        36

CRGB leds[NUM_LEDS];

MethaneSensor methane_sensor(METHANE_SENSOR);
HydrogenSensor hydro_sensor(HYDROGEN_SENSOR);
RotatingLight rotating_light(ROTATING_LIGHT);
Pumps pumps(PUMPS);
   
void setup() {
  //Serial.begin(BAUD_RATE);

  // Set up sensors
  methane_sensor.init();

  // Set up pumps and LEDs
  pumps.init();
  rotating_light.init();
  FastLED.addLeds<WS2811, LED01>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, LED02>(leds, NUM_LEDS);

}

void loop() {
  leds[1] = CRGB::Red; 
  //FastLED.show(); 

  digitalWrite(ROTATING_LIGHT, LOW);

  delay(300);

  // read sensors
  float methane_ppm = methane_sensor.get_value();
  float hydrogen_ppm = hydro_sensor.get_value();

}
