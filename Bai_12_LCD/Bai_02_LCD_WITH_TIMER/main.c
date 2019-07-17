
#include "lib/uart.h"
#include "lib/gpio.h"
#include "lib/clock.h"
#include "lib/Itc.h"
#include "lib/exinterrupt.h"
#include "lib/Lcd.h"
#include "lib/timer.h"
#include "stdio.h"

void InitClock();
void InitGpio();
void InitTimer();
uint16_t count=0; // 0.1s count up
int main(){
  InitClock();
  InitGpio();
  InitTimer();
  LCD_Init((1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6));
  asm("rim\n"); 
  
  while(1){
  }
  
  
  
  while(1){}
  return 0;
}

#pragma vector =25
__interrupt void timer(){
 
  count++;              
  if (count>9999)
    count=0;
  LCD_SEG6(GetHexCodeNum(count%10));
  LCD_SEG5(GetHexCodeNum((count/10)%10));
  LCD_SEG4(GetHexCodeNum((count/100)%10));
  TIM1_SR1 = ~_BIT0;
}
void InitTimer(){
  TIM1_CR1&=~_BIT4;      //0: Counter used as up-counter
  TIM1_CR1|=_BIT0;       //1: Counter enabled
  TIM1_IER|=_BIT0;       //1: Update interrupt enabled/
  TIM1_PSCRH=0x00;      //The prescaler=255
  TIM1_PSCRL=0xff;
  //time clock=62500 HZ
  TIM1_ARRH=0x18;       //auto reload = 6250
  TIM1_ARRL=0x6a;
  //time interval  =0.1s

}
void InitClock(){
  CLK->DIVR.CKM=0x00;           //DIV 0
  CLK->ICKR.HSION=1;            //HSI=16MHZ
  while (!CLK->SCSR){}          //wait
  CLK->PCKENR2.PCKEN23=1;       // clock lcd
  CLK->CRTCR.RTCSEL0=0;         //LSE lsc
  CLK->CRTCR.RTCSEL1=0;
  CLK->CRTCR.RTCSEL2=0;
  CLK->CRTCR.RTCSEL3=1;
  
  CLK->CCOR.CCOSEL=0x5;
  
  CLK->PCKENR2.PCKEN21=1; //enbale clock for tim1
  while(!(CLK->ECKR.LSERDY)){
    printf("%d\n",CLK->ECKR.HSEBYP);
    printf("%d\n",CLK->ECKR.HSEON);
    printf("%d\n",CLK->ECKR.HSERDY);
    printf("%d\n",CLK->ECKR.LSEBYP);
    printf("%d\n",CLK->ECKR.LSEON);
    printf("%d\n",CLK->ECKR.LSERDY);
    printf("\n----------------\n");
  }
  CLK->PCKENR1.PCKEN15=1;       //enable clock uart
}
void InitGpio(){
  
  PC->DDR.BIT7=1;
  PC->CR1.BIT7=1;
  PC->ODR.BIT7=1;
  
  PC->DDR.BIT1=0;
  PC->CR1.BIT1=1;
  PC->CR2.BIT1=1;
  
  EXTI->CR1.P1IS=0x00;
  //ITC->SPR3 |= (3<<2);
 
}
