#include "Hardware_Setup.h"
#include "iodefine.h"
#include "HC_SR04.h"
#include "MTU_PWM.h"
#include "Timer.h"
#include "Dispenser.h"

int distance = 0;
int mode = 0;
int flag1 = 0;


void dispenser(void){
	distance = re_range_return();
	
	switch(mode){
		case 0: //MTU_Change_Func1();
			flag1 = 0;
			break;
		case 1: push_action();
			break;
		default: break;
	}
	
	if(distance <= 10){
		mode = 1;
	}else if(distance >= 11){
		mode = 0;
	}
	
}

void push_action(void){
	
	if(flag1 == 0){
		MTU_Change_Func2();
		delay_ms(500);
			
		MTU_Change_Func1();
		delay_ms(500);
			
		MTU_Change_Func2();
		delay_ms(500);
			
		MTU_Change_Func1();
		delay_ms(500);
		
		mode = 0;
		flag1 = 1;
	}
}