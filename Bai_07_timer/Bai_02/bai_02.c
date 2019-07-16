#include<stdint.h>

#define TIM1_CR1      (*(uint8_t *)0x52B0)     //TIM1 control register 1 0x00                   
#define TIM1_CR2      (*(uint8_t *)0x52B1)     //TIM1 control register 2 0x00                   
#define TIM1_SMCR     (*(uint8_t *)0x52B2)     //TIM1 Slave mode control register 0x00          
#define TIM1_ETR      (*(uint8_t *)0x52B3)     //TIM1 external trigger register 0x00            
#define TIM1_DER      (*(uint8_t *)0x52B4)     //TIM1 DMA1 request enable register 0x00         
#define TIM1_IER      (*(uint8_t *)0x52B5)     //TIM1 Interrupt enable register 0x00            
#define TIM1_SR1      (*(uint8_t *)0x52B6)     //TIM1 status register 1 0x00                    
#define TIM1_SR2      (*(uint8_t *)0x52B7)     //TIM1 status register 2 0x00                    
#define TIM1_EGR      (*(uint8_t *)0x52B8)     //TIM1 event generation register 0x00            
#define TIM1_CCMR1    (*(uint8_t *)0x52B9)     //TIM1 Capture/Compare mode register 1 0x00        
#define TIM1_CCMR2    (*(uint8_t *)0x52BA)     //TIM1 Capture/Compare mode register 2 0x00        
#define TIM1_CCMR3    (*(uint8_t *)0x52BB)     //TIM1 Capture/Compare mode register 3 0x00        
#define TIM1_CCMR4    (*(uint8_t *)0x52BC)     //TIM1 Capture/Compare mode register 4 0x00        
#define TIM1_CCER1    (*(uint8_t *)0x52BD)     //TIM1 Capture/Compare enable register 1 0x00      
#define TIM1_CCER2    (*(uint8_t *)0x52BE)     //TIM1 Capture/Compare enable register 2 0x00      
#define TIM1_CNTRH    (*(uint8_t *)0x52BF)     //TIM1 counter high 0x00                           
#define TIM1_CNTRL    (*(uint8_t *)0x52C0)     //TIM1 counter low 0x00                            
#define TIM1_PSCRH    (*(uint8_t *)0x52C1)     //TIM1 prescaler register high 0x00                
#define TIM1_PSCRL    (*(uint8_t *)0x52C2)     //TIM1 prescaler register low 0x00               
#define TIM1_ARRH     (*(uint8_t *)0x52C3)     //TIM1 Auto-reload register high 0xFF            
#define TIM1_ARRL     (*(uint8_t *)0x52C4)     //TIM1 Auto-reload register low 0xFF             
#define TIM1_RCR      (*(uint8_t *)0x52C5)     //TIM1 Repetition counter register 0x00          
#define TIM1_CCR1H    (*(uint8_t *)0x52C6)     //TIM1 Capture/Compare register 1 high 0x00      
#define TIM1_CCR1L    (*(uint8_t *)0x52C7)     //TIM1 Capture/Compare register 1 low 0x00       
#define TIM1_CCR2H    (*(uint8_t *)0x52C8)     //TIM1 Capture/Compare register 2 high 0x00      
#define TIM1_CCR2L    (*(uint8_t *)0x52C9)     //TIM1 Capture/Compare register 2 low 0x00       
#define TIM1_CCR3H    (*(uint8_t *)0x52CA)     //TIM1 Capture/Compare register 3 high 0x00      
#define TIM1_CCR3L    (*(uint8_t *)0x52CB)     //TIM1 Capture/Compare register 3 low 0x00       
#define TIM1_CCR4H    (*(uint8_t *)0x52CC)     //TIM1 Capture/Compare register 4 high 0x00      
#define TIM1_CCR4L    (*(uint8_t *)0x52CD)     //TIM1 Capture/Compare register 4 low 0x00       
#define TIM1_BKR      (*(uint8_t *)0x52CE)     //TIM1 break register 0x00                       
#define TIM1_DTR      (*(uint8_t *)0x52CF)     //TIM1 dead-time register 0x00                   
#define TIM1_OISR     (*(uint8_t *)0x52D0)     //TIM1 output idle state register 0x00           
#define TIM1_DCR1     (*(uint8_t *)0x52D1)     //DMA1 control register 1 0x00                   
#define TIM1_DCR2     (*(uint8_t *)0x52D2)     //TIM1 DMA1 control register 2 0x00              
#define TIM1_DMA1R    (*(uint8_t *)0x52D3)     //TIM1 DMA1 address for burst mode 0x00            


