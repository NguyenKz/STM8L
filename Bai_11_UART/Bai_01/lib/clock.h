#ifndef CLOCK
#define CLOCK

#include <stdint.h>
#include "gpio.h"


//CLK_DIVR_TYPE
//Reserved        CKM[2:0]
//- - - - -       rw rw rw
typedef struct {
//000: System clock source/1
//001: System clock source /2
//010: System clock source /4
//011: System clock source /8
//100: System clock source /16
//101: System clock source /32
//110: System clock source /64
//111: System clock source /128
//These bits are written by software to define the system clock prescaling factor.
  uint8_t CKM:3;
  uint8_t Reserved:5;
}CLK_DIVR_TYPE; 

//CLK_CRTCR_TYPE
//RTCDIV2 RTCDIV1 RTCDIV0 RTCSEL3 RTCSEL2 RTCSEL1 RTCSEL0 RTCSWBSY
//rw      rw      rw      rw      rw      rw      rw      r
typedef struct {
//This bit is set by hardware any time a valid clock change for RTC is required.
//It is reset when the RTC clock change procedure is complete.
  uint8_t RTCSWBSY  :1;
//0000: No clock selected
//0001: HSI clock used as RTC clock source
//0010: LSI clock used as RTC clock source
//0100: HSE clock used as RTC clock source
//1000: LSE clock used as RTC clock source
  uint8_t RTCSEL0   :1;
  uint8_t RTCSEL1   :1;
  uint8_t RTCSEL2   :1;
  uint8_t RTCSEL3   :1;
//000: RTC clock source/1
//001: RTC clock source /2
//010: RTC clock source /4
//011: RTC clock source /8
//100: RTC clock source /16
//101: RTC clock source /32
//110: RTC clock source /64
//111: RTC clock source /128
  uint8_t RTCDIV0   :1;
  uint8_t RTCDIV1   :1;
  uint8_t RTCDIV2   :1;

}CLK_CRTCR_TYPE;

//CLK_ICKCR_TYPE
//  Reserved    BEEPAHALT       FHWU     SAHALT  LSIRDY  LSION   HSIRDY  HSION
//  -           rw              rw       rw      r       rw      r       rw
typedef struct {

  
//This bit is set and cleared by software. It is set by hardware whenever the HSI oscillator is required, for
//example:
//? When activated as safe oscillator by the CSS
//? When switching to HSI clock (see CLK_SWR register)
//? When HSI is selected as the active CCO source, RTC clock
//? When exiting Halt/Active-halt in fast wake up mode
//It cannot be cleared when HSI is selected as system clock (CLK_SCSR register), as active CCO
//source, as active RTC clock or if the safe oscillator (AUX) is enabled.
//0: High-speed internal RC OFF
//1: High-speed internal RC ON
  uint8_t HSION  :1;
//This bit is set and cleared by hardware.
//0: HSI clock not ready
//1: HSI clock ready
  uint8_t HSIRDY   :1;
//example:
//? When switching to the LSI clock (see CLK_SWR register)
//? When LSI is selected as the active CCO source (see CLK_CCOR register)
//? When LSI is selected as the active RTC clock source (see CLK_CRTCR register)
//? When LSI is selected as the active BEEP clock source (see CLK_CBEEPR register)
//? When LSI measurement is enabled (MSR bit set in the BEEP_CSR1 register)
//It cannot be cleared when LSI is selected
//? as system clock source (CLK_SCSR register)
//? as active CCO source
//? as clock source for the BEEP peripheral while BEEPAHALT bit is set
//? or as active clock source for RTC.
//0: Low speed internal RC OFF
//1: Low speed internal RC ON
  uint8_t LSION   :1;
//This bit is set and cleared by hardware.
//0: LSI clock not ready
//1: LSI clock ready
  uint8_t LSIRDY   :1;
//This bit is set and cleared by software. When it is set, the main voltage regulator is powered off as
//soon as the MCU enters Active-halt mode, so the wakeup time is longer.
//0: MVR regulator ON in HALT/Active-halt mode
//1: MVR regulator OFF in HALT/Active-halt mode
  uint8_t SAHALT   :1;
//This bit is set and cleared by software.
//0: Fast wakeup from Halt/Active-halt modes disabled: system clock is the last selected clock source
//before entering Halt/Active-halt mode
//1: Fast wakeup from Halt/Active-halt modes enabled: HSI/8 used as system clock source after
//wakeup from Halt/Active-halt
  uint8_t FHWU   :1;
//This bit is set and cleared by software.
//0: BEEP clock is switched off during Halt mode or Active-halt mode
//1: BEEP clock is kept running during Halt mode
  uint8_t BEEPAHALT   :1;

  uint8_t Reserved   :1;

}CLK_ICKCR_TYPE;
//////////////////////
//PCKEN1[7:0]
//rw rw rw rw rw rw rw rw
//0: SYSCLK to peripheral disabled
//1: SYSCLK to peripheral enabled
//PCKEN17 DAC
//PCKEN16 BEEP
//PCKEN15 USART1
//PCKEN14 SPI1
//PCKEN13 I2C1
//PCKEN12 TIM4
//PCKEN11 TIM3
//PCKEN10 TIM2
//////////////////////


