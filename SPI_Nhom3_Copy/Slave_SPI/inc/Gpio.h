#ifndef GPIO
#define GPIO

#include <stdint.h>

typedef struct{
  uint8_t ODR;
  uint8_t IDR;
  uint8_t DDR;
  uint8_t CR1;
  uint8_t CR2;
}GPIO_Type;

#define PA ((volatile GPIO_Type *)0x5000)
#define PB ((volatile GPIO_Type *)0x5005)
#define PC ((volatile GPIO_Type *)0x500A)
#define PD ((volatile GPIO_Type *)0x500F)
#define PE ((volatile GPIO_Type *)0x5014)
#define PF ((volatile GPIO_Type *)0x5019)

#endif