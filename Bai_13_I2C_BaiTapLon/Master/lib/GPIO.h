#ifndef GPIO
#pragma once

#include<stdint.h>

typedef struct{
  uint8_t GPIO_PORT0:1;
  uint8_t GPIO_PORT1:1;
  uint8_t GPIO_PORT2:1;
  uint8_t GPIO_PORT3:1;
  uint8_t GPIO_PORT4:1;
  uint8_t GPIO_PORT5:1;
  uint8_t GPIO_PORT6:1;
  uint8_t GPIO_PORT7:1;
}BYTE_TYPE;

typedef struct{
  BYTE_TYPE ODR;
  BYTE_TYPE IDR;
  BYTE_TYPE DDR;
  BYTE_TYPE CR1;
  BYTE_TYPE CR2;
}PORT_TYPE;
#define GPIO_PA ((volatile PORT_TYPE *)0x5000)

#define GPIO_PB ((volatile PORT_TYPE *)0x5005)

#define GPIO_PC ((volatile PORT_TYPE *)0x500A)

#define GPIO_PD ((volatile PORT_TYPE *)0x500F)

#define GPIO_PE ((volatile PORT_TYPE *)0x5014)

#define GPIO_PF ((volatile PORT_TYPE *)0x5019)
#endif