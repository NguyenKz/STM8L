
#include<stdint.h>
typedef struct{
  uint8_t ADC1DMA_REMAP:2;
  uint8_t TIM4DMA_REMAP:2;
  uint8_t USART1TR_REMAP:2;
  uint8_t USART1CK_REMAP:1;
  uint8_t SPI1_REMAP1:1;
}RMPCR1_TYPE;


typedef struct{
  uint8_t ADC1TRIG_REMAP:1;
  uint8_t TIM2TRIG_REMAP:1;
  uint8_t IM3TRIG_REMAP1:1;
  uint8_t TIM2TRIGLSE_REMAP:1;
  uint8_t TIM3TRIGLSE_REMAP:1;
  
  uint8_t SPI2_REMAP:1;
  uint8_t TIM3TRIG_REMAP2:1;
  uint8_t TIM23BKIN_REMAP:1;
  
}RMPCR2_TYPE;



typedef struct {
  RMPCR1_TYPE SYSCFG_RMPCR1;
  RMPCR2_TYPE SYSCFG_RMPCR2;

}SYSCFG_type;
#define SYSCFG ((volatile SYSCFG_type *)0x509E)

