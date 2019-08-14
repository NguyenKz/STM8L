#include "SPI.h"

void SPI_SlaveInit(void){
  /*Configure the SPI in slave mode */
  SPI->CR1 |= (1<<0) | (1<<1); //CPOL: the second clock transistion + SCK=1 
  SPI->CR1 &= ~(1<<7); //MSB First
  
  SPI->CR2 |= (1<<1); //SSM enable
  SPI->CR2 &= ~(1<<0); //Clear SSO - Slave Mode.
  
  SPI->CR1 &= ~(1<<2); //Slave [MSTR]
  SPI->CR1 |= (1<<6); // SPI Enable
  
  /*------------------------------------------- */
  /*Configure Pins for Slave mode */
  PB->DDR &= ~(1<<6); //MOSI Port B6
  PB->CR1 |= (1<<6);//pull-up
  
  PB->DDR |= (1<<7); //MISO port B7
  PB->CR1 |= (1<<7); // push-pull
  
  PB->DDR &= ~(1<<5);//SCK input
  PB->CR1 |= (1<<5);
  
  PB->DDR &= ~(1<<4);//NSS
  PB->CR1 |= (1<<4);
}
void SPI_MasterInit(void){
  /*Configure the SPI in master mode */
  SPI->CR1 |= (1<<0) | (1<<1); //CPOL: the second clock transistion + SCK=1 
  SPI->CR1 &= ~(1<<7); //MSB First
  SPI->CR1 |= (1<<4); //BR/8
  
  SPI->CR2 |= (1<<1); //SSM enable
  SPI->CR2 |= (1<<0); //Master mode
  
  SPI->CR1 |= (1<<2); //Master [MSTR]
  SPI->CR1 |= (1<<6); // SPI Enable
  /*------------------------------------------- */
  /*Configure Pins for Master mode */
  PB->DDR |= (1<<6); //MOSI Port B6
  PB->CR1 |= (1<<6);//pull-up
  
  PB->DDR &= ~(1<<7); //MISO port B7
  PB->CR1 |= (1<<7); // push-pull
  
  PB->DDR |= (1<<5);//SCK input
  PB->CR1 |= (1<<5);
  
  PB->DDR |= (1<<4);//NSS
  PB->CR1 |= (1<<4);  
}
void SPI_Transmit(unsigned char data){
  SPI->DR = data;
 // while(!(SPI->SR & (1<<1)));
}

unsigned char SPI_Receive (){
  while (SPI->SR & 0x80);
  return SPI->DR;
}

void SPI_Slave_Transmit(unsigned char data){
  //while (!(SPI->SR & 0x01)); // doi xem master da truyen du lieu chua
  SPI_Transmit(data);
  PC->ODR |=(1<<7);
}