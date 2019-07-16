#include<stdint.h>

typedef struct{
//  0: Data is not transferred to the shift register
//  1: Data is transferred to the shift register
    uint8_t PE    : 1;
//  0: Transmission is not complete
//  1: Transmission is complete
    uint8_t FE    : 1;
//  0: Data is not received
//  1: Received data is ready to be read.
    uint8_t NF    : 1;
//  0: No Idle Line is detected
//  1: Idle Line is detected
    uint8_t OR    : 1;
//  0: No Overrun error
//  1: Overrun error is detected
    uint8_t IDLE  : 1;
//  0: No noise is detected
//  1: Noise is detected
    uint8_t RXNE  : 1;
//  0: No framing error is detected
//  1: Framing error or break character is detected
    uint8_t TC    : 1;
//  0: No parity error
//  1: Parity error
    uint8_t TXE   : 1;    
}USART1_SR_TYPE;
typedef struct{
//  0: Parity interrupt disabled
//  1: Parity interrupt is generated whenever PE=1 in the USART_SR register
    uint8_t PIEN    : 1;
//  0: Even parity
//  1: Odd parity
    uint8_t PS:      :1;    
//  0: Parity control disabled
//  1: Parity control enabled
    uint8_t PCEN    : 1;
//  0: Idle line
//  1: Address mark
    uint8_t WAKE    : 1;
//   0: 1 Start bit, 8 Data bits, ‘n’ STOP bit (n depending on STOP[1:0] bits in the USART_CR3 register)
//   1: 1 Start bit, 9 Data bits, 1 STOP bit
    uint8_t M  : 1;
//  0: USART enabled
//  1: USART prescaler and outputs disabled
    uint8_t USARTD  : 1;
//  This bit is used to store the 9th bit of the transmitted word when M=1
    uint8_t T8    : 1;
//  This bit is used to store the 9th bit of the received word when M=1
    uint8_t R8   : 1;    
}USART_CR1_TYPE;
typedef struct{
//0: No break character is transmitted
//1: Break character will be transmitted
    uint8_t SBK    : 1;
//0: Receiver in active mode
//1: Receiver in mute mode
    uint8_t RWU:      :1;    
//0: Receiver is disabled
//1: Receiver is enabled and begins searching for a start bit
    uint8_t REN    : 1;
//0: Transmitter is disabled
//1: Transmitter is enabled
    uint8_t TEN    : 1;
//0: Interrupt is inhibited
//1: An USART interrupt is generated whenever IDLE=1 in the USART_SR register
    uint8_t ILIEN  : 1;
//0: Interrupt is inhibited
//1: An USART interrupt is generated whenever OR=1 or RXNE=1 in the USART_SR register
    uint8_t RIEN  : 1;
//0: Interrupt is inhibited
//1: An USART interrupt is generated whenever TC=1 in the USART_SR register
    uint8_t TCIEN    : 1;
//0: Interrupt is inhibited
//1: An USART interrupt is generated whenever TXE=1 in the USART_SR register
    uint8_t TIEN   : 1;    
}USART_CR2_TYPE;
typedef struct{
//0: The clock pulse of the last data bit is not output to the USART_CK pin.
//1: The clock pulse of the last data bit is output to the USART_CK pin.
    uint8_t LBCL    : 1;
//0: The first clock transition is the first data capture edge
//1: The second clock transition is the first data capture edge
    uint8_t CPHA:      :1;    
//0: USART_CK to 0 when idle
//1: USART_CK to 1 when idle.
    uint8_t CPOL    : 1;
//0: USART_CK pin disabled
//1: USART_CK pin enabled
    uint8_t CLKEN    : 1;
//00: 1 STOP bit
//01: Reserved
//10: 2 STOP bits
//11: 1.5 STOP bits
    uint8_t STOP  : 2;
    uint8_t Reserved:2;
}USART_CR3_TYPE;
typedef struct{
//These 4 bits define the LSB of the USART Divider (USART_DIV)
    uint8_t USART_DIV_LSB:4;
//These 4 bits define the MSB of the USART Divider (USART_DIV)
    uint8_t USART_DIV_MSB:4;
}USART_BRR2_TYPE;
typedef struct{
//This bit-field gives the address of the USART node.
//This is used in multiprocessor communication during mute mode, for wakeup with address mark
//detection.
    uint8_t ADD    :4;
    uint8_t Reserved:4;
}USART_CR4_TYPE;
typedef struct{
//0: Interrupt is inhibited
//1: An interrupt is generated whenever DMAR=1 in the USART_CR5 register and FE=1 or OR=1 or
//NF=1 in the USART_SR register.
    uint8_t EIE    : 1;
//0: IrDA disabled
//1: IrDA enabled
    uint8_t IREN:      :1;    
//0: Normal mode
//1: Low power mode
    uint8_t IRLP    : 1;
//0: Half duplex mode is not selected
//1: Half duplex mode is selected
    uint8_t HDSEL    : 1;
//0: NACK transmission in case of parity error is disabled
//1: NACK transmission during parity error is enabled.
    uint8_t NACK  : 1;
//0: Smartcard Mode disabled
//1: Smartcard Mode enabled
    uint8_t SCEN  : 1;
//1: DMA mode is enabled for reception.
//0: DMA mode is disabled for reception.
    uint8_t DMAR    : 1;
//1: DMA mode is enabled for transmission.
//0: DMA mode is disabled for transmission.
    uint8_t DMAT   : 1;    
}USART_CR5_TYPE;
typedef struct{
  USART1_SR_TYPE USART1_SR;
  uint8_t USART1_DR;
  uint8_t USART1_BRR1;
  USART_BRR2_TYPE USART1_BRR2;
  USART_CR1_TYPE USART1_CR1;
  USART_CR2_TYPE USART1_CR2;
  USART_CR3_TYPE USART1_CR3;
  USART_CR4_TYPE USART1_CR4;
  USART_CR5_TYPE USART1_CR5;
  uint8_t USART1_GTR;
  uint8_t USART1_PSCR;
}UART_TYPE;

#define (( volatile UART_TYPE *)0x5230)
