
#include "lib/uart.h"
#include "lib/gpio.h"
#include "lib/clock.h"


void InitClock();
void InitGpio();
void InitUart();
int main(){
  InitClock();
  InitGpio();
  InitUart();
  
  
  
  while(1){}
  return 0;
}
void InitClock(){

}
void InitGpio();
void InitUart();