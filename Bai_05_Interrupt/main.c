/* Signed integer types  */

typedef   signed char     int8_t;
typedef   signed short    int16_t;
typedef   signed long     int32_t;

/* Unsigned integer types  */
typedef unsigned char     uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned long     uint32_t;
#define PC_ODR          *(uint8_t *)    0x500A
#define PC_IDR          *(uint8_t *)    0x500B
#define PC_DDR          *(uint8_t *)    0x500C
#define PC_CR1          *(uint8_t *)    0x500D
#define PC_CR2          *(uint8_t *)    0x500E


#define PE_ODR          *(uint8_t *)    0x5014
#define PE_IDR          *(uint8_t *)    0x5015
#define PE_DDR          *(uint8_t *)    0x5016
#define PE_CR1          *(uint8_t *)    0x5017
#define PE_CR2          *(uint8_t *)    0x5018


#define EXTI_CR1        *(uint8_t *)    0x50A0
#define EXTI_SR1        *(uint8_t *)    0x50A3
#define EXTI_CONF1      *(uint8_t *)    0x50A5

#define SBit(VAR, Place)         ((VAR) |= ((1<< Place)))
#define CBit(VAR, Place)         ((VAR) &=~ ((1<<Place)))

#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80







//EXTI_CR1
//EXTI_SR1
//ITC_SPR3


//EXTI_CONF1


//EXTI_CR1 kieu tac donglen chan de sinh ra ngat
//P3IS[1:0] P2IS[1:0] P1IS[1:0] P0IS[1:0]
//P1IS[1:0]: Portx bit 1 external interrupt sensitivity bits
//These bits can only be written when I1 and I0 in the CCR register are both set to 1 (level 3). They
//define the sensitivity of bit 1 of Port A, B, C, D and/or E external interrupts.
//00: Falling edge and low level
//01: Rising edge only
//10: Falling edge only
//11: Rising and falling edge




//EXTI_SR1 Trang thai cua ngat
//P7F P6F P5F P4F P3F P2F P1F P0F
//Bits 7:0 PxF: Port A/B/C/D/E/F bit x external interrupt flag
//These bits are set by hardware when an interrupt event occurs on the corresponding pin.They are
//cleared by writing a ‘1’ by software.
//0: No interrupt
//1: External interrupt pending
uint8_t BatDauChop=0;
#pragma vector=11
__interrupt void NhanPhim(){
  while(!(PC_IDR&BIT1)){}
  BatDauChop=1;
  EXTI_SR1    |=BIT1;
}

void Delay(uint32_t time){
  while (time){
    time--;
  }
}
int main(){
  uint8_t count=0;
  PC_DDR |= BIT7;
  PC_ODR &=~BIT7;
  PC_CR1 |= BIT7;
  PC_CR2 &=~BIT7;
  
  PE_DDR |= BIT7;
  PE_ODR &=~BIT7;
  PE_CR1 |= BIT7;
  PE_CR2 &=~BIT7;
  
  PC_DDR &=~BIT1;
  PC_CR1 |=BIT1;
  PC_CR2 |=BIT1;
  
  
  // chon cach tac dong interrupt
  EXTI_CR1&=~(BIT3+BIT2);  //Falling edge and low level
  // set muc uu tien
  //EXTI_CONF1
  asm("rim\n"); 
  while (1){
    if (BatDauChop){
      PC_ODR |= BIT7;
      PE_ODR &=~BIT7;
      BatDauChop=0;
      count = 20;
    }
    if (count){
      count--;
      PC_ODR ^= BIT7;
      PE_ODR ^= BIT7;  
    }else{
      PC_ODR &=~BIT7;
      PE_ODR &=~BIT7;
    }
    Delay(30000);
  }
  return 0;
}