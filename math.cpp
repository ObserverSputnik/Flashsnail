#include "math.h"

float Kp = 1;
float Ki = 1;
float Kd = 1;

int PID(int var, int lastVar, int Dlt)
{
  
}

int grad(int var, int LastVar, int Dlt)  {return (LastVar-var)/Dlt;}
