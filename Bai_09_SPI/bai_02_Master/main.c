#include "lib/spi.h"
#include "lib/lcd.h"
#include "lib/clock.h"
#include <stdio.h>
#include <string.h>


void config_GPIO();
void config_Clock();
char *str;
uint8_t len=0;
char x;
char rx;
char press;
uint8_t dangNhan=0;
void delay(){
  uint32_t time=20000;
  while (time--);
}
void nhanDuLieu(){
  if (!dangNhan){
    dangNhan=1;
    free(str);
    len=0;
    str=(char *)malloc(50*sizeof(char));
  }
  rx=SPI1->SR.RXNE;
  
  while (!SPI1->SR.RXNE){}
  
  x=SPI1->DR;
  printf(" c:%c \n",x);
  rx=SPI1->SR.RXNE;
  printf("RNEX: %d.\n",rx);
  str[len]=x;
  str[len+1]=0;
  if (x==0||len>50){
    dangNhan=0;
    printf("ket qua: %s \n",str);
  }
  len++;
}
int main(){
  config_Clock();
  config_GPIO();
  
  
  InitSPIMaster();
  CLK->PCKENR2.BIT0=1;//enabel clock for lcd
  LCD_Init((1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6));
  asm("rim\n");
  char * ss="A";
  while(1){
    
    sendString(ss);
    delay();
  }
  return 0;
}




//#pragma vector=28               //spi
//__interrupt void ReData(){
//  nhanDuLieu();
//  LCD_SEG6(GetHexCodeNum(str[0]));
//}
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


