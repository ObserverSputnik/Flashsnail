#include "util.h"

int flag = 1;
int count=0;
int thisFrame = 0;
int lastFrame = 0;
void tickInit(HardwareTimer timer)
{
    timer.pause();
    timer.setPrescaleFactor(10);
    timer.setChannel1Mode(TIMER_OUTPUT_COMPARE);
    timer.setOverflow(BIT_16*5000/9102);
    timer.setCompare(TIMER_GENERAL,700);  // Interrupt 1 count after each update
    timer.attachCompare1Interrupt(tickHandler);
    timer.refresh();
    timer.resume();
}

int getTime()
{ 
  int period;
  thisFrame = micros();
  period = thisFrame-lastFrame;
  lastFrame = thisFrame;
  return period;
}

void tickHandler()
{
  count++;
  if(count > 100)
  {flag = !flag;
  count = 0;
  }
  digitalWrite(PC13,flag);
  CheckUSART();
}

int readBattery()
{
  int Batt = analogRead(batteryPin);
  uint8_t Battery = int(256*float(Batt)/float(0xfff));
  uint8_t dic = int(floor(Battery));
  uint8_t men = int((int(Battery)-dic)*10);
  usart_putc(USART1,Battery);
  //Serial1.print(men);
  return Battery;
}

void pinInit()
{
  pinMode(TX_LED,OUTPUT);
  pinMode(RX_LED,OUTPUT);
  pinMode(PC13,OUTPUT);
  pinMode(batteryPin,INPUT_ANALOG);
}
