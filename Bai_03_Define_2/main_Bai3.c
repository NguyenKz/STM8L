#include<stdint.h>
//cach 2
typedef struct PORT{
  uint8_t P0: 1;
  uint8_t P1: 1;
  uint8_t P2: 1;
  uint8_t P3: 1;
  uint8_t P4: 1;
  uint8_t P5: 1;
  uint8_t P6: 1;
  uint8_t P7: 1;
}PORT_TYPE;
typedef struct GPIO{
 PORT_TYPE ODR;
 PORT_TYPE IDR;
 PORT_TYPE DDR;
 PORT_TYPE CR1;
 PORT_TYPE CR2;
}GPIO_TYPE;
#define PC ((GPIO_TYPE *)0x500A)
#define PE ((GPIO_TYPE *)0x5014)
void delay(uint32_t time);
void configLedGreen();
void configLedBlue();
void configUserButton();
void main(){
  char BlinkLed1=0;
  uint32_t time=40000;// thoi gian check led lien tuc
  configLedGreen();
  configLedBlue();
  configUserButton();
  while (1){
    if (!PC->IDR.P1){
      while (!PC->IDR.P1){// wait end press
      }
      BlinkLed1=!BlinkLed1;

    }
    if (!time){// luon checck phim
      time=40000;
      if (BlinkLed1){
        PC->ODR.P7=0;
        PE->ODR.P7=!PE->ODR.P7;
      }
      else{
          PE->ODR.P7=0;
          PC->ODR.P7=!PC->ODR.P7; 
      }    
    }
    time--;
  }
  
}
void configUserButton(){
  PC->CR1.P1=1; //SET BUTTON PULL UP;
}
void configLedBlue(){
  PC->DDR.P7=1; //SET LED     PUSH-PULL FASTMODE 
  PC->CR1.P7=1;
  PC->CR2.P7=1;
  PC->ODR.P7=1;
}
void configLedGreen(){
  PE->DDR.P7=1; //SET LED     PUSH-PULL FASTMODE 
  PE->CR1.P7=1;
  PE->CR2.P7=1;
  PE->ODR.P7=1;
}
