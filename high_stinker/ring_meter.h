#include <Elegoo_GFX.h>    // Core graphics library

class RingMeter {

public:
  RingMeter(int, int, int, int, int, char*, byte);

  void draw(Elegoo_GFX&, int);

private:

  int vMin;
  int vMax;
  int mX;
  int mY;
  int radius;
  char *units;
  byte scheme;

  unsigned int rainbow(byte value);
  
};
