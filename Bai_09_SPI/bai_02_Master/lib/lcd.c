#include "Lcd.h"

void LCD_Init(uint8_t SEG){
  LCD->CR1 |= (3<<1); // 1/4 Duty 
  LCD->CR1 &= ~(1<<0); // 1/3 Bias
  
  LCD->CR2 |= (1<<4); // HD on
  LCD->CR2 |= (4<<1); //Vlcd4
  LCD->CR2 |=1; // Internal Voltage Source
  
  //LCD->FRQ = 0x30;
  
  LCD->PM[3] = 0x00;
  if (SEG & (1<<1)){ // SEG1 Enable
    LCD->PM[0] |= (3<<0);
    LCD->PM[2] |= (12<<4);
  }
  if (SEG & (1<<2)){ // SEG2 Enable
    LCD->PM[0] |= (12<<0);
    LCD->PM[2] |= (3<<4);
  }
  if (SEG & (1<<3)){ // SEG3 Enable
    LCD->PM[0] |= (3<<4);
    LCD->PM[2] |= (12<<0);
  }
  if (SEG & (1<<4)){ // SEG4 Enable
    LCD->PM[0] |= (12<<4);
    LCD->PM[2] |= (3<<0);
  }
  if (SEG & (1<<5)){ // SEG5 Enable
    LCD->PM[1] |= (12<<4);
    LCD->PM[1] |= (3<<0);
  }
  if (SEG & (1<<6)){ // SEG6 Enable
    LCD->PM[1] |= (3<<4);
    LCD->PM[1] |= (12<<0);
  }
  
  //LCD->CR3 |= (1<<5); //IRQ Enable
  LCD->CR3 |= (1<<6); //LCD Enalbe
}

void LCD_SEG1(uint16_t data){
  _1A = (data & (1<<0)) ? 1:0;
  _1B = (data & (1<<1)) ? 1:0;
  _1C = (data & (1<<2)) ? 1:0;
  _1D = (data & (1<<3)) ? 1:0;
  _1E = (data & (1<<4)) ? 1:0;
  _1F = (data & (1<<5)) ? 1:0;
  _1G = (data & (1<<6)) ? 1:0;
  _1H = (data & (1<<7)) ? 1:0;
  _1J = (data & (1<<8)) ? 1:0;
  _1K = (data & (1<<9)) ? 1:0;
  _1M = (data & (1<<10)) ? 1:0;
  _1N = (data & (1<<11)) ? 1:0;
  _1P = (data & (1<<12)) ? 1:0;
  _1Q = (data & (1<<13)) ? 1:0;
  _1DP = (data & (1<<14)) ? 1:0;
  _1CL = (data & (1<<15)) ? 1:0;
}

void LCD_SEG2(uint16_t data){
  _2A = (data & (1<<0)) ? 1:0;
  _2B = (data & (1<<1)) ? 1:0;
  _2C = (data & (1<<2)) ? 1:0;
  _2D = (data & (1<<3)) ? 1:0;
  _2E = (data & (1<<4)) ? 1:0;
  _2F = (data & (1<<5)) ? 1:0;
  _2G = (data & (1<<6)) ? 1:0;
  _2H = (data & (1<<7)) ? 1:0;
  _2J = (data & (1<<8)) ? 1:0;
  _2K = (data & (1<<9)) ? 1:0;
  _2M = (data & (1<<10)) ? 1:0;
  _2N = (data & (1<<11)) ? 1:0;
  _2P = (data & (1<<12)) ? 1:0;
  _2Q = (data & (1<<13)) ? 1:0;
  _2DP = (data & (1<<14)) ? 1:0;
  _2CL = (data & (1<<15)) ? 1:0;
}

void LCD_SEG3(uint16_t data){
  _3A = (data & (1<<0)) ? 1:0;
  _3B = (data & (1<<1)) ? 1:0;
  _3C = (data & (1<<2)) ? 1:0;
  _3D = (data & (1<<3)) ? 1:0;
  _3E = (data & (1<<4)) ? 1:0;
  _3F = (data & (1<<5)) ? 1:0;
  _3G = (data & (1<<6)) ? 1:0;
  _3H = (data & (1<<7)) ? 1:0;
  _3J = (data & (1<<8)) ? 1:0;
  _3K = (data & (1<<9)) ? 1:0;
  _3M = (data & (1<<10)) ? 1:0;
  _3N = (data & (1<<11)) ? 1:0;
  _3P = (data & (1<<12)) ? 1:0;
  _3Q = (data & (1<<13)) ? 1:0;
  _3DP = (data & (1<<14)) ? 1:0;
  _3CL = (data & (1<<15)) ? 1:0;
}

