/*
  Den xanh la se bat len khi clk dc config
  sau do den xanh bien se bat len khi truyen du lieu thanh cong
*/
#include "stm8.h"

void Clock_Init();
void GPIO_Init();
void interrupt_Init();
void delay(unsigned int);
volatile uint8_t recvData = 0x00;

int main( void )
{
  Clock_Init();
  GPIO_Init();
  SPI_MasterInit();
  interrupt_Init();
  asm("RIM\n");
  while (1){
    SPI_Receive();
    delay(60000);
    PE->ODR |= (1<<7);
   // PC->ODR &= ~(1<<7);
  }

}

void Clock_Init(){
  CLK->DIVR =0x03; // 2 MHz
  CLK->ICKR |= (1<<0);
  while (CLK->SCSR != 0x01);
  PE->ODR |= (1<<7);
  CLK->PCKENR1 |= (1<<4);
}
void GPIO_Init(){
  PC->DDR |= (1<<7);
  PC->CR1 |= (1<<7);
  PE->DDR |= (1<<7);
  PE->CR1 |= (1<<7);
  
  PC->DDR &= ~(1<<1);
  PC->CR1 |= (1<<1);
  PC->CR2 |= (1<<1);// External interrupt enabled
}

void interrupt_Init(){
  EXTI->CR1 |=(1<<3);
}
#pragma vector = 28
__interrupt void SPI_Interrupt(void){
  PC->ODR |= (1<<7);
  recvData = SPI->DR;
}

#pragma vector = 11
__interrupt void button_interrrupt(){
  
  SPI_Transmit('a');
  PE->ODR &= ~(1<<7);
  EXTI->SR1 |=0x02; // bit 1 cleared 
}
void delay(unsigned int n){
  while(n--);
}