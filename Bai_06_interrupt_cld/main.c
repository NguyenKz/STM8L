#include<stdint.h>


#define CLK_CKDIVR (*(uint8_t*)0x50c0) /*!< Clock master divider register */
#define CLK_CRTCR (*(uint8_t*)0x50c1) /*!< Clock RTC Register */
#define CLK_PCKENR2 (*(uint8_t*)0x50c4) /*!< Peripheral clock gating register 2 */

#define PC_DDR (*(uint8_t*)0x500c) /*!< Port C data direction register */
#define PC_CR1 (*(uint8_t*)0x500d) /*!< Port C control register 1 */
#define PC_CR2 (*(uint8_t*)0x500e) /*!< Port C control register 2 */

#define EXTI_CR1 (*(uint8_t*)0x50a0) /*!< External interrupt control register 1 */
#define EXTI_SR1 (*(uint8_t*)0x50a3) /*!< EXternal interrupt status register */
#define ITC_SPR3 (*(uint8_t*)0x7f72) /*!< Software priority register 3 */
#define ITC_SPR5 (*(uint8_t*)0x7f74) /*!< Software priority register 5 */

#define LCD_CR1 (*(uint8_t*)0x5400) /*!< LCD control register 1 */
#define LCD_CR2 (*(uint8_t*)0x5401) /*!< LCD control register 2 */
#define LCD_CR3 (*(uint8_t*)0x5402) /*!< LCD control register 3 */
#define LCD_FRQ (*(uint8_t*)0x5403) /*!< LCD frequency selection register */
#define LCD_PM0 (*(uint8_t*)0x5404) /*!< LCD Port mask register 0 */
#define LCD_PM1 (*(uint8_t*)0x5405) /*!< LCD Port mask register 1 */
#define LCD_PM2 (*(uint8_t*)0x5406) /*!< LCD Port mask register 2 */
#define LCD_PM3 (*(uint8_t*)0x5407) /*!< LCD Port mask register 3 */

#define LCD_RAM0 (*(uint8_t*)0x540c) /*!< LCD display memory 0 */
#define LCD_RAM1 (*(uint8_t*)0x540d) /*!< LCD display memory 1 */
#define LCD_RAM2 (*(uint8_t*)0x540e) /*!< LCD display memory 2 */
#define LCD_RAM3 (*(uint8_t*)0x540f) /*!< LCD display memory 3 */
#define LCD_RAM4 (*(uint8_t*)0x5410) /*!< LCD display memory 4 */
#define LCD_RAM5 (*(uint8_t*)0x5411) /*!< LCD display memory 5 */
#define LCD_RAM6 (*(uint8_t*)0x5412) /*!< LCD display memory 6 */

#define SET_B(REG,N) (REG |= (1<<N)) /*!< Set bit N of register */
#define CLR_B(REG,N) (REG &= ~(1<<N)) /*!< Clear bit N of register */
#define GET_B(REG,N) ((0u == (REG & (1<<N)))?0u:1u) /*!< Get bit N of register */

static uint8_t counter = 0;
static uint8_t counter_changed = 1;
#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80


void config_LCD();
void number_2(uint8_t number);
void number_1(uint8_t number);

uint8_t count=0;
int main(){
  
  PC_DDR &=~BIT1;
  PC_CR1 |=BIT1;
  PC_CR2 |=BIT1;
  config_LCD();
  
  asm("RIM\n");
  while (1) {
  }
  
  
  return 0;
}
#pragma vector = 18
__interrupt void LCD(void)
{

  number_2(counter % 10); 
  number_1(counter / 10);
  LCD_CR3|=BIT3;
	
}
#pragma vector = 11
__interrupt void BUTTON(void)
{
  count++;
  if (count>99){
    count=0;
  }
  EXTI_SR1|=BIT1;
}
void number_2(uint8_t number)
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


void number_1(uint8_t number)
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
	 
	}
}