void LCD_SEG4(uint16_t data){
  _4A = (data & (1<<0)) ? 1:0;
  _4B = (data & (1<<1)) ? 1:0;
  _4C = (data & (1<<2)) ? 1:0;
  _4D = (data & (1<<3)) ? 1:0;
  _4E = (data & (1<<4)) ? 1:0;
  _4F = (data & (1<<5)) ? 1:0;
  _4G = (data & (1<<6)) ? 1:0;
  _4H = (data & (1<<7)) ? 1:0;
  _4J = (data & (1<<8)) ? 1:0;
  _4K = (data & (1<<9)) ? 1:0;
  _4M = (data & (1<<10)) ? 1:0;
  _4N = (data & (1<<11)) ? 1:0;
  _4P = (data & (1<<12)) ? 1:0;
  _4Q = (data & (1<<13)) ? 1:0;
  _4DP = (data & (1<<14)) ? 1:0;
  _4CL = (data & (1<<15)) ? 1:0;
}

void LCD_SEG5(uint16_t data){
  _5A = (data & (1<<0)) ? 1:0;
  _5B = (data & (1<<1)) ? 1:0;
  _5C = (data & (1<<2)) ? 1:0;
  _5D = (data & (1<<3)) ? 1:0;
  _5E = (data & (1<<4)) ? 1:0;
  _5F = (data & (1<<5)) ? 1:0;
  _5G = (data & (1<<6)) ? 1:0;
  _5H = (data & (1<<7)) ? 1:0;
  _5J = (data & (1<<8)) ? 1:0;
  _5K = (data & (1<<9)) ? 1:0;
  _5M = (data & (1<<10)) ? 1:0;
  _5N = (data & (1<<11)) ? 1:0;
  _5P = (data & (1<<12)) ? 1:0;
  _5Q = (data & (1<<13)) ? 1:0;
}

void LCD_SEG6(uint16_t data){
  _6A = (data & (1<<0)) ? 1:0;
  _6B = (data & (1<<1)) ? 1:0;
  _6C = (data & (1<<2)) ? 1:0;
  _6D = (data & (1<<3)) ? 1:0;
  _6E = (data & (1<<4)) ? 1:0;
  _6F = (data & (1<<5)) ? 1:0;
  _6G = (data & (1<<6)) ? 1:0;
  _6H = (data & (1<<7)) ? 1:0;
  _6J = (data & (1<<8)) ? 1:0;
  _6K = (data & (1<<9)) ? 1:0;
  _6M = (data & (1<<10)) ? 1:0;
  _6N = (data & (1<<11)) ? 1:0;
  _6P = (data & (1<<12)) ? 1:0;
  _6Q = (data & (1<<13)) ? 1:0;
}

uint16_t GetHexCodeNum(int data){
  switch (data){
  case 0: return 0x08BF; break;
  case 1: return 0x0006; break;
  case 2: return 0x045B; break;
  case 3: return 0x044F; break;
  case 4: return 0x0466; break;
  case 5: return 0x046D; break;
  case 6: return 0x047D; break;
  case 7: return 0x0007; break;
  case 8: return 0x047F; break;
  case 9: return 0x046F; break;
  case 'A': return 0x0477; break;
  case 'B': return 0x150F; break;
  case 'C': return 0x0039; break;
  case 'D': return 0x110F; break;
  case 'E': return 0x0479; break;
  case 'F': return 0x0071; break;
  case 'G': return 0x043D; break;
  case 'H': return 0x0476; break;
  case 'I': return 0x1109; break;
  case 'J': return 0x01E; break;
  case 'K': return 0x0A70; break;
  case 'L': return 0x0038; break;
  case 'M': return 0x02B6; break;
  case 'N': return 0x08B6; break;
  case 'O': return 0x003F; break;
  case 'P': return 0x0473; break;
  case 'Q': return 0x083F; break;
  case 'R': return 0x0C73; break;
  case 'S': return 0x046D; break;
  case 'T': return 0x1101; break;
  case 'X': return 0x2A80; break;
  case 'Y': return 0x1280; break;
  case 'Z': return 0x2209; break;
  case 'V': return 0x0886; break;
  case 'U': return 0x003E; break;
  case 'W': return 0x2836; break;
  default: return 0x003F; break;
  
  }
}