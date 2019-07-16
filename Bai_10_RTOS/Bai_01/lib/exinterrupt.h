#ifndef External
#define External
#include"gpio.h"
//Bits 7:6 P3IS[1:0]: Portx bit 3 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of bit 3 of Port A, B, C and/or D external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
//Bits 5:4 P2IS[1:0]: Portx bit 2 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of bit 2 of Port A, B, C and/or D external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
//Bits 3:2 P1IS[1:0]: Portx bit 1 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of bit 1 of Port A, B, C and/or D external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
//Bits 1:0 P0IS[1:0]: Portx bit 0 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of bit 0 of Port A, B, C and/or D external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
typedef struct{

  uint8_t P0IS:2;       //0,1
  uint8_t P1IS:2;       //2,3
  uint8_t P2IS:2;       //4,5
  uint8_t P3IS:2;       //6,7
  
}external_CR1;
//Bits 7:6 P7IS[1:0]: Portx bit 7 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of the bit 7 of Port B and/or D external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
//Bits 5:4 P6IS[1:0]: Portx bit 6 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of the bit 6 of Port A, B, C and/or D external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
//Bits 3:2 P5IS[1:0]: Portx bit 5 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of the bit 5 of Port A, B, C and/or D external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
//Bits 1:0 P4IS[1:0]: Portx bit 4 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of the bit 4 of Port A, B, C and/or D external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
typedef struct{

  uint8_t P4IS:2;       //0,1
  uint8_t P5IS:2;       //2,3
  uint8_t P6IS:2;       //4,5
  uint8_t P7IS:2;       //6,7
  
}external_CR2;

//Bits 7:4 Reserved
//Bits 3:2 PDIS[1:0]: Port D external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of the Port D external interrupts, when EXTID for Port D[3:0] and/or Port D[7:4]
//is enabled.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge
//Bits 1:0 PBIS[1:0]: Port B external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of the Port B external interrupts, when EXTIB for Port B[3:0] and/or PortB[7:4]
//is enabled.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge

typedef struct{

  uint8_t PBIS:2;       //0,1
  uint8_t PDIS:2;       //2,3
  uint8_t Reserved:4;       //4,5,6,7
  
}external_CR3;
//Bits 7:0 PxF: Port A/B/C/D bit x external interrupt flag
//These bits are set by hardware when an interrupt event occurs on the corresponding pin.They are
//cleared by writing a ‘1’ by software.
//0: No interrupt
//1: External interrupt pending

typedef struct{

  uint8_t P0F:1;        //0
  uint8_t P1F:1;        //1
  uint8_t P2F:1;        //2
  uint8_t P3F:1;        //3
  uint8_t P4F:1;        //4
  uint8_t P5F:1;        //5
  uint8_t P6F:1;        //6
  uint8_t P7F:1;        //7
}external_SR1;
//Bits 7:2 Reserved
//Bit 1 PDF: Port D external interrupt flag
//This bit is set by hardware when an interrupt event occurs on the corresponding pin. It is cleared by
//writing a ‘1’ by software.
//0: No interrupt
//1: External interrupt pending
//Bit 0 PBF: Port B external interrupt flag
//This bit is set by hardware when an interrupt event occurs on the corresponding pin.It is cleared by
//writing a ‘1’ by software.
//0: No interrupt
//1: External interrupt pending


typedef struct{

  uint8_t PBF:1;                //0
  uint8_t PDF:1;                //1
  uint8_t Reserved:6;           //2,3,4,5,6,7
 
}external_SR2;
//Bits 7:4 Reserved
//Bit 3 PDHIS: Port D[7:4] external interrupt select
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). It
//selects pins PD[7:4] for EXTID interrupt.
//0: PD[7:4] are used for EXTI7-EXTI4 interrupt generation
//1: PD[7:4] are used for EXTID interrupt generation
//Bit 2 PDLIS: Port D[3:0] external interrupt select
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). It
//selects pins PD[3:0] for EXTID interrupt.
//0: PD[3:0] are used for EXTI3-EXTI0 interrupt generation
//1: PD[3:0] are used for EXTID interrupt generation
//Bit 1 PBHIS: Port B[7:4] external interrupt select
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). It
//selects pins PB[7:4] for EXTIB interrupt.
//0: PB[7:4] are used for EXTI7-EXTI4 interrupt generation
//1: PB[7:4] are used for EXTIB interrupt generation
//Bit 0 PBLIS: Port B[3:0] external interrupt select
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). It
//selects pins PB[3:0] for EXTIB interrupt.
//0: PB[3:0] are used for EXTI3-EXTI0 interrupt generation
//1: PB[3:0] are used for EXTIB interrupt generation
typedef struct{

  uint8_t PBLIS:1;                //0
  uint8_t PBHIS:1;                //1
  uint8_t PDLIS:1;                //2
  uint8_t PDHIS:1;                //3
  uint8_t Reserved:4;           //4,5,6,7
 
}external_CONF;

typedef struct{
  external_CR1 CR1;
  external_CR2 CR2;
  external_CR3 CR3;
  external_SR1 SR1;
  external_SR2 SR2;
  external_CONF CONF1;
}External_Type;

#define EXTI ((volatile External_Type *)0x50A0)


#endif