//CLK_PCKENR2_TYPE
//PCKEN27       Reserved        PCKEN2[5:0]
//rw            -               rw rw rw rw rw rw
//PCKEN27(1) Boot ROM
//PCKEN25 COMP1 and COMP2
//PCKEN24 DMA1
//PCKEN23 LCD
//PCKEN22 RTC
//PCKEN21 TIM1
//PCKEN20 ADC1
typedef struct {
//0: SYSCLK to peripheral disabled
//1: SYSCLK to peripheral enabled
  uint8_t PCKEN2  :6;
//0000: No clock selected
//0001: HSI clock used as RTC clock source
//0010: LSI clock used as RTC clock source
//0100: HSE clock used as RTC clock source
//1000: LSE clock used as RTC clock source
  uint8_t Reserved   :1;
//0: SYSCLK to peripheral disabled
//1: SYSCLK to peripheral enabled
  uint8_t PCKEN27   :1;

}CLK_PCKENR2_TYPE;

//
//Reserved      PCKEN3[5:0]
//-             rw rw rw rw rw rw
//PCKEN35 CSS_LSE
//PCKEN34 USART3
//PCKEN33 USART2
//PCKEN32 SPI2
//PCKEN31 TIM5
//PCKEN30 AES
typedef struct {
//0: SYSCLK to peripheral disabled
//1: SYSCLK to peripheral enabled
  uint8_t PCKEN3  :6;
  uint8_t Reserved   :2;

}CLK_PCKENR3_TYPE;



//7 6 5         4 3 2 1                 0
//CCODIV[2:0]   CCOSEL[3:0]             CCOSWBSY
//rw rw rw      rw rw rw rw             r
//Configurable clock output register CLK_CCOR
typedef struct {
//This bit is set and cleared by hardware. It indicates that the selected CCO clock source is being
//switched-on and stabilized. While CCOSWBSY is set, the CCOSEL bits and CCODIV bits are writeprotected.
//CCOSWBSY remains set until the CCO clock is enabled.
//0: CCO clock not busy
//1: CCO clock busy
  uint8_t CCOSWBSY  :1;
//These bits are written by software to select the source of the output clock available on the CCO pin.
//0000: Clock output disabled, no clock output on CCO pin
//0001: HSI clock output on CCO pin
//0010: LSI clock output on CCO pin
//0100: HSE clock output on CCO pin
//1000: LSE clock output on CCO pin
//Note: Any write with a non valid target code will be skipped.
//The content of these bits is frozen and write protected when CCOSWBSY is set.
  uint8_t CCOSEL   :4;
  uint8_t CCODIV   :3;

}CLK_CCOR_TYPE;



typedef struct{
  BYTE_TYPE DIVR;
  BYTE_TYPE CRTCR;
  BYTE_TYPE ICKR;
  BYTE_TYPE PCKENR1;
  BYTE_TYPE PCKENR2;
  BYTE_TYPE CCOR;
  BYTE_TYPE ECKR;
  BYTE_TYPE SCSR;
  BYTE_TYPE SWR;
  BYTE_TYPE SWCR;
  BYTE_TYPE CSSR;
  BYTE_TYPE CBEEPR;
  BYTE_TYPE HSICALR;
  BYTE_TYPE HSITRIMR;
  BYTE_TYPE HSIUNLCKR;
  BYTE_TYPE REGCSR;
} CLK_TYPE;

#define CLK ((volatile CLK_TYPE *)0x50C0)

#endif