#ifndef SPI1
#define SPI1

#include <stdint.h>
#include "Gpio.h"

typedef struct{
  uint8_t CR1;
  uint8_t CR2;
  uint8_t ICD;
  uint8_t SR;
  uint8_t DR;
  uint8_t CRCPR;
  uint8_t RXCRCR;
  uint8_t TXCRCR;
}SPI_Type;

#define SPI ((volatile SPI_Type *)0x5200)

void SPI_SlaveInit(void);
void SPI_MasterInit(void);
void SPI_Transmit(unsigned char data);

#endif