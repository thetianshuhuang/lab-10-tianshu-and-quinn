/*
 * guitar.h
 *
 * Graphics for the onscreen guitar
 */

#include "guitar.h"
#include "../display/ST7735.h"

// 16x14
const uint16_t RedPickup[] = { 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000,
  0x0000, 0x001F, 0x001F, 0x001F, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x001F, 0x001F, 0x001F, 0x0000,
	0x001F, 0x001F, 0x001F, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x001F, 0x001F, 0x001F,
  0x001F, 0x001F, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x001F, 0x001F,
	0x001F, 0x001F, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x001F, 0x001F,
	0x001F, 0x001F, 0x001F, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x001F, 0x001F, 0x001F,
	0x0000, 0x001F, 0x001F, 0x001F, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x001F, 0x001F, 0x001F, 0x0000,
	0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001F, 0x001F, 0x001F, 0x001F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
const uint16_t YellowPickup[] = { 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x07FF, 0x07FF, 0x07FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x07FF, 0x07FF, 0x07FF, 0x0000, 0x0000,
  0x0000, 0x07FF, 0x07FF, 0x07FF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07FF, 0x07FF, 0x07FF, 0x0000,
	0x07FF, 0x07FF, 0x07FF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07FF, 0x07FF, 0x07FF,
  0x07FF, 0x07FF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07FF, 0x07FF,
	0x07FF, 0x07FF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07FF, 0x07FF,
	0x07FF, 0x07FF, 0x07FF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07FF, 0x07FF, 0x07FF,
	0x0000, 0x07FF, 0x07FF, 0x07FF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07FF, 0x07FF, 0x07FF, 0x0000,
	0x0000, 0x0000, 0x07FF, 0x07FF, 0x07FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x07FF, 0x07FF, 0x07FF, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07FF, 0x07FF, 0x07FF, 0x07FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
const uint16_t BluePickup[] = { 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0xF800, 0xF800, 0xF800, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF800, 0xF800, 0xF800, 0x0000, 0x0000,
  0x0000, 0xF800, 0xF800, 0xF800, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xF800, 0xF800, 0xF800, 0x0000,
	0xF800, 0xF800, 0xF800, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xF800, 0xF800, 0xF800,
  0xF800, 0xF800, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xF800, 0xF800,
	0xF800, 0xF800, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xF800, 0xF800,
	0xF800, 0xF800, 0xF800, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xF800, 0xF800, 0xF800,
	0x0000, 0xF800, 0xF800, 0xF800, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xF800, 0xF800, 0xF800, 0x0000,
	0x0000, 0x0000, 0xF800, 0xF800, 0xF800, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF800, 0xF800, 0xF800, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xF800, 0xF800, 0xF800, 0xF800, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
const uint16_t GreenPickup[] = { 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000,
  0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000,
  0x0000, 0x07E0, 0x07E0, 0x07E0, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07E0, 0x07E0, 0x07E0, 0x0000,
	0x07E0, 0x07E0, 0x07E0, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07E0, 0x07E0, 0x07E0,
  0x07E0, 0x07E0, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07E0, 0x07E0,
	0x07E0, 0x07E0, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07E0, 0x07E0,
	0x07E0, 0x07E0, 0x07E0, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07E0, 0x07E0, 0x07E0,
	0x0000, 0x07E0, 0x07E0, 0x07E0, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x07E0, 0x07E0, 0x07E0, 0x0000,
	0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x07E0, 0x07E0, 0x07E0, 0x07E0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

void drawGuitar(void){
	ST7735_FillScreen(0);
	ST7735_DrawBitmap(101, 155, RedPickup,16,14);
	ST7735_DrawBitmap(71, 155, YellowPickup,16,14);
	ST7735_DrawBitmap(41, 155, BluePickup,16,14);
	ST7735_DrawBitmap(11, 155, GreenPickup,16,14);
	ST7735_DrawCircle(101, 130, 0x001F);
	ST7735_DrawCircle(71, 130, 0x07FF);
	ST7735_DrawCircle(41, 130, 0xF800);
	ST7735_DrawCircle(11, 130, 0x07E0);
	ST7735_DrawLine(0, 0, 159, 159, 0xFFFF);
}
