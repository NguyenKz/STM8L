
#include "lib/uart.h"
#include "lib/gpio.h"
#include "lib/clock.h"
#include "lib/Itc.h"
#include "lib/exinterrupt.h"
#include "lib/Lcd.h"
#include "stdio.h"

void InitClock();
void InitGpio();
void delay(){
  uint32_t time=20000;
  while (time--);
}
uint16_t count=0;
int main(){
  InitClock();
  InitGpio();
  LCD_Init((1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6));
  asm("rim\n"); 
  LCD_SEG6(GetHexCodeNum('B'));
  while(1){
  }
  
  
  
  while(1){}
  return 0;
}

#pragma vector=11
__interrupt void Pressbutton(){
  while (!PC->IDR.BIT1){}
  count++;
  if (count>999){
    count=0;
  }
  
  LCD_SEG6(GetHexCodeNum(count%10));
  LCD_SEG5(GetHexCodeNum((count/10)%10));
  LCD_SEG4(GetHexCodeNum((count/100)%10));
  EXTI->SR1.P1F=1;

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
