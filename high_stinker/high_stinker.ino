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
#include "ring_meter.h"

#include <Elegoo_GFX.h>    // Core graphics library
#include <Elegoo_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

/******************* UI details */
#define BUTTON_X 180
#define BUTTON_Y 40
#define BUTTON_W 60
#define BUTTON_H 30
#define BUTTON_SPACING_X 20
#define BUTTON_SPACING_Y 20
#define BUTTON_TEXTSIZE 2

#define ILI9341_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9341_BLUE        0x001F      /*   0,   0, 255 */

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

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

Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Elegoo_GFX_Button buttons[4];
char buttonlabels[15][5] = {"Send", "Clr", "End", "1", "2", "3", "4", "5", "6", "7", "8", "9", "*", "0", "#" };

RingMeter ch4_meter(0, 100, 20, 20, 52, "CH4", 4);
RingMeter h_meter(0, 100, 20, 130, 52, "H", 4);


MethaneSensor methane_sensor(METHANE_SENSOR);
HydrogenSensor hydro_sensor(HYDROGEN_SENSOR);
RotatingLight rotating_light(ROTATING_LIGHT);
Pumps pumps(PUMPS);
   
void setup() {
  
  tft.reset();

  uint16_t identifier = tft.readID();
  if(identifier==0x0101) {     
      identifier=0x9341;
  }else {
    identifier=0x9341;
  }
  
  tft.begin(identifier);
  tft.setRotation(3);
  tft.fillScreen(BLACK);

  for (uint8_t row=0; row<2; row++) {
    for (uint8_t col=0; col<2; col++) {
      buttons[col + row*2].initButton(&tft, BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), 
                 BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
                  BUTTON_W, BUTTON_H, ILI9341_WHITE, ILI9341_BLUE, ILI9341_WHITE,
                  buttonlabels[col + row*2], BUTTON_TEXTSIZE); 
      buttons[col + row*2].drawButton();
    }
  }

  // Set up sensors
  //methane_sensor.init();

  // Set up pumps and LEDs
  //pumps.init();
  //rotating_light.init();
  //FastLED.addLeds<WS2811, LED01>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  //FastLED.addLeds<WS2811, LED02>(leds, NUM_LEDS);

}

void loop() {

  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  //pinMode(XP, OUTPUT);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  ch4_meter.draw(tft, 2000);
  h_meter.draw(tft, 200);

  //FastLED.show(); 

  
  //delay(300);

  // read sensors
  //float methane_ppm = methane_sensor.get_value();
  //float hydrogen_ppm = hydro_sensor.get_value();

}
