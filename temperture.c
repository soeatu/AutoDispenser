#include "iodefine.h"
#include "Hardware_Setup.h"

void temperture_set(void){
	PORTA.PDR.BIT.B0 = 0;
}

void temperture_get(void){
	S12AD.ADDR0;
	
}