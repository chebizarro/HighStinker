/*
 The High Stinker
 The High Stinker gives you the chance to test your fart potency.
 The average human can produce over 100ml of methane per day.
 How much have you got?
*/

class MethaneSensor {

public:

  MethaneSensor(int);

  void init();

  void calibrate();

  float get_value();

private:

  int mInput;

  float mR0;

  float mSlope;

  float mYIntercept;
  
};
