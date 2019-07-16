/* Signed integer types  */
typedef   signed char     int8_t;
typedef   signed short    int16_t;
typedef   signed long     int32_t;

/* Unsigned integer types  */
typedef unsigned char     uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned long     uint32_t;
#define PC_ODR *(uint8_t *)0x500A
#define PC_IDR *(uint8_t *)0x500B
#define PC_DDR *(uint8_t *)0x500C
#define PC_CR1 *(uint8_t *)0x500D
#define PC_CR2 *(uint8_t *)0x500E

#define SBit(VAR, Place)         ((VAR) |= ((1<< Place)))
#define CBit(VAR, Place)         ((VAR) &=~ ((1<<Place)))
void Delay (uint32_t nCount);
#define CLK_DIVR      *(uint8_t *)0x50C0 /*   Clock master divider register 0x03                  */
#define CLK_SCSR      *(uint8_t *)0x50C7 /*   System clock status register 0x01                   */
#define CLK_SWR       *(uint8_t *)0x50C8 /*   System clock switch register 0x01                    */
#define CLK_SWCR      *(uint8_t *)0x50C9 /*   Clock switch control register 0bxxxx0000            */
void main( void )
{

  
  /* Enables switching the system clock */
  SBit(CLK_SWCR, 1);

  //    0x08: LSE selected as system clock source
  //CLK_SWR&=0;
  CLK_SWR |= 0x08;
  
  /* 000: System clock source/1 */
  CLK_DIVR &= 0;
 // CBit(CLK_SWCR,1);
//  0x01: HSI selected as system clock source (reset value)
//  0x02: LSI selected as system clock source
//  0x04: HSE selected as system clock source
//  0x08: LSE selected as system clock source
  while (!(CLK_SCSR & 0x08));
  
  
 
  SBit(PC_DDR, 7);
  SBit(PC_CR1, 7);
  CBit(PC_CR2, 7);
  while(1)
  {  
    SBit(PC_ODR, 7);
    Delay(1000);
    CBit(PC_ODR, 7);
    Delay(1000);
  }
  
}


void Delay(uint32_t nCount)
{
  nCount = nCount*50;
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}