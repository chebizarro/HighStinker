#include <Arduino.h>
#include "rotating_light.h"


RotatingLight::RotatingLight(int id) :
mOutput(id)
{ }

void RotatingLight::init() {
    pinMode(mOutput, OUTPUT);
}

void RotatingLight::changeState(RotatingLightState state) {
  if (state == RotatingLightState::on) {
    digitalWrite(mOutput, 0);
  } else {
    digitalWrite(mOutput, 1);
  }
}
