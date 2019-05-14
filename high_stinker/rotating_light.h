enum class RotatingLightState { on, off };

class RotatingLight {

public:

  RotatingLight(int);

  void init();

  void changeState(RotatingLightState);

private:

  int mOutput;
  
};
