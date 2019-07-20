#include "lib/CLOCK.h"




void InitI2C();
void InitClock();
int main(){
  InitClock();
  return 0;
}
void InitClock(){
  while (CLK->CLK_SWCR.CLK_SWBSY);      //wait when clock switch on going
  CLK->CLK_SWCR.CLK_SWEN=1;     //enable switch clock
  CLK->CLK_SWR=0x01;            //select HSI
  while (CLK->CLK_SCSR!=0x01);  //wait for HSI selected
  
  
  
  
  CLK->CLK_DIVR.CLK_CKM=0x0;    //000: System clock source/1
  
  CLK->CLK_PCKENR2.CLK_PCKEN23=1;       //enable clock for lcd
  CLK->CLK_PCKENR1.CLK_PCKEN13=1;       //enable clock for i2c
}