#include "motor.h"
#include "util.h"
#include "protocols.h"


int ii = 255;
StepMotor stepper(PB15,PB14);
//HardwareTimer tick(2);
Motor motor1;
void setup()
{
  Serial1.begin(115200);
  pinInit();
  Serial1.println("Init done");
  /* --TODO: readBattery and FIR and BUFF --*/
}


void loop()
{
  CheckUSART();
}
