#include "gpio.h"
void main(){
  PC->DDR.BIT7=1;
  PC->CR1.BIT7=1;
  PC->ODR.BIT7=1;
  
  PE->DDR.BIT7=1;
  PE->CR1.BIT7=1;
  PE->ODR.BIT7=1;
  
  
  while (1){
    PE_ODR^=(1<<7);
    delay(40000);       // delay 1s.
  }
}

