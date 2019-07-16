#include<stdint.h>
//cach 2

typedef struct GPIO{//Khai Bao truct theo thu tu cua reference stm8l
  uint8_t ODR;
  uint8_t IDR;
  uint8_t DDR;
  uint8_t CR1;
  uint8_t CR2;
}GPIO_TYPE;
#define PC ((GPIO_TYPE *)0x500A)// dia chi port c
#define PE ((GPIO_TYPE *)0x5014)// dia chi port e
void delay(uint32_t time);
void configLedGreen();
void configUserButton();
void main(){
  configLedGreen();
  configUserButton();
  while (1){
    if (!(PC->IDR&0x02)){
      while (!(PC->IDR&0x02)){}
      PE->ODR^=(1<<7);
      delay(40000);
    }
  }
}
void configUserButton(){
  PC->CR1 |=0x02; //SET BUTTON PULL UP;
}
void configLedGreen(){
  PE->DDR |=0x80; //SET LED     PUSH-PULL FASTMODE 
  PE->CR1 |=0x80; //config register 1
  PE->CR2 |=0x80; //config register 2
  PE->ODR |=0x80; //turn off led green
}
void delay(uint32_t time){
  while (time){
    time--;
  }
}