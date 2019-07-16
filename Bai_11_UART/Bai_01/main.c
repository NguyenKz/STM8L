
#include "lib/uart.h"
#include "lib/gpio.h"
#include "lib/clock.h"
#include "lib/Itc.h"
#include "lib/exinterrupt.h"
#include "stdio.h"

void InitClock();
void InitGpio();
void InitUart();
void USART_Transmit(char data);

void USART_SendString(char *data);
char *str;
uint8_t len=0;
char x;
char rx;
uint8_t dangNhan=0;
void delay(){
  uint32_t time=20000;
  while (time--);
}

void nhanDuLieu(){
  if (!dangNhan){
    dangNhan=1;
    free(str);
    len=0;
    str=(char *)malloc(50*sizeof(char));
  }
  rx=UART1->USART1_SR.RXNE;
  
  while (!UART1->USART1_SR.RXNE){}
  
  x=UART1->USART1_DR;
  //printf("%d\n",x);
  //printf(" c:%c \n",x);
  //rx=UART1->USART1_SR.RXNE;
  //printf("RNEX: %d.\n",rx);
  str[len]=x;
  str[len+1]=0;
  if (x==0||len>50){
    dangNhan=0;
    printf("ket qua: %s \n",str);
  }
  len++;
}
int main(){
  InitClock();
  //InitGpio();
  InitUart();
  asm("rim\n"); 
  while(1){
    delay();
    USART_SendString("Tran Thao Nguyen\n");
  }
  
  
  
  while(1){}
  return 0;
}
#pragma vector = 30
__interrupt void USART_Recived(void){
  //PC->ODR.BIT7 ^=1;
  nhanDuLieu();
}
#pragma vector=11
__interrupt void Pressbutton(){
  while (!PC->IDR.BIT1){}
  PC->ODR.BIT7^=1;
  USART_SendString("Tran Thao Nguyen");
  EXTI->SR1.P1F=1;

}
void USART_Transmit(char data){
  while (!(UART1->USART1_SR.TXE));
  UART1->USART1_DR = data;
}

void USART_SendString(char *data){
  register unsigned i = 0;
  while(data[i]){
    USART_Transmit(data[i]);
    i++;
  }
}

void InitClock(){
  CLK->DIVR.CKM=0x00;           //DIV 0
  CLK->ICKR.HSION=1;            //HSI=16MHZ
  while (!CLK->SCSR){}          //wait
  CLK->PCKENR2.PCKEN23=1;       // clock lcd
  CLK->CRTCR.RTCSEL0=0;         //LSE lsc
  CLK->CRTCR.RTCSEL1=0;
  CLK->CRTCR.RTCSEL2=0;
  CLK->CRTCR.RTCSEL3=1;
  
  CLK->CCOR.CCOSEL=0x5;
  while(!(CLK->ECKR.LSERDY)){
    printf("%d\n",CLK->ECKR.HSEBYP);
    printf("%d\n",CLK->ECKR.HSEON);
    printf("%d\n",CLK->ECKR.HSERDY);
    printf("%d\n",CLK->ECKR.LSEBYP);
    printf("%d\n",CLK->ECKR.LSEON);
    printf("%d\n",CLK->ECKR.LSERDY);
    printf("\n----------------\n");
  }
  CLK->PCKENR1.PCKEN15=1;       //enable clock uart
  
}
void InitGpio(){
  EXTI->CR1.P1IS=0x0;
  PC->DDR.BIT7=0;
  PC->CR1.BIT7=1;
  PC->CR2.BIT7=1;
  PC->ODR.BIT7=1;
  
  PC->DDR.BIT1=0;
  PC->CR1.BIT1=1;
  PC->CR2.BIT1=1;
  
  PE->DDR.BIT7=0;
  PE->CR1.BIT7=1;
  PE->CR2.BIT7=1;
  PE->ODR.BIT7=1;
  ITC->SPR3 |= (3<<2);
  
  ITC->SPR8 |= (3<<0);
}
void InitUart(){
  UART1->USART1_BRR1 = 0x68;
  UART1->USART1_BRR2.USART_DIV_LSB = 0x03;           //9600 baud
  UART1->USART1_CR1.M=0;        //8bit
  UART1->USART1_CR1.USARTD=0;   //0: USART enabled
  UART1->USART1_CR2.REN=1;
  UART1->USART1_CR2.TEN=1;
  UART1->USART1_CR2.RIEN=1;
}