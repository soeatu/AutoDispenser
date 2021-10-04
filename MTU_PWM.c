#include "iodefine.h"
#include "Hardware_Setup.h"
#include "MTU_PWM.h"

int flag = 0;

void MTU_start(void){
	MTU.TSTR.BIT.CST0 = 1;		//�^�C�}�X�^�[�g���W�X�^�@�J�E���^�X�^�[�g�r�b�g�@0:MTU0�J�E���g��~ 1:MTU0�J�E���g����
}

void MTU_stop(void){
	MTU.TSTR.BIT.CST0 = 0;		//�^�C�}�X�^�[�g���W�X�^�@�J�E���^�X�^�[�g�r�b�g�@0:MTU0�J�E���g��~ 1:MTU0�J�E���g����
}

void MTU_Change_Func(void){
	
	if(flag == 0){
		MTU.TSTR.BIT.CST0 = 0;
		MTU0.TGRA = MTU0_TGRA;
		MTU0.TGRB = MTU0_TGRB_1;
		MTU.TSTR.BIT.CST0 = 1;	
		flag = 1;
	}else if(flag == 1){
		MTU.TSTR.BIT.CST0 = 0;
		MTU0.TGRA = MTU0_TGRA;
		MTU0.TGRB = MTU0_TGRB_2;
		MTU.TSTR.BIT.CST0 = 1;	
		flag = 0;
	}
}

void MTU_Change_Func1(void){
	
	MTU.TSTR.BIT.CST0 = 0;
	MTU0.TGRA = MTU0_TGRA;
	MTU0.TGRB = MTU0_TGRB_1;
	MTU.TSTR.BIT.CST0 = 1;
	
}

void MTU_Change_Func2(void){
	
	MTU.TSTR.BIT.CST0 = 0;
	MTU0.TGRA = MTU0_TGRA ;
	MTU0.TGRB = MTU0_TGRB_2;
	MTU.TSTR.BIT.CST0 = 1;
	
}