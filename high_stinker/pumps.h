enum class PumpsState { on, off };

class Pumps {

public:
  Pumps(int);

  void init();

  void changeState(PumpsState);

private:
  int mOutput;
  
};