void config_LCD(){
  //enable clock lcd
  CLK_PCKENR2|=BIT3;
  //LCD_CR1
  //BLINK1 BLINK0 BLINKF2 BLINKF1 BLINKF0 DUTY1 DUTY0 B2
//  Bits 5:3 BLINKF[2:0]: Blink frequency
//  000: fLCD/8
//  001: fLCD/16
//  010: fLCD/32
//  011: fLCD/64
//  100: fLCD/128
//  101: fLCD/256
//  110: fLCD/512
//  111: fLCD/1024
  LCD_CR1 &=~(BIT5+BIT4+BIT3);
//  Bits 2:1 DUTY: Duty ratio selection
//  00: Static duty
//  01: 1/2 duty
//  10: 1/3 duty
//  11: 1/4 duty
  LCD_CR1 &=~(BIT2+BIT1);
  
//  Bit 0 B2: 1/2 Bias selector
//  0: 1/3 bias
//  1: 1/2 bias
  LCD_CR1 &=~BIT0;
  //LCD_CR2
  //PON2 PON1 PON0 HD CC2 CC1 CC0 VSEL
  //rw rw rw rw rw rw rw rw
//   Bits 7:5 PON: Pulse ON duration              tan sao que lcd
//  These bits specify the pulse duration (number of CLKPS pulses). The pulse duration is PON[2:0] clock
//  cycles coming out from the first prescaler thus determining the amount of time the RL resistive network
//  is turned on for each voltage transition on SEG and COM pins. A short drive time decreases power
//  consumption, but displays with a high internal resistance may need longer drive time to achieve a
//  satisfactory contrast.
//  Note: The drive time will never be longer than half the prescaled LCD clock period
//  000: 0 CLKPS pulses
//  001: 1 CLKPS pulses*
//  010: 2 CLKPS pulses
//  011: 3 CLKPS pulses
//  100: 4 CLKPS pulses
//  101: 5 CLKPS pulses
//  110: 6 CLKPS pulses
//  111: 7 CLKPS pulses
//    
  LCD_CR2 |=BIT5;
//  Bits 3:1 CC[2:0]: Contrast control
//  These bits specify one of the VLCD maximum voltage (independent of VDD).
//  The new values will have effect every beginning of a new frame. The contrast controller (Boost circuit)
//  is required inside the voltage generator.
//  000: VLCD0
//  001: VLCD1
//  010: VLCD2
//  011: VLCD3
//  100: VLCD4*
//  101: VLCD5
//  110: VLCD6
//  111: VLCD7
//  Note: Refer to the device datasheet for the VLCDx values.
    LCD_CR2 |=BIT3;
    
//    Bit 4 HD: High drive enable
//This bit permanently enables the low resistance divider. Displays with a high internal resistance may
//need longer drive time to achieve a satisfactory contrast, so the software can set the HD bit if there is
//no strong power constraint.
//0: High drive permanent disabled
//1: High drive permanent enabled
    
    LCD_CR2 |=BIT4;
    //LCD_CR3
    //LCDEN SOFIE SOF SOFC DEAD2 DEAD1 DEAD0
    //rw rw r w rw rw rw
//    Bit 6 LCDEN: LCD enable
//  Clearing this bit during a frame delays the reset at the end of the even frame in order to avoid a
//  medium voltage level different from 0 during the frame.
//  0: LCD controller disabled
//  1: LCD controller enabled
    LCD_CR3 |=BIT6;
      
//      Bit 5 SOFIE: Interrupt enable
//When this bit is set, the LCD start of frame interrupt is enabled.
//0: SOF interrupt disabled
//1: SOF interrupt enabled
//      
    LCD_CR3 |=BIT5;
    
    LCD_PM0 = 0x0f; 
    LCD_PM1 = 0x00;
    LCD_PM2 = 0xf0;
    LCD_PM3 = 0x00;
  

}