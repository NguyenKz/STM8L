#ifndef SPI
#include "gpio.h"
#include "clock.h"
#include "exinterrupt.h"
#include "SYSCFG.h"
//Bit 7 LSBFIRST: Frame format (1)
//0: MSB is transmitted first
//1: LSB is transmitted first
//Bit 6 SPE: SPI enable (2)
//0: Peripheral disabled
//1: Peripheral enabled
//Bits 5:3 BR[2:0]: Baud rate control
//000: fSYSCLK/2
//001: fSYSCLK/4
//010: fSYSCLK/8
//011: fSYSCLK/16
//100: fSYSCLK/32
//101: fSYSCLK/64
//110: fSYSCLK/128
//111: fSYSCLK/256
//Note: These bits should not be changed when the communication is ongoing.
//Bit 2 MSTR: Master selection (1)
//0: Slave configuration
//1: Master configuration
//Bit1 CPOL: Clock polarity (1)
//0: SCK to 0 when idle
//1: SCK to 1 when idle
//Bit 0 CPHA: Clock phase (1)
//0: The first clock transition is the first data capture edge
//1: The second clock transition is the first data capture edge

typedef struct{
  uint8_t CPHA:1;       //0
  uint8_t CPOL:1;       //1
  uint8_t MSTR:1;       //2
  uint8_t BR:3;         //3,4,5
  uint8_t SPE:1;        //6
  uint8_t LSBFIRST:1;   //7

}CR1_TYPE;


//Bit 7 BDM: Bidirectional data mode enable
//0: 2-line unidirectional data mode selected
//1: 1-line bidirectional data mode selected
//Bit 6 BDOE: Input/Output enable in bidirectional mode
//This bit selects the direction of transfer in bidirectional mode when BDM is set to 1.
//0: Input enabled (receive-only mode)
//1: Output enabled (transmit-only mode)
//In master mode, the MOSI pin is used and in slave mode, the MISO pin is used.
//Bit 5 CRCEN: Hardware CRC calculation enable
//0: CRC calculation disabled
//1: CRC calculation Enabled
//Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation
//Bit 4 CRCNEXT: Transmit CRC next
//0: Next transmit value is from Tx buffer
//1: Next transmit value is from Tx CRC register
//Bit 3 Reserved
//Bit 2 RXONLY: Receive only
//0: Full duplex (Transmit and receive)
//1: Output disabled (Receive only mode)
//This bit combined with BDM bit selects the direction of transfer in 2 line uni-directional mode
//This bit is also useful in a multi-slave system in which this particular slave is not accessed, the output
//from the accessed slave is not corrupted.
//Bit 1 SSM: Software slave management
//0: Software slave management disabled
//1: Software slave management enabled
//When the SSM bit is set, the NSS pin input is replaced with the value coming from the SSI bit
//Bit 0 SSI: Internal slave select
//This bit has effect only when SSM bit is set. The value of this bit is forced onto the NSS pin and the I/O
//value of the NSS pin is ignored.
//0: Slave mode
//1: Master mode
typedef struct{
  uint8_t SSI:1;        //0
  uint8_t SSM:1;        //1
  uint8_t RXONLY:1;     //2
  uint8_t Reserved:3;   //3,4,5
  uint8_t BDOE:1;       //6
  uint8_t BDM:1;        //7
}CR2_TYPE;      

//
//Bit 7 TXIE: Tx buffer empty interrupt enable (1)
//0: TXE interrupt masked
//1: TXE interrupt not masked. This allows an interrupt request to be generated when the TXE flag is
//set.
//Bit 6 RXIE: RX buffer not empty interrupt enable (2)
//0: RXNE interrupt masked
//1: RXNE interrupt not masked. This allows an interrupt request to be generated when the RXNE flag
//is set.
//Bit 5 ERRIE: Error interrupt enable
//0: Error interrupt is masked
//1: Error interrupt is enabled. This allows an interrupt request to be generated when an error
//condition occurs (CRCERR, OVR, MODF)
//Bit 4 WKIE: Wakeup interrupt enable
//0: Wakeup interrupt masked
//1: Wakeup interrupt enabled. This allows an interrupt request to be generated when the WKUP flag
//is set.
//Bits 3:2 Reserved
//Bit 1 TXDMAEN: Tx Buffer DMA Enable
//When this bit is set, the DMA request is made whenever the TXE flag is set.
//0: Tx buffer DMA disabled
//1: Tx buffer DMA enabled
//Bit 0 RXDMAEN: Rx Buffer DMA Enable
//When this bit is set, the DMA request is made whenever the RXNE flag is set.
//0: Rx buffer DMA disabled
//1: Rx buffer DMA enabled
typedef struct{
  uint8_t Reserved:4;   //0,1,2,3
  uint8_t WKIE:1;       //4
  uint8_t ERRIE:1;      //5
  uint8_t RXIE:1;       //6
  uint8_t TXIE:1;       //7
}ICR_TYPE;

//Bit 7 BSY: Busy flag
//0: SPI not busy
//1: SPI is busy in communication
//This flag is set and reset by hardware.
//Note: BSY flag must be used with cautious: refer to Section 30.3.7: Status flags on page 574 and
//Section 30.3.8: Disabling the SPI on page 574
//Bit 6 OVR: Overrun flag
//0: No Overrun occurred
//1: Overrun occurred
//This flag is set by hardware and reset by a software sequence.
//Bit 5 MODF: Mode fault
//0: No Mode fault occurred
//1: Mode fault occurred
//This flag is set by hardware and reset by a software sequence.
//Bit 4 CRCERR: CRC error flag
//0: CRC value received matches the SPI_RXCRCR value
//1: CRC value received does not match the SPI_RXCRCR value
//This flag is set by hardware and cleared by software writing 0.
//Bit 3 WKUP: Wakeup flag
//0: No wakeup event occurred
//1: Wakeup event occurred
//This flag is set on the first sampling edge on SCK when the STM8 is in Halt mode and the SPI is
//configured as slave.
//This flag is reset by software writing 0.
//Bit 2 Reserved
//Bit 1 TXE: Transmit buffer empty
//0: Tx buffer not empty
//1: Tx buffer empty
//Bit 0 RXNE: Receive buffer not empty
//0: Rx buffer empty
//1: Rx buffer not empty

typedef struct{
  
  uint8_t RXNE:1;       //0
  uint8_t TXE:1;        //1
  uint8_t Reserved_0:1;   //2
  uint8_t WKUP:1;       //3
  uint8_t Reserved_1:1;   //4
  uint8_t MODF:1;       //5
  uint8_t OVR:1;        //6
  uint8_t BSY:1;        //7
}SR_TYPE;





typedef struct{
  CR1_TYPE CR1;           //SPI1 control register 1 0x00
  CR2_TYPE CR2;           //SPI1 control register 2 0x00
  ICR_TYPE ICR;           //SPI1 interrupt control register 0x00
  SR_TYPE SR;            //SPI1 status register 0x02
  uint8_t DR;            //SPI1 data register 0x00
  uint8_t CRCPR;         //SPI1 CRC polynomial register 0x07
  uint8_t RXCRCR;        //SPI1 Rx CRC register 0x00
  uint8_t TXCRCR;        //SPI1 Tx CRC register 0x00
}SPI_TYPE;

#define SPI1 ((volatile SPI_TYPE *)0x5200)


void InitSPIMaster(void);
void InitSPISlave(void);
void sendChar(char);
void sendString(const char *);
char*receiveStr();
#endif