#define CLK_DIVR      (*(uint8_t *)0x50C0)      //Clock master divider register 0x03
#define CLK_CRTCR     (*(uint8_t *)0x50C1)      //Clock RTC register 0x00
#define CLK_ICKR      (*(uint8_t *)0x50C2)      //Internal clock control register 0x11
#define CLK_PCKENR1   (*(uint8_t *)0x50C3)      //Peripheral clock gating register 1 0x00
#define CLK_PCKENR2   (*(uint8_t *)0x50C4)      //Peripheral clock gating register 2 0x80
#define CLK_CCOR      (*(uint8_t *)0x50C5)      //Configurable clock control register 0x00
#define CLK_ECKR      (*(uint8_t *)0x50C6)      //External clock control register 0x00
#define CLK_SCSR      (*(uint8_t *)0x50C7)      //System clock status register 0x01
#define CLK_SWR       (*(uint8_t *)0x50C8)      //System clock switch register 0x01
#define CLK_SWCR      (*(uint8_t *)0x50C9)      //Clock switch control register 0bxxxx0000
#define CLK_CSSR      (*(uint8_t *)0x50CA)      //Clock security system register 0x00
#define CLK_CBEEPR    (*(uint8_t *)0x50CB)      //Clock BEEP register 0x00
#define CLK_HSICALR   (*(uint8_t *)0x50CC)      //HSI calibration register 0xxx
#define CLK_HSITRIMR  (*(uint8_t *)0x50CD)      //HSI clock calibration trimming register 0x00
#define CLK_HSIUNLCKR (*(uint8_t *)0x50CE)      //HSI unlock register 0x00
#define CLK_REGCSR    (*(uint8_t *)0x50CF)      //Main regulator control status register 0bxx11100x






#define EXTI_CR1        *(uint8_t *)    0x50A0
#define EXTI_SR1        *(uint8_t *)    0x50A3
#define EXTI_CONF1      *(uint8_t *)    0x50A5


#define PC_ODR        (*(uint8_t *) 0x500A) // data output latch register 0x00
#define PC_IDR        (*(uint8_t *) 0x500B) // input pin value register 0xXX
#define PC_DDR        (*(uint8_t *) 0x500C) // data direction register 0x00
#define PC_CR1        (*(uint8_t *) 0x500D) // control register 1 0x00
#define PC_CR2        (*(uint8_t *) 0x500E) // control register 2 0x00

#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80


void config_timer();
void config_clock();
int printf(const char *format, ...);
void config_GPIO();

uint16_t count=0;
uint8_t  speed=0;
int main(){
  config_GPIO();
  config_timer();
  
  asm("rim\n");
  while (1){
  
  }

  return 0;
}
#pragma vector =11
__interrupt void button(){
  while(!(PC_IDR&BIT1)){}
  if ((TIM1_ARRH==0x18) && (TIM1_ARRL==0x6a)){
    TIM1_ARRH=0x0C;
    TIM1_ARRL=0x35;
  }else{
    TIM1_ARRH=0x18;       //auto reload = 6250
    TIM1_ARRL=0x6a;
  }
  EXTI_SR1    |=BIT1;
  
}
#pragma vector =25
__interrupt void timer(){
  PC_ODR^=BIT7;         //changed led to debug
  count++;              
  if (count>9999)
    count=0;
  printf("%d",count);   //display
  TIM1_SR1 = ~BIT0;
}


void config_clock(){
  
  CLK_PCKENR2|=BIT1;    //TIM1
  CLK_SWCR|=BIT1;       //In automatic switching mode (SWEN=1):
  CLK_SWR&=0x00;         //HSI selected as system clock source 16 MHz high-speed internal (HSI) factory-trimmed RC clock
  CLK_SWR|=0x01;
  CLK_SWCR|=BIT1;           //Enable clock switch execution
  CLK_DIVR=0x00;        //001: System clock source  =16mhz
  while((CLK_SWCR&BIT0)){}        //Clock switch ongoing
}
void config_timer(){
  config_GPIO();
  config_clock();
  TIM1_CR1&=~BIT4;      //0: Counter used as up-counter
  TIM1_CR1|=BIT0;       //1: Counter enabled
  TIM1_IER|=BIT0;       //1: Update interrupt enabled/
  TIM1_PSCRH=0x00;      //The prescaler=255
  TIM1_PSCRL=0xff;
  //time clock=62500 HZ
  TIM1_ARRH=0x18;       //auto reload = 6250
  TIM1_ARRL=0x6a;
  //time interval  =0.1s
}
void config_GPIO(){
  PC_DDR |=BIT7;
  
  PC_CR1 |=BIT7;
  
  PC_DDR &=~BIT1;       //set input for user button
  PC_CR1 |=BIT1;        //set pull-up
  PC_CR2 |=BIT1;        //set enable interrupt
}