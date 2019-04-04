#ifndef MOTOR_H_
#define MOTOR_H_

#include"Arduino.h" 

#define MRF PA7
#define MRB PA6
#define MLF PB1
#define MLB PB0
#define FULLSPEED 255

enum {LEFT=1,RIGHT=0};

class Motor
{
  public:
    Motor();
        void Go(int PWML, int PWMR);
        void Stop();
        void TurnTo(int Angle);
};

class StepMotor
{
  public:
      StepMotor(int sPin, int dPin);
      void Go(int dir, int stepNum);
      int getStepNum();
  private:
      int stepPin;
      int dirPin;
      int stepCount;
};
#endif
