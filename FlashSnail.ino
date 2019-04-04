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
  //tickInit(tick);
  pinInit();
  Serial1.println("Init done");
  //nvic_irq_enable(NVIC_USART1);
   stepper.Go(0,100);
}


void loop()
{
 
  //Serial1.print("asdw   ");
  //motor1.Go(255,255);
  CheckUSART();
  
}
