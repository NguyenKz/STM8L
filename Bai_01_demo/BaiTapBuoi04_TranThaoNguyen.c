#include <stdint.h>

#define PC_ODR	(*(volatile uint8_t *)0x500a)
#define PC_IDR  (*(volatile uint8_t *)0x500b)
#define PC_DDR	(*(volatile uint8_t *)0x500c)
#define PC_CR1	(*(volatile uint8_t *)0x500d)
#define PC_CR2  (*(volatile uint8_t *)0x500e)


#define PE_ODR	(*(volatile uint8_t *)0x5014)
#define PE_DDR	(*(volatile uint8_t *)0x5016)
#define PE_CR1	(*(volatile uint8_t *)0x5017)

#define CLK_DIVR	(*(volatile uint8_t *)0x50c0)
#define CLK_PCKENR2	(*(volatile uint8_t *)0x50c4)



#define SetBit(a,b) ((a)|=(0x1<<(b)))    //set bit
#define ClearBit(a,b) ((a)&=~(0x1<<(b))) //clear bit
#define GetBit(a,b) (0x1&(a)>>(b))       //get bit


void Delay(unsigned int time){
  while (time){
    time--;
  }

}

void main(void)
{
        uint8_t count=0;
	CLK_DIVR = 0x00; // Set the frequency to 16 MHz
	CLK_PCKENR2 |= 0x02; // Enable clock to timer
	// Configure pins
	PE_DDR = 0x80;  //use Led Blue
	PE_CR1 = 0x80;  //use register 1
        PE_ODR =0x7f;   //turn off Led Blue
        
        
	PC_DDR = 0x82;  //use Led Green and Button
	PC_CR1 = 0x82;  //use register 1 
        PC_CR2 = 0x0;   
	for(;;)
	{
          if ((PC_IDR&0x2)){      //press
            
            if (count>100){// long press
              PC_ODR =0x80;
            }else{
              PC_ODR &=0x7f;
              count++;
            }
            PE_ODR =0x80;
            Delay(40000);
            PE_ODR |= 0x7f;
            
          }else{
            PC_ODR &=0x7f;
            count=0;
          }
          

	}
   
}