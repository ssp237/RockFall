/*extern "C" {
	#include "board_accelerometer.h"
	#include "fsl_debug_console.h"
	#include "board.h"
	#include "Driver_I2C.h"
	#include "fsl_i2c_hal.h"
	int32_t Accelerometer_Initialize();
	int32_t Accelerometer_GetState(ACCELEROMETER_STATE*);
}

ACCELEROMETER_STATE state;
int main(){
	hardware_init();
	Accelerometer_Initialize();
	while(1){
		Accelerometer_GetState(&state);
		debug_printf("%5d %5d %5d\r\n", state.x, state.y, state.z);
	}
}*/