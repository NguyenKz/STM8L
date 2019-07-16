#include <stdint.h>

#define CLK_CKDIVR (*(uint8_t*)0x50c0) 
#define CLK_CRTCR (*(uint8_t*)0x50c1)
#define CLK_PCKENR2 (*(uint8_t*)0x50c4)

#define PC_ODR *(uint8_t *) 0x500A
#define PC_IDR *(uint8_t *) 0x500B
#define PC_DDR *(uint8_t *) 0x500C
#define PC_CR1 *(uint8_t *) 0x500D
#define PC_CR2 *(uint8_t *) 0x500E

#define EXTI_CR1 (*(uint8_t*)0x50a0)
#define EXTI_SR1 (*(uint8_t*)0x50a3)
#define ITC_SPR3 (*(uint8_t*)0x7f72)
#define ITC_SPR5 (*(uint8_t*)0x7f74)

#define LCD_CR1 (*(uint8_t*)0x5400) 
#define LCD_CR2 (*(uint8_t*)0x5401) 
#define LCD_CR3 (*(uint8_t*)0x5402) 
#define LCD_FRQ (*(uint8_t*)0x5403) 
#define LCD_PM0 (*(uint8_t*)0x5404) 
#define LCD_PM1 (*(uint8_t*)0x5405) 
#define LCD_PM2 (*(uint8_t*)0x5406) 
#define LCD_PM3 (*(uint8_t*)0x5407) 

#define LCD_RAM0 (*(uint8_t*)0x540c) 
#define LCD_RAM1 (*(uint8_t*)0x540d) 
#define LCD_RAM2 (*(uint8_t*)0x540e) 
#define LCD_RAM3 (*(uint8_t*)0x540f) 
#define LCD_RAM4 (*(uint8_t*)0x5410) 
#define LCD_RAM5 (*(uint8_t*)0x5411) 
#define LCD_RAM6 (*(uint8_t*)0x5412) 

#define SET_B(REG,N) (REG |= (1<<N)) 
#define CLR_B(REG,N) (REG &= ~(1<<N))
#define GET_B(REG,N) ((0u == (REG & (1<<N)))?0u:1u) 
static uint8_t counter = 0;


void number_2(uint8_t number);
void number_1(uint8_t number);



void config_LCD();
int main(void)
{
	CLR_B(PC_DDR,1);
	SET_B(PC_CR1,1);
	SET_B(PC_CR2,1);
	config_LCD();
	asm("RIM\n");
	while (1) {
	}
	
	return 0;
}

void config_LCD(){
  SET_B(CLK_PCKENR2,3);
  CLR_B(LCD_CR1,0); 
  SET_B(LCD_CR1,1);
  SET_B(LCD_CR1,2);
  
  LCD_PM0 = 0x0f; 
  LCD_PM1 = 0x00;
  LCD_PM2 = 0xf0;
  LCD_PM3 = 0x00;
  SET_B(LCD_CR2,3);
  SET_B(LCD_CR2,4);
  SET_B(LCD_CR3,5);
  
  SET_B(LCD_CR3,6);
}

#pragma vector = 11
__interrupt void user_button_interrupt_handler(void)
{
  while (!(PC_IDR&=BIT1)){}
  counter++;
  if (counter > 99)
          counter = 0;
  
  SET_B(EXTI_SR1,1); 
}

#pragma vector = 18
__interrupt void LCD_interrupt_handler(void)
{

    number_2(counter % 10); 
    number_1(counter / 10);
    SET_B(LCD_CR3,3);	
}

void number_1(uint8_t number)
{
	switch (number) {
	    case 0:
		LCD_RAM0 |= 0x01;
		LCD_RAM2 |= 0x40;
		LCD_RAM3 |= 0x30;
		LCD_RAM6 |= 0x0c;
		break;
	    case 1:
		LCD_RAM2 |= 0x40;
		LCD_RAM3 |= 0x20;
		break;
	    case 2:
		LCD_RAM0 |= 0x03;
		LCD_RAM2 |= 0xc0;
		LCD_RAM3 |= 0x10;
		LCD_RAM6 |= 0x04;
		break;
	    case 3:
		LCD_RAM0 |= 0x02;
		LCD_RAM2 |= 0xc0;
		LCD_RAM3 |= 0x30;
		LCD_RAM6 |= 0x04;
		break;
	    case 4:
		LCD_RAM0 |= 0x02;
		LCD_RAM2 |= 0xc0;
		LCD_RAM3 |= 0x20;
		LCD_RAM6 |= 0x08;
		break;
	    case 5:
		LCD_RAM0 |= 0x02;
		LCD_RAM2 |= 0x80;
		LCD_RAM3 |= 0x30;
		LCD_RAM6 |= 0x0c;
		break;
	    case 6:
		LCD_RAM0 |= 0x03;
		LCD_RAM2 |= 0x80;
		LCD_RAM3 |= 0x30;
		LCD_RAM6 |= 0x0c;
		break;
	    case 7:
		LCD_RAM2 |= 0x40;
		LCD_RAM3 |= 0x20;
		LCD_RAM6 |= 0x04;
		break;
	    case 8:
		LCD_RAM0 |= 0x03;
		LCD_RAM2 |= 0xc0;
		LCD_RAM3 |= 0x30;
		LCD_RAM6 |= 0x0c;
		break;
	    case 9:
		LCD_RAM0 |= 0x02;
		LCD_RAM2 |= 0xc0;
		LCD_RAM3 |= 0x30;
		LCD_RAM6 |= 0x0c;
		break;
	}
}


void number_2(uint8_t number)
{
	switch (number) {
	    case 0:
		LCD_RAM0 = 0x04;
		LCD_RAM2 = 0x10;
		LCD_RAM3 = 0xc0;
		LCD_RAM6 = 0x03;
		break;
	    case 1:
		LCD_RAM0 = 0x00;
		LCD_RAM2 = 0x10;
		LCD_RAM3 = 0x80;
		LCD_RAM6 = 0x00;
		break;
	    case 2:
		LCD_RAM0 = 0x0c;
		LCD_RAM2 = 0x30;
		LCD_RAM3 = 0x40;
		LCD_RAM6 = 0x01;
		break;
	    case 3:
		LCD_RAM0 = 0x08;
		LCD_RAM2 = 0x30;
		LCD_RAM3 = 0xc0;
		LCD_RAM6 = 0x01;
		break;
	    case 4:
		LCD_RAM0 = 0x08;
		LCD_RAM2 = 0x30;
		LCD_RAM3 = 0x80;
		LCD_RAM6 = 0x02;
		break;
	    case 5:
		LCD_RAM0 = 0x08;
		LCD_RAM2 = 0x20;
		LCD_RAM3 = 0xc0;
		LCD_RAM6 = 0x03;
		break;
	    case 6:
		LCD_RAM0 = 0x0c;
		LCD_RAM2 = 0x20;
		LCD_RAM3 = 0xc0;
		LCD_RAM6 = 0x03;
		break;
	    case 7:
		LCD_RAM0 = 0x00;
		LCD_RAM2 = 0x10;
		LCD_RAM3 = 0x80;
		LCD_RAM6 = 0x01;
		break;
	    case 8:
		LCD_RAM0 = 0x0c;
		LCD_RAM2 = 0x30;
		LCD_RAM3 = 0xc0;
		LCD_RAM6 = 0x03;
		break;
	    case 9:
		LCD_RAM0 = 0x08;
		LCD_RAM2 = 0x30;
		LCD_RAM3 = 0xc0;
		LCD_RAM6 = 0x03;
		break;
	    default:
		return;
	}
}