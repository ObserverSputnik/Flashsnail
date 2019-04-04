#include "motor.h"


Motor::Motor()
{
  pinMode(MLF,PWM);
  pinMode(MRF,PWM);
  pinMode(MLB,PWM);
  pinMode(MRB,PWM);
  pwmWrite(MLF,0x00);
  pwmWrite(MRF,0x00);
  pwmWrite(MLB,0x00);
  pwmWrite(MRB,0x00);
}


void Motor::Go(int PWML, int PWMR)
{
    if(PWML<0)
    {analogWrite(MLB,abs(PWML));analogWrite(MLF,0);}
    else
    {analogWrite(MLF,PWML);analogWrite(MLB,0);}
    if(PWMR<0)
    {analogWrite(MRB,abs(PWMR));analogWrite(MRF,0);}
    else
    {analogWrite(MRF,PWMR);analogWrite(MRB,0);}
}

void Motor::Stop()
{
  pwmWrite(MLF,0x00);
  pwmWrite(MRF,0x00);
  pwmWrite(MLB,0x00);
  pwmWrite(MRB,0x00);
}

void Motor::TurnTo(int Angle)
{
  
}

StepMotor::StepMotor(int sPin, int dPin)
{
  pinMode(sPin,OUTPUT);
  pinMode(dPin,OUTPUT);
  stepPin = sPin;
  dirPin = dPin;
  stepCount = 0;
}


void StepMotor::Go(int dir, int stepNum)
/* var: dir = 1 for up 0 for down*/
{
  digitalWrite(dirPin,dir);
  for(int ii = stepNum; ii>0; ii--)
  {
    digitalWrite(stepPin,1);
    delay(1);
    digitalWrite(stepPin,0);
    delay(1);
  }
  if(dir){stepCount+=stepNum;}
  else{stepCount-=stepNum;}
}

int StepMotor::getStepNum()
{return stepCount;}
