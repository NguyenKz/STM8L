#ifndef ITC1
#define ITC1
#include <stdint.h>

typedef struct{
  uint8_t SPR1;
  uint8_t SPR2;
  uint8_t SPR3;
  uint8_t SPR4;
  uint8_t SPR5;
  uint8_t SPR6;
  uint8_t SPR7;
  uint8_t SPR8;
}ITC_Type;

#define ITC ((volatile ITC_Type *)0x7F70)

#endif