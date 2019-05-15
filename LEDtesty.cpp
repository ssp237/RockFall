extern "C" {
	#include "board_accelerometer.h"
	#include "fsl_debug_console.h"
	#include "board.h"
	#include "Driver_I2C.h"
	#include <stdio.h>

extern ARM_DRIVER_I2C Driver_I2C0;
static ARM_DRIVER_I2C * topDriver = &Driver_I2C0;
extern ARM_DRIVER_I2C Driver_I2C1;
static ARM_DRIVER_I2C * botDriver = &Driver_I2C1;
}

#define LED_ON 1
#define LED_OFF 0
#define LED_RED 1
#define LED_YELLOW 2
#define LED_GREEN 3
#define HT16K33_BLINK_CMD 0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BLINK_OFF 0
#define HT16K33_BLINK_2HZ  1
#define HT16K33_BLINK_1HZ  2
#define HT16K33_BLINK_HALFHZ  3
#define HT16K33_CMD_BRIGHTNESS 0xE0

uint32_t adr = 0x70;
uint8_t topBuff[17];
uint8_t botBuff[17];

void i2c_init (void) {
  topDriver->Initialize   (NULL);
  topDriver->PowerControl (ARM_POWER_FULL);
  topDriver->Control      (ARM_I2C_BUS_SPEED, ARM_I2C_BUS_SPEED_FAST);
  topDriver->Control      (ARM_I2C_BUS_CLEAR, 0);
}

void board_init (void) {
	uint8_t x[1];
	x[0] = 0x21;
	topDriver->MasterTransmit(adr, x, 1, false);
	while (topDriver->GetStatus().busy) ;
	x[0] = (HT16K33_BLINK_CMD | HT16K33_BLINK_DISPLAYON | HT16K33_BLINK_OFF);	
  topDriver->MasterTransmit(adr, x, 1, false);
	while (topDriver->GetStatus().busy);
	x[0] = (HT16K33_CMD_BRIGHTNESS | 15);
  topDriver->MasterTransmit(adr, x, 1, false);
	while (topDriver->GetStatus().busy);
	
	x[0] = 0x21;
	botDriver->MasterTransmit(adr, x, 1, false);
	while (botDriver->GetStatus().busy) ;
	x[0] = (HT16K33_BLINK_CMD | HT16K33_BLINK_DISPLAYON | HT16K33_BLINK_OFF);	
  botDriver->MasterTransmit(adr, x, 1, false);
	while (botDriver->GetStatus().busy);
	x[0] = (HT16K33_CMD_BRIGHTNESS | 15);
  botDriver->MasterTransmit(adr, x, 1, false);
	while (botDriver->GetStatus().busy);
}

void board_display() {
	topDriver->MasterTransmit(adr, topBuff, 17, false);		
	while (topDriver->GetStatus().busy);
	botDriver->MasterTransmit(adr, botBuff, 17, false);		
	while (botDriver->GetStatus().busy);
}


void clearBuffer() {
  for (uint8_t i=0; i<=16; i++) {
		topBuff[i] = 0;
		botBuff[i] = 0;
  }
}

int main(){
	hardware_init();	
	i2c_init();
	board_init();
	clearBuffer();
	topBuff[4] = 7;
	board_display();
	
}