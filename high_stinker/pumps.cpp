#include <Arduino.h>
#include "pumps.h"

Pumps::Pumps(int output):
mOutput(output)
{ }

void Pumps::init() {
  
}

void Pumps::changeState(PumpsState state) {
  if (state == PumpsState::on) {
    digitalWrite(mOutput, HIGH);
  } else {
    digitalWrite(mOutput, LOW);
  }
}
