#ifndef MOTOR_H_
#define MOTOR_H_

#include"Arduino.h" 

#define MLF PA7
#define MLB PA6
#define MRF PB0
#define MRB PB1
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
