#include"spi.h"
void sendChar(char data){
  while (!SPI1->SR.TXE){}
        SPI1->DR=data;
  
}
void sendString(const char *data){
  for (int i=0;i<strlen(data);i++){
      sendChar(data[i]);
    }
  sendChar(0);
}
void InitSPISlave(void){
  CLK->PCKENR1.BIT4=1;//enabel clock for spi
  
   //MOSI
  PB->DDR.BIT6=0;//input
  PB->CR1.BIT6=1;//pull-up
  //SCK
  PB->DDR.BIT5=0;//input
  PB->CR1.BIT5=1;//pull-up
  //MISO
  PB->DDR.BIT7=1;//input
  PB->CR1.BIT7=1;//pull-up
  
  
  SPI1->CR1.SPE=0;//disable spi to config
  SPI1->CR1.MSTR=0;// master mode
  SPI1->CR1.CPOL=1;//SCK to 0 when idle
  SPI1->CR1.CPHA=1;
  SPI1->CR2.RXONLY=0;   //full duplex
  SPI1->CR2.BDM=0;//2-line unidirectional data mode selected
  SPI1->CR2.SSI=0;      //MASTER MODE
  SPI1->CR2.SSM=1;      //1: Software slave management enabled
  
  SPI1->ICR.RXIE=1;     //interrupt rx
  SPI1->CR1.SPE=1;//enabel spi
  
}

void InitSPIMaster(void){

  CLK->PCKENR1.BIT4=1;//enabel clock for spi
   //MOSI
  PB->DDR.BIT6=1;//output
  PB->CR1.BIT6=1;//push-pull
  //SCK
  PB->DDR.BIT5=1;//output
  PB->CR1.BIT5=1;//push-pull
  //MISO
  PB->DDR.BIT7=0;//input
  PB->CR1.BIT7=1;//pull-up
  
  
  SPI1->CR1.SPE=0;//disable spi to config
  SPI1->CR1.MSTR=1;// master mode
  SPI1->CR1.CPOL=0;//SCK to 0 when idle
  SPI1->CR1.CPHA=0;
  SPI1->CR2.RXONLY=0;   //full duplex
  SPI1->CR2.BDM=0;//2-line unidirectional data mode selected
  SPI1->CR2.SSI=1;      //MASTER MODE
  SPI1->CR2.SSM=1;      //1: Software slave management enabled
  
  SPI1->ICR.RXIE=1;     //interrupt rx
  SPI1->CR1.SPE=1;//enabel spi
  
}