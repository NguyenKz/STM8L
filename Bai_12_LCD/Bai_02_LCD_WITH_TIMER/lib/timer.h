#include <stdint.h>

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

#define _BIT0 0x01
#define _BIT1 0x02
#define _BIT2 0x04
#define _BIT3 0x08
#define _BIT4 0x10
#define _BIT5 0x20
#define _BIT6 0x40
#define _BIT7 0x80
