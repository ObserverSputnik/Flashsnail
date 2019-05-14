#include "protocols.h"

uint8_t IICWriteBuffer[5];
uint8_t IICReadBuffer[5];
uint8_t IICmsgBuffer[5];
i2c_msg msgOut;
i2c_msg msgIn;
char CommandBuffer[50];
char charNow = END_OF_SIG;
int jj = 0;
int Speed = 255;
uint8_t FlagReg;



/* 
 * * * * def for commandBuffer * * * *
 * buffer    |     func
 * ----------------------------------
 * buffer[0] |     WSADEQ
 * buffer[1] |     speed  
 * buffer[2] |     flagReg
 * buffer[3] |     stepper_step_num
 * buffer[4] |
 * buffer[5] |
 * buffer[6] |
 * buffer[7] |     
 * ----------------------------------
 * * * * def for FlagReg * * * *
 * 
 * bit    |         flag
 * ----------------------------------
 * bit 0  |                      1
 * bit 1  | read from IMU        2
 * bit 2  | read battery         4
 * bit 3  | stepper_ready        8
 * bit 4  | stepper_dir          16
 * bit 5  |                      32
 * bit 6  |                      64
 * bit 7  |                      128
 */
Motor motor;
StepMotor myStepper(PB15,PB14);

void LinuxUARTInit()
{
  Serial1.begin(115200);
  CommandBuffer[0]=0;
}

uint8_t GetFlags() {return FlagReg;}


void cmdHandler()
{
  int cmd = CommandBuffer[0];
  Speed = CommandBuffer[1];
  int flags = CommandBuffer[2];
  int stepNum = CommandBuffer[3];
  
  /* DC motor commands */
  if(cmd == 'w')        {motor.Go(Speed,Speed);}
  else if(cmd == 'a')   {motor.Go(Speed,Speed*-1);}
  else if(cmd == 'd')   {motor.Go(Speed*-1,Speed);}
  else if(cmd == 's')   {motor.Go(Speed*-1,Speed*-1);}
  else if(cmd == ' ')   {motor.Go(0,0);}
  
  /* stepper commands */
  if((flags>>3)&0x01)   {myStepper.Go((flags>>4)&0x01,stepNum);}
  if((flags>>2)&0x01)   {readBattery();}
}


 void CheckUSART()
{
  int ii = usart_data_available(USART1);
  //Serial1.print(ii);
  int flag = 0;
  int ind;
  while(ii)
  {
    charNow = usart_getc(USART1);
    if(charNow!=END_OF_SIG) 
    {
      CommandBuffer[jj] = charNow;
      //usart_putc(USART1,CommandBuffer[jj]);
      ind = jj;
      jj++;  
    }
    else
    {
      jj=0;
      flag = 1;
    }
    ii--;
  }
  if(flag) {cmdHandler();}
}
