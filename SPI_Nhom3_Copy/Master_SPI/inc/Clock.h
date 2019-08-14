#ifndef CLOCK
#define CLOCK

#include <stdint.h>

typedef struct{
  uint8_t DIVR;
  uint8_t CRTCR;
  uint8_t ICKR;
  uint8_t PCKENR1;
  uint8_t PCKENR2;
  uint8_t CCOR;
  uint8_t ECKR;
  uint8_t SCSR;
  uint8_t SWR;
  uint8_t SWCR;
  uint8_t CSSR;
  uint8_t CBEEPR;
  uint8_t HSICALR;
  uint8_t HSITRIMR;
  uint8_t HSIUNLCKR;
  uint8_t REGCSR;
} CLK_Type;

#define CLK ((volatile CLK_Type *)0x50C0)

#endif