#include "lib/CLOCK.h"
#include "lib/I2C.h"
#include "lib/GPIO.h"


#define Slave_Adrress           0x50

void InitClock();
void InitGpio();
void Delay(){
  uint32_t time=40000;
  while(time--);
}
int main(){
  InitClock();
  InitI2C_Master();
  InitGpio();
  asm("rim\n");
  
  while(1){
    I2C1_Start();
    I2C1_Select_Slave(Slave_Adrress,1);
    I2C1_Write('A');
    I2C1_Stop();
    Delay();
  
  }
  
  return 0;
}



void InitGpio(){
  //SDA
  GPIO_PC->DDR.GPIO_PORT0=1;            //OUITPUT            
  GPIO_PC->CR1.GPIO_PORT0=1;            //PUSH-PULL
  GPIO_PC->CR2.GPIO_PORT0=1;            //

  //SCL
  GPIO_PC->DDR.GPIO_PORT1=1;            //OUITPUT            
  GPIO_PC->CR1.GPIO_PORT1=1;            //PUSH-PULL
  GPIO_PC->CR2.GPIO_PORT1=1;            //
  
  
  GPIO_PC->DDR.GPIO_PORT7=1;
  GPIO_PC->CR1.GPIO_PORT7=1;
  GPIO_PC->CR2.GPIO_PORT7=1;
  GPIO_PC->ODR.GPIO_PORT7=1;
}


void InitClock(){
  while (CLK->CLK_SWCR.CLK_SWBSY);      //wait when clock switch on going
  CLK->CLK_SWCR.CLK_SWEN=1;             //enable switch clock
  CLK->CLK_SWR=0x01;                    //select HSI
  while (CLK->CLK_SCSR!=0x01);          //wait for HSI selected
  CLK->CLK_DIVR.CLK_CKM=0x0;            //000: System clock source/1  
  CLK->CLK_PCKENR2.CLK_PCKEN23=1;       //enable clock for lcd
  CLK->CLK_PCKENR1.CLK_PCKEN13=1;       //enable clock for i2c
}