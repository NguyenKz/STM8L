#ifndef External
#define External
#include <stdint.h>

typedef struct{
  uint8_t CR1;
  uint8_t CR2;
  uint8_t CR3;
  uint8_t SR1;
  uint8_t SR2;
  uint8_t CONF1;
}External_Type;

#define EXTI ((volatile External_Type *)0x50A0)

#pragma vector = 11
__interrupt void press(void);


#endif