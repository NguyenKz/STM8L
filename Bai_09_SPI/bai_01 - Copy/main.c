#include "lib/spi.h"
#include "lib/lcd.h"
#include "lib/clock.h"
#include <stdio.h>
#include <string.h>

#define Time_Reload 20000
void config_GPIO();
void config_Clock();
int main(){
  config_Clock();
  config_GPIO();
  uint32_t time;
  while(1){
    
    if (!PC->IDR.BIT1){
      PE->ODR.BIT7^=1;
    }
    
    
    if (time){
      time=Time_Reload;
      PC->ODR.BIT7^=1;
    }
    time++;

  }
  return 0;
}




#pragma vector=28               //spi
__interrupt void ReData(){
  nhanDuLieu();
  LCD_SEG6(GetHexCodeNum(str[0]));
}
void config_Clock(){

  //CLK->DIVR = 0x00;
  CLK->PCKENR2.BIT3=1;
  CLK->CRTCR.BIT7=0; //RTCDIV = 0
  CLK->CRTCR.BIT6=0; //RTCDIV = 0
  CLK->CRTCR.BIT5=0; //RTCDIV = 0
  CLK->CRTCR.BIT4=1; // RTC-LSE
  while(!(CLK->ECKR.BIT3));
}
void config_GPIO(){
  PC->DDR.BIT1=0;
  PC->CR1.BIT1=1;
  PC->CR2.BIT1=1;
  
  PC->DDR.BIT7=1;
  PC->CR1.BIT7=1;
  PC->ODR.BIT7=1;
  
  PE->DDR.BIT7=1;
  PE->CR1.BIT7=1;
  PE->ODR.BIT7=1;
}


