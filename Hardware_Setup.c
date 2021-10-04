#include "iodefine.h"
#include "Hardware_Setup.h"

/*-------------------------------------------------------------------------------
	�֐���		: set_main_clk
	���e	 	: CPU CLOCK �̏�����
	����		: ����
	�ߒl		: ����
	�X�V��		: 2017/08/16
-------------------------------------------------------------------------------*/
void set_main_clk(void){

unsigned int i; 	


	// �N���b�N���� ( HOCO 50MHz���U )

	SYSTEM.PRCR.WORD   = 0xA507;						// �v���e�N�g����
	
	SYSTEM.HOCOWTCR2.BYTE = 0x03;						// 9216cyc���U�������
	SYSTEM.HOCOCR2.BYTE   = 0x03;						// 50MHz��I��  03
	SYSTEM.HOCOCR.BYTE    = 0x00;						// HOCO���U
	for( i = 0 ; i<11 ; i++ );						// 350��s�̔��U�ҋ@����

	// ���샂�[�h/�N���b�N������/�N���b�N���I��
	SYSTEM.OPCCR.BYTE  = 0x06;						// �ᑬ���샂�[�h�P�ɐ؂�ւ�	
	while( SYSTEM.OPCCR.BIT.OPCMTSF );					// �������������҂�													
	SYSTEM.SCKCR.LONG  = 0x10821115;					// �N���b�N������ݒ�
	while( SYSTEM.SCKCR.LONG!=0x10821115 );					// �������������҂�			
	*(char*)0x00080200 = 0x00;						// SCKCR3�ύX�葱��
	SYSTEM.SCKCR3.WORD = 0x0100;						// �N���b�N����HOCO

	RTC.RCR3.BYTE = 0x0C;							// �N���b�N���͋֎~
	while(RTC.RCR3.BIT.RTCEN);						// �������������҂�
	
	SYSTEM.PRCR.WORD   = 0xA500;						// �v���e�N�g�ݒ�	
	
}

/*-------------------------------------------------------------------------------
	�֐���		: set_IOport
	���e	 	: ���o�̓|�[�g���ꊇ�錾
	����		: ����
	�ߒl		: ����
	�X�V��		: 2021/04/21
-------------------------------------------------------------------------------*/
/*------------     IO�|�[�g�ݒ�     ------------*/
void set_IOport(void){

	//PDR�@����/�o�͂��w�肷��|�[�g�������W�X�^�@0:���� 1:�o��
	PORT0.PDR.BYTE = 0x00;
	PORT1.PDR.BYTE = 0x00;
	PORT2.PDR.BYTE = 0x00;
	PORT3.PDR.BYTE = 0x00;
	PORT4.PDR.BYTE = 0x00;
	PORT5.PDR.BYTE = 0x00;
	PORTA.PDR.BYTE = 0x00;
	PORTB.PDR.BYTE = 0x00;
	PORTC.PDR.BYTE = 0x00;
//	PORTD.PDR.BYTE = 0x00;
	PORTE.PDR.BYTE = 0x00;
	PORTH.PDR.BYTE = 0x00;
//	PORTJ.PDR.BYTE = 0x00;

	//PODR�@�|�[�g�o�̓f�[�^���W�X�^�@�ėp�o�̓|�[�g�Ƃ��Ďg�p����[�q�̏o�̓f�[�^���i�[���郌�W�X�^�@0:�o��Low�@1:�o��High
	PORT0.PODR.BYTE = 0x00;
	PORT1.PODR.BYTE = 0x00;
	PORT2.PODR.BYTE = 0x00;
	PORT3.PODR.BYTE = 0x00;
	PORT4.PODR.BYTE = 0x00;
	PORT5.PODR.BYTE = 0x00;
	PORTA.PODR.BYTE = 0x00;
	PORTB.PODR.BYTE = 0x00;
	PORTC.PODR.BYTE = 0x00;
//	PORTD.PODR.BYTE = 0x00;
	PORTE.PODR.BYTE = 0x00;
	PORTH.PODR.BYTE = 0x00;
//	PORTJ.PODR.BYTE = 0x00;

	//PIDR�@�|�[�g���̓f�[�^���W�X�^�@�|�[�g�̒[�q�̏�Ԃ𔽉f���郌�W�X�^�ł��@
	PORT0.PIDR.BYTE = 0x00;
	PORT1.PIDR.BYTE = 0x00;
	PORT2.PIDR.BYTE = 0x00;
	PORT3.PIDR.BYTE = 0x00;
	PORT4.PIDR.BYTE = 0x00;
	PORT5.PIDR.BYTE = 0x00;
	PORTA.PIDR.BYTE = 0x00;
	PORTB.PIDR.BYTE = 0x00;
	PORTC.PIDR.BYTE = 0x00;
//	PORTD.PIDR.BYTE = 0x00;
	PORTE.PIDR.BYTE = 0x00;
	PORTH.PIDR.BYTE = 0x00;
//	PORTJ.PIDR.BYTE = 0x00;

	//PMR�@���W�X�^�̊e�r�b�g�͂��ꂼ��̃|�[�g�̒[�q��{���ɑΉ����Ă���A�P�r�b�g�P�ʂŎw��ł���@1:�ėp���̓|�[�g�Ƃ��Ďg�p�@2:���Ӌ@��Ƃ��Ďg�p
	PORT0.PMR.BYTE = 0x00;
	PORT1.PMR.BYTE = 0x00;
	PORT2.PMR.BYTE = 0x00;
	PORT3.PMR.BYTE = 0x00;
	PORT4.PMR.BYTE = 0x00;
	PORT5.PMR.BYTE = 0x00;
	PORTA.PMR.BYTE = 0x00;
	PORTB.PMR.BYTE = 0x00;
	PORTC.PMR.BYTE = 0x00;
//	PORTD.PMR.BYTE = 0x00;
	PORTE.PMR.BYTE = 0x00;
	PORTH.PMR.BYTE = 0x00;
//	PORTJ.PMR.BYTE = 0x00;

	//ODR0�@�I�[�v���h���C�����䃌�W�X�^0�@�}�j���A���Q��
//	PORT0.ODR0.BYTE = 0x00;
	PORT1.ODR0.BYTE = 0x00;
//	PORT2.ODR0.BYTE = 0x00;
	PORT3.ODR0.BYTE = 0x00;
//	PORT4.ODR0.BYTE = 0x00;
//	PORT5.ODR0.BYTE = 0x00;
	PORTA.ODR0.BYTE = 0x00;
	PORTB.ODR0.BYTE = 0x00;
	PORTC.ODR0.BYTE = 0x00;
//	PORTD.ODR0.BYTE = 0x00;
	PORTE.ODR0.BYTE = 0x00;
//	PORTH.ODR0.BYTE = 0x00;
//	PORTJ.ODR0.BYTE = 0x00;

	//ODR1�@�I�[�v���h���C�����䃌�W�X�^1�@�}�j���A���Q��
//	PORT0.ODR1.BYTE = 0x00;
	PORT1.ODR1.BYTE = 0x00;
	PORT2.ODR1.BYTE = 0x00;
	PORT3.ODR1.BYTE = 0x00;
//	PORT4.ODR1.BYTE = 0x00;
//	PORT5.ODR1.BYTE = 0x00;
	PORTA.ODR1.BYTE = 0x00;
	PORTB.ODR1.BYTE = 0x00;
	PORTC.ODR1.BYTE = 0x00;
//	PORTD.ODR1.BYTE = 0x00;
//	PORTE.ODR1.BYTE = 0x00;
//	PORTH.ODR1.BYTE = 0x00;
//	PORTJ.ODR1.BYTE = 0x00;

	//PCR�@�v���A�b�v���䃌�W�X�^�@�[�q�����͏�Ԃ̂Ƃ��APORTm.PCR���W�X�^��"1"�̃r�b�g�ɑΉ�����[�q�̓��̓v���A�b�v��R���L���ɂȂ�@0:���̓v���A�b�v��R�����@1:���̓v���A�b�v��R�L��
	PORT0.PCR.BYTE = 0x00;
	PORT1.PCR.BYTE = 0x00;
	PORT2.PCR.BYTE = 0x00;
	PORT3.PCR.BYTE = 0x00;
	PORT4.PCR.BYTE = 0x00;
	PORT5.PCR.BYTE = 0x00;
	PORTA.PCR.BYTE = 0x00;
	PORTB.PCR.BYTE = 0x00;
	PORTC.PCR.BYTE = 0x00;
//	PORTD.PCR.BYTE = 0x00;
	PORTE.PCR.BYTE = 0x00;
	PORTH.PCR.BYTE = 0x00;
//	PORTJ.PWR.BYTE = 0x00;

	//DSCR  �쓮���䃌�W�X�^�@0:�ʏ�o�́@1:���쓮�o��
//	PORT0.DSCR.BYTE = 0x00;
	PORT1.DSCR.BYTE = 0x00;
//	PORT2.DSCR.BYTE = 0x00;
//	PORT3.DSCR.BYTE = 0x00;
//	PORT4.DSCR.BYTE = 0x00;
//	PORT5.DSCR.BYTE = 0x00;
//	PORTA.DSCR.BYTE = 0x00;
	PORTB.DSCR.BYTE = 0x00;
	PORTC.DSCR.BYTE = 0x00;
//	PORTD.DSCR.BYTE = 0x00;
//	PORTE.DSCR.BYTE = 0x00;
//	PORTH.DSCR.BYTE = 0x00;
//	PORTJ.DSCR.BYTE = 0x00;

}

/*-------------------------------------------------------------------------------
	�֐���		: set_AD_Convert
	���e	 	: A/D�ϊ����W�X�^�ݒ�
	����		: ����
	�ߒl		: ����
	�X�V��		: 2021/04/21
-------------------------------------------------------------------------------*/
void set_AD_Convert(void){
	//32bit�w���WORD��p����
	SYSTEM.PRCR.WORD = 0xA502;		//�v���e�N�g���W�X�^�@�@�@�@�@�@�@�@�@�@�@�@�v���e�N�g���W�X�^�̏���d�͒ጸ�@�\���������݋��@���8�r�b�g��A5�Œ�@����8�r�b�g�ɐݒ����������
	SYSTEM.MSTPCRA.BIT.MSTPA17 = 0;		//���W���[���X�g�b�v�R���g���[�����W�X�^A   ����d�͒ጸ�@�\��17bit���w�肵�ă��W���[���X�g�b�v��Ԃ�����
	SYSTEM.PRCR.WORD = 0xA500;		//�v���e�N�g���W�X�^�@�@�@�@�@�@�@�@�@�@�@�@�v���e�N�g���W�X�^�̏���d�͒ጸ�@�\���������݋֎~�@���8�r�b�g��A5�Œ�@����8�r�b�g�ɐݒ����������
	
	MPC.PWPR.BIT.PFSWE = 1;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 0;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	
	MPC.P40PFS.BIT.ASEL = 1;		//P40�[�q�@�\���䃌�W�X�^�@P40PFS�@AN000 ASEL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p���� 
//	MPC.P41PFS.BIT.ASEL = 1;		//P41�[�q�@�\���䃌�W�X�^�@P41PFS�@AN001 ASEL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.P42PFS.BIT.ASEL = 1;		//P42�[�q�@�\���䃌�W�X�^�@P42PFS�@AN002 ASEL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.P43PFS.BIT.ASEL = 1;		//P43�[�q�@�\���䃌�W�X�^�@P43PFS�@AN003 ASEL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.P44PFS.BIT.ASEL = 1;		//P44�[�q�@�\���䃌�W�X�^�@P44PFS�@AN004 ASEL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.P45PFS.BIT.ASEL = 1;		//P45�[�q�@�\���䃌�W�X�^�@P45PFS�@AN005 ASEL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p���� 100pin Only
//	MPC.P46PFS.BIT.ASEL = 1;		//P46�[�q�@�\���䃌�W�X�^�@P46PFS�@AN006 ASEL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.P47PFS.BIT.ASEL = 1;		//P47�[�q�@�\���䃌�W�X�^�@P47PFS�@AN007 ASEL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p���� 100pin Only

	MPC.PE0PFS.BIT.ASEL = 1;		//PE0�[�q�@�\���䃌�W�X�^�@PE0PFS�@AN008 AESL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.PE1PFS.BIT.ASEL = 1;		//PE1�[�q�@�\���䃌�W�X�^�@PE0PFS�@AN008 AESL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.PE2PFS.BIT.ASEL = 1;		//PE2�[�q�@�\���䃌�W�X�^�@PE0PFS�@AN008 AESL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.PE3PFS.BIT.ASEL = 1;		//PE3�[�q�@�\���䃌�W�X�^�@PE0PFS�@AN008 AESL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.PE4PFS.BIT.ASEL = 1;		//PE4�[�q�@�\���䃌�W�X�^�@PE0PFS�@AN008 AESL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.PE5PFS.BIT.ASEL = 1;		//PE5�[�q�@�\���䃌�W�X�^�@PE0PFS�@AN008 AESL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p����
//	MPC.PE6PFS.BIT.ASEL = 1;		//PE6�[�q�@�\���䃌�W�X�^�@PE0PFS�@AN008 AESL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p���� 100pin Only
//	MPC.PE7PFS.BIT.ASEL = 1;		//PE7�[�q�@�\���䃌�W�X�^�@PE0PFS�@AN008 AESL�r�b�g�@0:�A�i���O�[�q�ȊO�Ɏg�p����@1:�A�i���O�[�q�Ƃ��Ďg�p���� 100pin Only

	MPC.PWPR.BIT.PFSWE = 0;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 1;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	
	S12AD.ADANSA.BIT.ANSA0 = 1;		//A/D�ϊ��`���l���I���r�b�g[0]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA1 = 1;		//A/D�ϊ��`���l���I���r�b�g[1]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA2 = 1;		//A/D�ϊ��`���l���I���r�b�g[2]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA3 = 1;		//A/D�ϊ��`���l���I���r�b�g[3]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA4 = 1;		//A/D�ϊ��`���l���I���r�b�g[4]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA5 = 1;		//A/D�ϊ��`���l���I���r�b�g[5]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA6 = 1;		//A/D�ϊ��`���l���I���r�b�g[6]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA7 = 1;		//A/D�ϊ��`���l���I���r�b�g[7]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA8 = 1;		//A/D�ϊ��`���l���I���r�b�g[8]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA9 = 1;		//A/D�ϊ��`���l���I���r�b�g[9]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA10 = 1;		//A/D�ϊ��`���l���I���r�b�g[10]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA11 = 1;		//A/D�ϊ��`���l���I���r�b�g[11]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA12 = 1;		//A/D�ϊ��`���l���I���r�b�g[12]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA13 = 1;		//A/D�ϊ��`���l���I���r�b�g[13]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA14 = 1;		//A/D�ϊ��`���l���I���r�b�g[14]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���
//	S12AD.ADANSA.BIT.ANSA15 = 1;		//A/D�ϊ��`���l���I���r�b�g[15]�@0:AN000�`AN015��ϊ��Ώۂ���O���@1:AN000�`AN015��ϊ��ΏۂƂ���

//	S12AD.ADCSR.BIT.DBLANS = 0;		//A/D�R���g���[�����W�X�^�@A/D�ϊ��f�[�^2�d���`���l���I���r�b�g
//	S12AD.ADCSR.BIT.GBADIE = 0;		//A/D�R���g���[�����W�X�^�@�O���[�vB�X�L�����I�����荞�݋��r�b�g
//	S12AD.ADCSR.BIT.DBLE = 0;		//A/D�R���g���[�����W�X�^�@�_�u���g���K���[�h�I���r�b�g
//	S12AD.ADCSR.BIT.EXTRG = 0;		//A/D�R���g���[�����W�X�^�@�g���K�I���r�b�g
//	S12AD.ADCSR.BIT.TRGE = 0;		//A/D�R���g���[�����W�X�^�@�g���K�J�n���r�b�g
//	S12AD.ADCSR.BIT.ADIE = 0;		//A/D�R���g���[�����W�X�^�@�X�L�����I�����荞�݃r�b�g
	S12AD.ADCSR.BIT.ADCS = 2;		//A/D�R���g���[�����W�X�^�@�X�L�������[�h�I���r�b�g[1:0] 00:�V���O�� 01:�O���[�v 10:�A���X�L���� 11:�֎~
	S12AD.ADCSR.BIT.ADST = 1;		//A/D�R���g���[�����W�X�^�@A/D�ϊ��X�^�[�g�r�b�g�@0:A/D�ϊ���~�@1:A/D�ϊ��J�n
}

/*-------------------------------------------------------------------------------
	�֐���		: set_IRQ
	���e	 	: �O�������ݐݒ�
	����		: ����
	�ߒl		: ����
	�X�V��		: 2021/04/21
-------------------------------------------------------------------------------*/
void set_IRQ(void){
	//IRQ0
	ICU.IER[0x08].BIT.IEN0 = 0;		//���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	ICU.IPR[64].BYTE = 0x0F;		//IRQ0���荞�ݗv���v���C�I���e�B���W�X�^0�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	ICU.IRQFLTE0.BIT.FLTEN0 = 0;		//IRQ�[�q�f�W�^���t�B���^�����W�X�^0�@IRQ0�f�W�^���t�B���^���r�b�g�@0:�����@1:�L��
	ICU.IRQFLTC0.BIT.FCLKSEL0 = 3;		//IRQ�[�q�f�W�^���t�B���^�ݒ背�W�X�^0�@IRQ0�f�W�^���t�B���^�T���v�����O�N���b�N�ݒ�r�b�g�@00:PCLK�@01:PCLK8 10:PCLK32 11:PCLK64
	PORT3.PDR.BIT.B0 = 0;			//�|�[�g�ݒ�@P30����
	MPC.PWPR.BIT.B0WI  = 0;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	MPC.PWPR.BIT.PFSWE = 1;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.P30PFS.BIT.ISEL = 1;		//P30�[�q�@�\���䃌�W�X�^�@P30PFS�@0:IRQ���͒[�q�Ƃ��Ďg�p���Ȃ��@1:IRQ���͒[�q�Ƃ��Ďg�p
	MPC.PWPR.BIT.PFSWE = 0;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 1;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	PORT3.PMR.BIT.B0 = 1;			//�|�[�g���[�h���W�X�^�@�[�q���[�h����r�b�g�@0:�ėp���o�̓|�[�g�Ƃ��Ďg�p�@1:���Ӌ@��Ƃ��Ďg�p
	ICU.IRQCR[0].BIT.IRQMD = 3;		//IRQ�R���g���[�����W�X�^�@IRQ���o�ݒ�r�b�g�@00:Low 01:�����オ��G�b�W 10:������G�b�W 11:���G�b�W
	ICU.IR[64].BIT.IR = 0;			//���荞�ݗv�����W�X�^�@���荞�݃X�e�[�^�X�t���O�@0:���荞�ݗv���Ȃ��@1:���荞�ݗv������@�G�b�W���o�v���̏ꍇ0�̂݁@���x�����o�v���̏ꍇ��������NG
	ICU.IRQFLTE0.BIT.FLTEN0 = 1;		//IRQ�[�q�f�W�^���t�B���^�����W�X�^0�@IRQ0�f�W�^���t�B���^���r�b�g�@0:�����@1:�L��
	ICU.IER[0x02].BIT.IEN0 = 1;		//���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	
	
	//IRQ1
	ICU.IER[0x08].BIT.IEN1 = 0;		//���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	ICU.IPR[65].BYTE = 0x0F;		//IRQ0���荞�ݗv���v���C�I���e�B���W�X�^0�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	ICU.IRQFLTE0.BIT.FLTEN1 = 0;		//IRQ�[�q�f�W�^���t�B���^�����W�X�^1�@IRQ1�f�W�^���t�B���^���r�b�g�@0:�����@1:�L��
	ICU.IRQFLTC0.BIT.FCLKSEL1 = 3;		//IRQ�[�q�f�W�^���t�B���^�ݒ背�W�X�^1�@IRQ1�f�W�^���t�B���^�T���v�����O�N���b�N�ݒ�r�b�g�@00:PCLK�@01:PCLK8 10:PCLK32 11:PCLK64
	PORT3.PDR.BIT.B1 = 0;			//�|�[�g�ݒ�@P31����
	MPC.PWPR.BIT.B0WI  = 0;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	MPC.PWPR.BIT.PFSWE = 1;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.P31PFS.BIT.ISEL = 1;		//P31�[�q�@�\���䃌�W�X�^�@P31PFS�@0:IRQ���͒[�q�Ƃ��Ďg�p���Ȃ��@1:IRQ���͒[�q�Ƃ��Ďg�p
	MPC.PWPR.BIT.PFSWE = 0;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 1;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	PORT3.PMR.BIT.B1 = 1;			//�|�[�g���[�h���W�X�^�@�[�q���[�h����r�b�g�@0:�ėp���o�̓|�[�g�Ƃ��Ďg�p�@1:���Ӌ@��Ƃ��Ďg�p
	ICU.IRQCR[1].BIT.IRQMD = 3;		//IRQ�R���g���[�����W�X�^�@IRQ���o�ݒ�r�b�g�@00:Low 01:�����オ��G�b�W 10:������G�b�W 11:���G�b�W
	ICU.IR[65].BIT.IR = 0;			//���荞�ݗv�����W�X�^�@���荞�݃X�e�[�^�X�t���O�@0:���荞�ݗv���Ȃ��@1:���荞�ݗv������@�G�b�W���o�v���̏ꍇ0�̂݁@���x�����o�v���̏ꍇ��������NG
	ICU.IRQFLTE0.BIT.FLTEN1 = 1;		//IRQ�[�q�f�W�^���t�B���^�����W�X�^0�@IRQ0�f�W�^���t�B���^���r�b�g�@0:�����@1:�L��
	ICU.IER[0x08].BIT.IEN1 = 1;		//���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	
	/*
	//IRQ2
	ICU.IER[0x02].BIT.IEN0 = 0;		//���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	ICU.IPR[67].BYTE = 0x0f;			//IRQ0���荞�ݗv���v���C�I���e�B���W�X�^0�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	ICU.IRQFLTE0.BIT.FLTEN0 = 0;		//IRQ�[�q�f�W�^���t�B���^�����W�X�^0�@IRQ0�f�W�^���t�B���^���r�b�g�@0:�����@1:�L��
	ICU.IRQFLTC0.BIT.FCLKSEL0 = 3;		//IRQ�[�q�f�W�^���t�B���^�ݒ背�W�X�^0�@IRQ0�f�W�^���t�B���^�T���v�����O�N���b�N�ݒ�r�b�g�@00:PCLK�@01:PCLK8 10:PCLK32 11:PCLK64
	PORT3.PDR.BIT.B1 = 0;			//�|�[�g�ݒ�@P31����
	MPC.PWPR.BIT.PFSWE = 1;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 0;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	MPC.P30PFS.BIT.ISEL = 1;		//P30�[�q�@�\���䃌�W�X�^�@P30PFS�@0:IRQ���͒[�q�Ƃ��Ďg�p���Ȃ��@1:IRQ���͒[�q�Ƃ��Ďg�p
	MPC.PWPR.BIT.PFSWE = 0;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 1;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	PORT3.PMR.BIT.B1 = 1;			//�|�[�g���[�h���W�X�^�@�[�q���[�h����r�b�g�@0:�ėp���o�̓|�[�g�Ƃ��Ďg�p�@1:���Ӌ@��Ƃ��Ďg�p
	ICU.IRQCR[0].BIT.IRQMD = 1;		//IRQ�R���g���[�����W�X�^�@IRQ���o�ݒ�r�b�g�@00:Low 01:�����オ��G�b�W 10:������G�b�W 11:���G�b�W
	ICU.IR[066].BIT.IR = 0;			//���荞�ݗv�����W�X�^�@���荞�݃X�e�[�^�X�t���O�@0:���荞�ݗv���Ȃ��@1:���荞�ݗv������@�G�b�W���o�v���̏ꍇ0�̂݁@���x�����o�v���̏ꍇ��������NG
	ICU.IRQFLTE0.BIT.FLTEN2 = 1;		//IRQ�[�q�f�W�^���t�B���^�����W�X�^0�@IRQ0�f�W�^���t�B���^���r�b�g�@0:�����@1:�L��
	ICU.IER[0x02].BIT.IEN0 = 1;		//���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	*/
}

/*-------------------------------------------------------------------------------
	�֐���		: set_CMT
	���e	 	: �R���y�A�}�b�`�^�C�}���荞�ݐݒ�
	����		: ����
	�ߒl		: ����
	�X�V��		: 2021/04/21
-------------------------------------------------------------------------------*/
void set_CMT(void){
	SYSTEM.PRCR.WORD = 0xA502;		//�v���e�N�g���W�X�^ �v���e�N�g���W�X�^�̏���d�͒ጸ�@�\���������݋��@���8�r�b�g��A5�Œ�@����8�r�b�g�ɐݒ����������
	
	SYSTEM.MSTPCRA.BIT.MSTPA14 = 0;		//���W���[���X�g�b�v�R���g���[�����W�X�^A   ����d�͒ጸ�@�\��14bit�ڂ��w�肵�ăR���y�A�}�b�`�^�C�}���j�b�g1���W���[���X�g�b�v��Ԃ������@CMT0,CMT1
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;		//���W���[���X�g�b�v�R���g���[�����W�X�^A   ����d�͒ጸ�@�\��14bit�ڂ��w�肵�ăR���y�A�}�b�`�^�C�}���j�b�g0���W���[���X�g�b�v��Ԃ�����  CMT2,CMT3
	
	SYSTEM.PRCR.WORD = 0xA500;		//�v���e�N�g���W�X�^ �v���e�N�g���W�X�^�̏���d�͒ጸ�@�\���������݋֎~�@���8�r�b�g��A5�Œ�@����8�r�b�g�ɐݒ����������
	
	ICU.IER[0x03].BIT.IEN4 = 1;		//CMT0���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	ICU.IER[0x03].BIT.IEN5 = 1;		//CMT1���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	ICU.IER[0x03].BIT.IEN6 = 1;		//CMT2���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	ICU.IER[0x03].BIT.IEN7 = 1;		//CMT3���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	
	ICU.IPR[4].BYTE = 0x01;			//CMT0���荞�ݗv���v���C�I���e�B���W�X�^1�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	ICU.IPR[5].BYTE = 0x01;			//CMT1���荞�ݗv���v���C�I���e�B���W�X�^2�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	ICU.IPR[6].BYTE = 0x01;			//CMT2���荞�ݗv���v���C�I���e�B���W�X�^3�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	ICU.IPR[7].BYTE = 0x01;			//CMT3���荞�ݗv���v���C�I���e�B���W�X�^4�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	
	//CMT0
	//PCLKB=25MHz  s = 1/f = 0.04us
	//8�����̏ꍇ:0.04us * 8 = 0.32us
	CMT0.CMCR.BIT.CKS = 0;			//�R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�@�N���b�N�I���r�b�g�@CKS[2:0]�@00:PCLK8(8����) 01:PCLK32(32����) 10:PCLK128(128����) 11:PCLK512(512����)
	CMT0.CMCR.BIT.CMIE = 1;			//�R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�@�R���y�A�}�b�`���荞�݋��r�b�g�@0:�֎~�@1:����
	
	//CMT1
	//32�����̏ꍇ:0.04us * 32 = 1.28us
	CMT1.CMCR.BIT.CKS = 1;			//�R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�@�N���b�N�I���r�b�g�@CKS[2:0]�@00:PCLK8(8����) 01:PCLK32(32����) 10:PCLK128(128����) 11:PCLK512(512����)
	CMT1.CMCR.BIT.CMIE = 1;			//�R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�@�R���y�A�}�b�`���荞�݋��r�b�g�@0:�֎~�@1:����
	
	//CMT2
	//128�����̏ꍇ:0.04us * 128 = 5.12us
	CMT2.CMCR.BIT.CKS = 2;			//�R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�@�N���b�N�I���r�b�g�@CKS[2:0]�@00:PCLK8(8����) 01:PCLK32(32����) 10:PCLK128(128����) 11:PCLK512(512����)
	CMT2.CMCR.BIT.CMIE = 1;			//�R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�@�R���y�A�}�b�`���荞�݋��r�b�g�@0:�֎~�@1:����
	
	//CMT3
	//512�����̏ꍇ:0.04us * 512 = 20.48us
	CMT3.CMCR.BIT.CKS = 3;			//�R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�@�N���b�N�I���r�b�g�@CKS[2:0]�@00:PCLK8(8����) 01:PCLK32(32����) 10:PCLK128(128����) 11:PCLK512(512����)
	CMT3.CMCR.BIT.CMIE = 1;			//�R���y�A�}�b�`�^�C�}�R���g���[�����W�X�^�@�R���y�A�}�b�`���荞�݋��r�b�g�@0:�֎~�@1:����
	
	
	
	
	//CMT0
	CMT0.CMCNT = 0;				//�J�E���^���W�X�^������
	CMT0.CMCOR = 181 - 1;			//�J�E���g�ݒ�@0.32us * 3�J�E���g�@= 30us

	//CMT1
	CMT1.CMCNT = 0;				//�J�E���^���W�X�^������
	CMT1.CMCOR = 7810 - 1;			//�J�E���g�ݒ�@1.28us * 781�J�E���g�@= 10ms

	//CMT2
	CMT2.CMCNT = 0;				//�J�E���^���W�X�^������
	CMT2.CMCOR = 50 -1;			//�J�E���g�ݒ�@5.12us * 50�J�E���g�@= 256us

	//CMT3
	CMT3.CMCNT = 0;				//�J�E���^���W�X�^������
	CMT3.CMCOR = 50 -1;			//�J�E���g�ݒ�@20.48us * 50�J�E���g�@= 1024us

}

/*-------------------------------------------------------------------------------
	�֐���		: set_CMT
	���e	 	: �R���y�A�}�b�`�^�C�}���荞�ݐݒ�
	����		: ����
	�ߒl		: ����
	�X�V��		: 2021/04/21
-------------------------------------------------------------------------------*/
void set_MTU(void){
	SYSTEM.PRCR.WORD = 0xA502;		//�v���e�N�g���W�X�^�@�@�@�@�@�@�@�@�@�@�@�@�v���e�N�g���W�X�^�̏���d�͒ጸ�@�\���������݋��@���8�r�b�g��A5�Œ�@����8�r�b�g�ɐݒ����������
	
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;		//���W���[���X�g�b�v�R���g���[�����W�X�^A   ����d�͒ጸ�@�\��9bit�ڂ��w�肵�ă}���`�t�@���N�V�����^�C�}�p���X���j�b�g1���W���[���X�g�b�v��Ԃ������@CMT0,CMT1
	
	SYSTEM.PRCR.WORD = 0xA500;		//�v���e�N�g���W�X�^�@�@�@�@�@�@�@�@�@�@�@�@�v���e�N�g���W�X�^�̏���d�͒ጸ�@�\���������݋֎~�@���8�r�b�g��A5�Œ�@����8�r�b�g�ɐݒ����������
	//MTU0
	ICU.IER[0x0E].BIT.IEN2 = 1;		//MTU0A���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	ICU.IER[0x0E].BIT.IEN3 = 1;		//MTU0B���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	//MTU1
//	ICU.IER[0x0F].BIT.IEN1 = 1;		//MTU1A���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
//	ICU.IER[0x0F].BIT.IEN2 = 1;		//MTU1B���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	//MTU2
	ICU.IER[0x0F].BIT.IEN5 = 1;		//MTU2A���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	ICU.IER[0x0F].BIT.IEN6 = 1;		//MTU2B���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	//MTU3
//	ICU.IER[0x10].BIT.IEN1 = 1;		//MTU3A���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
//	ICU.IER[0x10].BIT.IEN2 = 1;		//MTU3B���荞�ݗv�������W�X�^�@���荞�ݗv�����r�b�g�@0:�֎~�@1:����
	
	//MTU0
	ICU.IPR[114].BYTE = 0x01;		//MTU0A���荞�ݗv���v���C�I���e�B���W�X�^�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	ICU.IPR[115].BYTE = 0x01;		//MTU0B���荞�ݗv���v���C�I���e�B���W�X�^�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	//MTU1
//	ICU.IPR[121].BYTE = 0x01;		//MTU1A���荞�ݗv���v���C�I���e�B���W�X�^�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
//	ICU.IPR[122].BYTE = 0x01;		//MTU1B���荞�ݗv���v���C�I���e�B���W�X�^�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	//MTU2
	ICU.IPR[125].BYTE = 0x01;		//MTU2A���荞�ݗv���v���C�I���e�B���W�X�^�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	ICU.IPR[126].BYTE = 0x01;		//MTU2B���荞�ݗv���v���C�I���e�B���W�X�^�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	//MTU3
//	ICU.IPR[129].BYTE = 0x01;		//MTU3A���荞�ݗv���v���C�I���e�B���W�X�^�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
//	ICU.IPR[130].BYTE = 0x01;		//MTU3B���荞�ݗv���v���C�I���e�B���W�X�^�@���荞�ݗD�惌�x���ݒ�r�b�g�@IPR[3:0] 0�`15(�ō�)���x��
	
	//MTU0
	PORTB.PDR.BIT.B3 = 1;			//�|�[�gB3���o�͐ݒ�@PWM�o�͐�
	PORTB.PMR.BIT.B3 = 0;			//�|�[�gB3��ėp���o�̓|�[�g�Ƃ��Đݒ�
//	MPC.PWPR.BYTE = 0x40;
	//�������݃v���e�N�g���W�X�^��B0WI����������Ȃ���PFSWE�͏��������Ȃ�
	MPC.PWPR.BIT.B0WI  = 0;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~	
	MPC.PWPR.BIT.PFSWE = 1;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	
	MPC.PB3PFS.BIT.PSEL = 1;		//PB3�[�q�@�\���䃌�W�X�^�@PB3PFS�@0:MTIOC0A�[�q�Ƃ��Ďg�p���Ȃ��@1:MTIOC0A�[�q�Ƃ��Ďg�p

	MPC.PWPR.BIT.PFSWE = 0;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 1;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	PORTB.PMR.BIT.B3 = 1;			//�|�[�gB3�����Ӌ@��|�[�g�Ƃ��Đݒ�
	
	MTU0.TMDR.BIT.MD = 2;   		//MTU�@�^�C�����[�h���W�X�^�@���[�h�I���r�b�g�@PWM���[�h1
	MTU0.TIORH.BIT.IOA = 2;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOA �����o�͂�Low �R���y�A�}�b�`��Low
	MTU0.TIORH.BIT.IOB = 1;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOB �����o�͂�Low �R���y�A�}�b�`��High
	MTU0.TIORL.BYTE = 0x00;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOA&IOB �o�͋֎~
	MTU0.TCR.BIT.TPSC = 2;			//MTU�@�^�C�}�R���g���[�����W�X�^ �^�C�}�v���X�P�[���I���r�b�g 0:25.000MHz=0.04us 1:12.500MHz=0.16us 2:15.625MHz=0.64us 3:0.390MHz=2.56us
	MTU0.TCR.BIT.CCLR = 1;			//MTU�@�^�C�}�R���g���[�����W�X�^�@�J�E���^���Z�b�g�I���r�b�g�@MTU0_B���R���y�A�}�b�`�ŃN���A
	MTU0.TIER.BIT.TGIEA = 1;		//MTU�@�^�C�}���荞�݋����W�X�^�@TGR���荞�݋���A�r�b�g�@0:�֎~�@1:����
	MTU0.TIER.BIT.TGIEB = 1;		//MTU�@�^�C�}���荞�݋����W�X�^�@TGR���荞�݋���B�r�b�g�@0:�֎~�@1:����
	
	MTU0.TCNT = 0;				//MTU�@�^�C�}�J�E���^�@������
	//���g���ݒ�@1 / (0.64us * 12500) = 125Hz 
	MTU0.TGRA =  MTU0_TGRA;			//MTU�@�^�C�}�W�F�l�������W�X�^�@�A�E�g�v�b�g�R���y�A/�C���v�b�g�L���v�`�� �R���y�A�}�b�`�@MTU.TPSC*MTU_TGRA ON���ԁ@0us
	MTU0.TGRB =  0;			//MTU�@�^�C�}�W�F�l�������W�X�^�@�A�E�g�v�b�g�R���y�A/�C���v�b�g�L���v�`�� �R���y�A�}�b�`�@MTU.TPSC*MTU_TGRA*MTU_TGRB�@�L�����A(����) 0.64us*31250=20ms
	
	//MTU1
	PORTE.PDR.BIT.B4 = 1;			//�|�[�gE4���o�͐ݒ�@PWM�o�͐�
	PORTE.PMR.BIT.B4 = 0;			//�|�[�gE4��ėp���o�̓|�[�g�Ƃ��Đݒ�
	MPC.PWPR.BIT.PFSWE = 1;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 0;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	MPC.PE4PFS.BIT.PSEL = 1;		//PE4�[�q�@�\���䃌�W�X�^�@PB3PFS�@0:MTIOC0A�[�q�Ƃ��Ďg�p���Ȃ��@1:MTIOC0A�[�q�Ƃ��Ďg�p
	MPC.PWPR.BIT.PFSWE = 0;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 1;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	PORTE.PMR.BIT.B4 = 1;			//�|�[�gB3�����Ӌ@��|�[�g�Ƃ��Đݒ�
	
	MTU1.TMDR.BIT.MD = 2;			//MTU�@�^�C�����[�h���W�X�^�@���[�h�I���r�b�g�@PWM���[�h1
	MTU1.TIOR.BIT.IOA = 1;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOA �����o�͂�Low �R���y�A�}�b�`��Low
	MTU1.TIOR.BIT.IOB = 2;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOB �����o�͂�Low �R���y�A�}�b�`��High
	MTU1.TCR.BIT.TPSC = 2;			//MTU�@�^�C�}�R���g���[�����W�X�^ �^�C�}�v���X�P�[���I���r�b�g 0:25.000MHz=0.04us 1:12.500MHz=0.08us 2:15.625MHz=0.64us 3:0.390MHz=2.56us
	MTU1.TCR.BIT.CCLR = 2;			//MTU�@�^�C�}�R���g���[�����W�X�^�@�J�E���^���Z�b�g�I���r�b�g�@MTU0_B���R���y�A�}�b�`�ŃN���A
	MTU1.TIER.BIT.TGIEA = 1;		//MTU�@�^�C�}���荞�݋����W�X�^�@TGR���荞�݋���A�r�b�g�@0:�֎~�@1:����
	MTU1.TIER.BIT.TGIEB = 1;		//MTU�@�^�C�}���荞�݋����W�X�^�@TGR���荞�݋���B�r�b�g�@0:�֎~�@1:����
	MTU1.TCNT = 0;				//MTU�@�^�C�}�J�E���^�@������
	MTU1.TGRA = 0;				//MTU�@�^�C�}�W�F�l�������W�X�^�@�A�E�g�v�b�g�R���y�A/�C���v�b�g�L���v�`�� �R���y�A�}�b�`�@MTU.TPSC*MTU_TGRA ON���ԁ@0us
	MTU1.TGRB = 31250;			//MTU�@�^�C�}�W�F�l�������W�X�^�@�A�E�g�v�b�g�R���y�A/�C���v�b�g�L���v�`�� �R���y�A�}�b�`�@MTU.TPSC*MTU_TGRA*MTU_TGRB�@�L�����A(����) 0.64us*31250=20ms
	
	//MTU2 �����g�Z���T�@�g���K�p�p���X
	PORTB.PDR.BIT.B5 = 1;			//�|�[�gB5���o�͐ݒ�@PWM�o�͐�
	PORTB.PMR.BIT.B5 = 0;			//�|�[�gB5��ėp���o�̓|�[�g�Ƃ��Đݒ�
	MPC.PWPR.BIT.B0WI  = 0;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	MPC.PWPR.BIT.PFSWE = 1;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	
	MPC.PB5PFS.BIT.PSEL = 1;		//PB5�[�q�@�\���䃌�W�X�^�@PB3PFS�@0:MTIOC0A�[�q�Ƃ��Ďg�p���Ȃ��@1:MTIOC0A�[�q�Ƃ��Ďg�p
	
	MPC.PWPR.BIT.PFSWE = 0;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 1;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	PORTB.PMR.BIT.B5 = 1;			//�|�[�gB5�����Ӌ@��|�[�g�Ƃ��Đݒ�
	
	MTU2.TMDR.BIT.MD = 2;			//MTU�@�^�C�����[�h���W�X�^�@���[�h�I���r�b�g�@PWM���[�h1
	MTU2.TIOR.BIT.IOA = 6;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOA �����o�͂�Low �R���y�A�}�b�`��Low
	MTU2.TIOR.BIT.IOB = 1;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOB �����o�͂�Low �R���y�A�}�b�`��High
	MTU2.TCR.BIT.TPSC = 2;			//MTU�@�^�C�}�R���g���[�����W�X�^ �^�C�}�v���X�P�[���I���r�b�g 0:25.000MHz=0.04us 1:12.500MHz=0.08us 2:15.625MHz=0.64us 3:0.390MHz=2.56us
	MTU2.TCR.BIT.CCLR = 1;			//MTU�@�^�C�}�R���g���[�����W�X�^�@�J�E���^���Z�b�g�I���r�b�g�@MTU0_A���R���y�A�}�b�`�ŃN���A
	MTU2.TIER.BIT.TGIEA = 1;		//MTU�@�^�C�}���荞�݋����W�X�^�@TGR���荞�݋���A�r�b�g�@0:�֎~�@1:����
	MTU2.TIER.BIT.TGIEB = 1;		//MTU�@�^�C�}���荞�݋����W�X�^�@TGR���荞�݋���B�r�b�g�@0:�֎~�@1:����
	MTU2.TCNT = 0;				//MTU�@�^�C�}�J�E���^�@������
	MTU2.TGRA = 15000;			//MTU�@�^�C�}�W�F�l�������W�X�^�@�A�E�g�v�b�g�R���y�A/�C���v�b�g�L���v�`�� �R���y�A�}�b�`�@MTU.TPSC*MTU_TGRA ON���ԁ@0us
	MTU2.TGRB = 15;				//MTU�@�^�C�}�W�F�l�������W�X�^�@�A�E�g�v�b�g�R���y�A/�C���v�b�g�L���v�`�� �R���y�A�}�b�`�@MTU.TPSC*MTU_TGRA*MTU_TGRB�@�L�����A(����) 0.64us*31250=20ms
	
	//MTU3
	PORT1.PDR.BIT.B4 = 1;			//�|�[�g14���o�͐ݒ�@PWM�o�͐�
	PORT1.PMR.BIT.B4 = 0;			//�|�[�g14��ėp���o�̓|�[�g�Ƃ��Đݒ�
	MPC.PWPR.BIT.PFSWE = 1;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 0;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	MPC.P14PFS.BIT.PSEL = 1;		//P14�[�q�@�\���䃌�W�X�^�@PB3PFS�@0:MTIOC0A�[�q�Ƃ��Ďg�p���Ȃ��@1:MTIOC0A�[�q�Ƃ��Ďg�p
	MPC.PWPR.BIT.PFSWE = 0;			//�������݃v���e�N�g���W�X�^�@PFS���W�X�^�̏������݋��r�b�g�@  0:�֎~�@1:����
	MPC.PWPR.BIT.B0WI  = 1;			//�������݃v���e�N�g���W�X�^�@PFSWE���W�X�^�̏������݋��r�b�g�@0:����  1:�֎~
	PORT1.PMR.BIT.B4 = 1;			//�|�[�gB3�����Ӌ@��|�[�g�Ƃ��Đݒ�
	
	MTU3.TMDR.BIT.MD = 2;			//MTU�@�^�C�����[�h���W�X�^�@���[�h�I���r�b�g�@PWM���[�h1
	MTU3.TIORH.BIT.IOA = 1;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOA �����o�͂�Low �R���y�A�}�b�`��Low
	MTU3.TIORH.BIT.IOB = 2;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOB �����o�͂�Low �R���y�A�}�b�`��High
	MTU3.TIORL.BYTE = 0x00;			//MTU�@�^�C�}I/O�R���g���[�����W�X�^�@IOA&IOB �o�͋֎~
	MTU3.TCR.BIT.TPSC = 2;			//MTU�@�^�C�}�R���g���[�����W�X�^ �^�C�}�v���X�P�[���I���r�b�g 0:25.000MHz=0.04us 1:12.500MHz=0.08us 2:15.625MHz=0.64us 3:0.390MHz=2.56us
	MTU3.TCR.BIT.CCLR = 2;			//MTU�@�^�C�}�R���g���[�����W�X�^�@�J�E���^���Z�b�g�I���r�b�g�@MTU0_B���R���y�A�}�b�`�ŃN���A
	MTU3.TIER.BIT.TGIEA = 1;		//MTU�@�^�C�}���荞�݋����W�X�^�@TGR���荞�݋���A�r�b�g�@0:�֎~�@1:����
	MTU3.TIER.BIT.TGIEB = 1;		//MTU�@�^�C�}���荞�݋����W�X�^�@TGR���荞�݋���B�r�b�g�@0:�֎~�@1:����
	MTU3.TCNT = 0;				//MTU�@�^�C�}�J�E���^�@������
	MTU3.TGRA = 0;				//MTU�@�^�C�}�W�F�l�������W�X�^�@�A�E�g�v�b�g�R���y�A/�C���v�b�g�L���v�`�� �R���y�A�}�b�`�@MTU.TPSC*MTU_TGRA ON���ԁ@0us
	MTU3.TGRB = 31250;			//MTU�@�^�C�}�W�F�l�������W�X�^�@�A�E�g�v�b�g�R���y�A/�C���v�b�g�L���v�`�� �R���y�A�}�b�`�@MTU.TPSC*MTU_TGRA*MTU_TGRB�@�L�����A(����) 0.64us*31250=20ms
}

/*-------------------------------------------------------------------------------
	�֐���		: set_I2C
	���e	 	: I2C�̏����ݒ�
	����		: ����
	�ߒl		: ����
	�X�V��		: 2017/08/16
-------------------------------------------------------------------------------*/
void set_I2C_intr(void){		
	
//	int i;
	
	/* I2CӼޭ�ٗL���� */
	SYSTEM.PRCR.WORD = 0xA502;						// �v���e�N�g����
	SYSTEM.MSTPCRB.BIT.MSTPB21 = 0;						// I2C(RIIC0) ���W���[���X�g�b�v ����
	SYSTEM.PRCR.WORD = 0xA500;						// �v���e�N�g�ݒ�
	
	PORT1.PDR.BIT.B6 = 0;							// �|�[�g�ݒ� P16 SCL-DS ����
	PORT1.PDR.BIT.B7 = 0;							// �|�[�g�ݒ� P17 SDA-DS ����
	
	PORT1.PMR.BIT.B6 = 0;							// �|�[�g�ݒ� P16 �ėp���o�̓|�[�g
	PORT1.PMR.BIT.B7 = 0;							// �|�[�g�ݒ� P17 �ėp���o�̓|�[�g
	
	MPC.PWPR.BIT.B0WI = 0;							//  PWPR�v���e�N�g���W�X�^  B0WI  ����		
	MPC.PWPR.BIT.PFSWE = 1;							//  PWPR�v���e�N�g���W�X�^  PFSWE ����		
	MPC.P16PFS.BYTE = 0x0F;							//  P16 �� SCL �[�q�Ƃ��ė��p����
	MPC.P17PFS.BYTE = 0x0F;							//  P17 �� SDA �[�q�Ƃ��ė��p����
	MPC.PWPR.BIT.PFSWE = 0;							//  PWPR�v���e�N�g���W�X�^  PFSWE ����
	MPC.PWPR.BIT.B0WI = 1;							//  PWPR�v���e�N�g���W�X�^  B0WI  ����
	
	PORT1.PMR.BIT.B6 = 1;							// �|�[�g�ݒ� SCL ���Ӌ@��|�[�g
	PORT1.PMR.BIT.B7 = 1;							// �|�[�g�ݒ� SDA ���Ӌ@��|�[�g
	
//  I2C �����ݒ�	
	RIIC0.ICCR1.BIT.ICE = 0;						// SCL�ASDA�[�q ����֎~
	RIIC0.ICCR1.BIT.IICRST=1;						// RIIC���Z�b�g
	RIIC0.ICCR1.BIT.ICE = 1;						// �������Z�b�g
	
	// SAR0 �ݒ�
	RIIC0.SARU0.BIT.FS = 0;							// 7�r�b�g�A�h���X�t�H�[�}�b�g�I��
	RIIC0.SARL0.BIT.SVA = 0x6B;						// �X���[�u�A�h���X���W�X�^ 0x6B

	// SAR1 �ݒ�
	RIIC0.SARU1.BIT.FS = 0;							// 7�r�b�g�A�h���X�t�H�[�}�b�g�I��
	RIIC0.SARL1.BIT.SVA = 0x1D;						// �X���[�u�A�h���X���W�X�^	


	RIIC0.ICSER.BIT.SAR0E = 1;						// SARL0�ASARU0�̐ݒ�l 	 �L��
	RIIC0.ICSER.BIT.SAR1E = 1;						// SARL1�ASARU1�̐ݒ�l 	 �L��
	RIIC0.ICSER.BIT.GCAE = 0;						// �W�F�l�����R�[���A�h���X�@����
	
	/*
	RIIC0.ICMR3.BIT.ACKWP = 1;						// NACk/ACK�M���̑��M�I������(RIIC0.ICMR3.BIT.ACKBT�ւ̏������݋���)
	
	
	RIIC0.ICMR1.BIT.CKS = 2;						// �ʐM�r�b�g���[�g��ݒ� pclk 25MHz�� b010�ݒ� (100kbps)

	RIIC0.ICBRH.BYTE = 0xF8 ;						// ICBRH
	RIIC0.ICBRL.BYTE = 0xFD ;						// ICBRL	
	*/
	
    /* Set transfer bit rate : 100kbps (PCLK = 25MHz) */
//    RIIC0.ICMR1.BIT.CKS = 2; 	/* Internal Reference Clock: PCLK/4 clock */
//    RIIC0.ICBRH.BIT.BRH = 24;	/* Set the High-level period of SCL clock */
//    RIIC0.ICBRL.BIT.BRL = 29; /* Set the Low-level period of SCL clock */

    /* Set transfer bit rate : 400kbps (PCLK = 25MHz) */
    RIIC0.ICMR1.BIT.CKS = 1; 	/* Internal Reference Clock: PCLK/2 clock */
    RIIC0.ICBRH.BIT.BRH = 24;	/* Set the High-level period of SCL clock */
    RIIC0.ICBRL.BIT.BRL = 29; 	/* Set the Low-level period of SCL clock */	
	
	
	/* disable all address detection. Master mode only. */
    RIIC0.ICSER.BYTE = 0x00;

	/* ACKWP is protect bit for ACKBT */
    RIIC0.ICMR3.BIT.ACKWP = 1;        						// NACk/ACK�M���̑��M�I������(RIIC0.ICMR3.BIT.ACKBT�ւ̏������݋���)
    RIIC0.ICCR1.BIT.IICRST = 0;       						// RIIC���Z�b�g����	
	
/*	
	ICMR2�AICMR3��ݒ�							// �K�v�ɉ����Đݒ�	
	ICMR2.TMWE=1								// �K�v�ɉ����Đݒ�  �^�C���A�E�g�����J�E���^�������݋���	
	TMOCNTL=00h								// �^�C���A�E�g�����J�E���^�̏�����	
	TMOCNTU=00h								// �^�C���A�E�g�����J�E���^�̏�����			
	ICFER.TMOE=1				 				// �^�C���A�E�g�@�\�L��(�g�p����ꍇ�L��)
	ICFER��ݒ�
*/	
/*
//	ICIER �̐ݒ�								// ���荞�݋���ݒ�
	RIIC0.ICIER.BIT.TMOIE = 1;						// �^�C���A�E�g���荞�݁iTMOI�j�̋���
	RIIC0.ICIER.BIT.ALIE  = 1;						// �A�[�r�g���[�V�������X�g���荞�݁iALI�j�̋���
	RIIC0.ICIER.BIT.STIE  = 1;						// �X�^�[�g�R���f�B�V�������o���荞�݁iSTI�j�̋���	
	RIIC0.ICIER.BIT.SPIE  = 1;						// �X�g�b�v�R���f�B�V�������o���荞�݁iSPI�j�̋���
	RIIC0.ICIER.BIT.NAKIE = 1;						// NACK��M���荞�݁iNAKI�j�̋���
	RIIC0.ICIER.BIT.RIE   = 1;						// ��M�f�[�^�t�����荞�݁iRXI�j�̋���
	RIIC0.ICIER.BIT.TEIE  = 1;						// ���M�I�����荞�݁iTEI�j�̋���
	RIIC0.ICIER.BIT.TIE   = 1;						// ���M�f�[�^�G���v�e�B���荞�݁iTXI�j�̋���
*/

//	RIIC0.ICFER.BIT.NFE = 1;						// �f�W�^���m�C�Y�t�B���^��H���g�p����
//	RIIC0.ICCR1.BIT.IICRST = 0;						// IICRST �������Z�b�g����

	RIIC0.ICCR1.BIT.ICE = 1;						// SCL�ASDA�[�q ���싖��
		
/*	
	RIIC0.ICCR2.BIT.ST=1;
	while(!RIIC0.ICCR2.BIT.ST){}
	
	RIIC0.ICDRT=0x0A;
*/
	return;	
}

/*-------------------------------------------------------------------------------
	�֐���		: set_SCI1
	���e	 	: SCI1�̏����ݒ�
	����		: ����
	�ߒl		: ����
	�X�V��		: 2017/08/16
-------------------------------------------------------------------------------*/
void SCI1_set(void){
	
	int i;
	
	/* SCI1Ӽޭ�ٗL���� */
	SYSTEM.PRCR.WORD = 0xA502;									// �v���e�N�g����
	SYSTEM.MSTPCRB.BIT.MSTPB30 = 0;									// SCI1 ���W���[���X�g�b�v ����
	SYSTEM.PRCR.WORD = 0xA500;									// �v���e�N�g�ݒ�
	
	PORT3.PDR.BIT.B0 = 0;										// �|�[�g�ݒ� RXD1 ����:0	
	PORT2.PDR.BIT.B6 = 0;										// �|�[�g�ݒ� TXD1 �o��:1
	
	PORT3.PMR.BIT.B0 = 0;										// �|�[�g�ݒ� RXD1 �ėp���o�̓|�[�g
	PORT2.PMR.BIT.B6 = 0;										// �|�[�g�ݒ� TXD1 �ėp���o�̓|�[�g
	
	MPC.PWPR.BIT.B0WI = 0;										//  PWPR�v���e�N�g���W�X�^  B0WI  ����		
	MPC.PWPR.BIT.PFSWE = 1;										//  PWPR�v���e�N�g���W�X�^  PFSWE ����		
	MPC.P30PFS.BYTE = 0x0A;										//  P30 �� TXD1 �[�q�Ƃ��ė��p����
	MPC.P26PFS.BYTE = 0x0A;										//  P26 �� RXD1 �[�q�Ƃ��ė��p����
	MPC.PWPR.BIT.PFSWE = 0;										//  PWPR�v���e�N�g���W�X�^  PFSWE ����
	MPC.PWPR.BIT.B0WI = 1;										//  PWPR�v���e�N�g���W�X�^  B0WI  ����
	
	PORT3.PMR.BIT.B0 = 1;										// �|�[�g�ݒ� RXD1 ���Ӌ@��|�[�g
	PORT2.PMR.BIT.B6 = 1;										// �|�[�g�ݒ� TXD1 ���Ӌ@��|�[�g
	
	/* �رٺ��۰�ڼ޽������� */
	SCI1.SCR.BYTE     = 0x00 ;	
	
	/* �������� 1:���� 0:�֎~ */

	ICU.IER[0x1B].BIT.IEN2 = 0;									// ERI ��M�G���[����	�֎~	
	ICU.IER[0x1B].BIT.IEN3 = 0;									// RXI ��M����		�֎~
	ICU.IER[0x1B].BIT.IEN4 = 0;									// TXI ���M�I������	�֎~
	ICU.IER[0x1B].BIT.IEN5 = 0;									// TEI ���M����		�֎~	
	
	
	/* �ʐM�v���g�R���ݒ� */	
	SCI1.SCR.BIT.CKE  = 0;										// �����ު�ڰ��g�p�A�o�͖���
	SCI1.SMR.BIT.STOP = 0;										// �į���ޯĒ� = 1
	SCI1.SMR.BIT.PM   = 0;										// ���è EVEN
	SCI1.SMR.BIT.PE   = 0;										// ���è����
	SCI1.SMR.BIT.CHR  = 0;										// �ް��� 8bit
	SCI1.SMR.BIT.CM   = 0;										// ��������	
	SCI1.SMR.BIT.CKS  = 0;										// 115200bps�ݒ� n �ݒ�
	SCI1.BRR 	  = 6;										// 115200bps�ݒ� N �ݒ�

	ICU.IPR[218].BIT.IPR = 0xF;									// SCI1 ���荞�ݗD�惌�x���ݒ�	
		
	/* 1bit���҂� */
	for(i=0; i<100000; i++);
	
	ICU.IR[ IR_SCI1_ERI1 ].BIT.IR = 0;								// ERI1 ���荞�ݗv���N���A	
	ICU.IR[ IR_SCI1_RXI1 ].BIT.IR = 0;								// RXI1 ���荞�ݗv���N���A	
	ICU.IR[ IR_SCI1_TXI1 ].BIT.IR = 0;								// TXI1 ���荞�ݗv���N���A		
	ICU.IR[ IR_SCI1_TEI1 ].BIT.IR = 0;								// TEI1 ���荞�ݗv���N���A
	
	/* �ʐM��Ԑݒ� */
	SCI1.SCR.BIT.RIE   = 1;										// ��M�Ǝ�M�G���[����			�L��
	SCI1.SCR.BIT.RE    = 1;										// ��M					�L��
	SCI1.SCR.BIT.TE    = 1;										// ���M					�L��
	SCI1.SCR.BIT.TIE   = 1;										// ���M����				�L��
	SCI1.SCR.BIT.TEIE  = 0;										// ���M�I������				����

	ICU.IER[0x1B].BIT.IEN2 = 1;									// ERI ��M�G���[����	����
	ICU.IER[0x1B].BIT.IEN3 = 1;									// RXI ��M����			����
	ICU.IER[0x1B].BIT.IEN4 = 1;									// TXI ���M����			����
	ICU.IER[0x1B].BIT.IEN5 = 1;									// TEI ���M�I������		����

	SCI1.SSR.BIT.ORER  = 0; 									// ORER�G���[���N���A
	SCI1.SSR.BIT.FER   = 0; 									// FER�G���[���N���A
	SCI1.SSR.BIT.PER   = 0; 									// PER�G���[���N���A

}

/*-------------------------------------------------------------------------------
	�֐���		: set_SCI5
	���e	 	: SCI5�̏����ݒ�
	����		: ����
	�ߒl		: ����
	�X�V��		: 2017/08/16
-------------------------------------------------------------------------------*/
void set_SCI5(void){	
	
	int i;
	
	/* SCI5Ӽޭ�ٗL���� */
	SYSTEM.PRCR.WORD = 0xA502;						// �v���e�N�g����
	SYSTEM.MSTPCRB.BIT.MSTPB26 = 0;						// SCI5 ���W���[���X�g�b�v ����
	SYSTEM.PRCR.WORD = 0xA500;						// �v���e�N�g�ݒ�
	
	PORTC.PDR.BIT.B2 = 0;							// �|�[�g�ݒ� RXD5 ����
	PORTC.PDR.BIT.B3 = 0;							// �|�[�g�ݒ� TXD5 �o��
	
	PORTC.PMR.BIT.B2 = 0;							// �|�[�g�ݒ� RXD5 �ėp���o�̓|�[�g
	PORTC.PMR.BIT.B3 = 0;							// �|�[�g�ݒ� TXD5 �ėp���o�̓|�[�g
	
	MPC.PWPR.BIT.B0WI = 0;							//  PWPR�v���e�N�g���W�X�^  B0WI  ����		
	MPC.PWPR.BIT.PFSWE = 1;							//  PWPR�v���e�N�g���W�X�^  PFSWE ����		
	MPC.PC2PFS.BYTE = 0x0A;							//  PC2 �� RXD5 �[�q�Ƃ��ė��p����
	MPC.PC3PFS.BYTE = 0x0A;							//  PC3 �� TXD5 �[�q�Ƃ��ė��p����
	MPC.PWPR.BIT.PFSWE = 0;							//  PWPR�v���e�N�g���W�X�^  PFSWE ����
	MPC.PWPR.BIT.B0WI = 1;							//  PWPR�v���e�N�g���W�X�^  B0WI  ����
	
	PORTC.PMR.BIT.B2 = 1;							// �|�[�g�ݒ� RXD5 ���Ӌ@��|�[�g
	PORTC.PMR.BIT.B3 = 1;							// �|�[�g�ݒ� TXD5 ���Ӌ@��|�[�g
	
	/* �رٺ��۰�ڼ޽������� */
	SCI5.SCR.BYTE     = 0x00 ;	
	
	/* �������� 1:���� 0:�֎~ */

	ICU.IER[0x1B].BIT.IEN6 = 0;						// ERI ��M�G���[����		�֎~	
	ICU.IER[0x1B].BIT.IEN7 = 0;						// RXI ��M����			�֎~
	ICU.IER[0x1C].BIT.IEN0 = 0;						// TXI ���M�I������		�֎~
	ICU.IER[0x1C].BIT.IEN1 = 0;						// TEI ���M����			�֎~	


	/* �ʐM�v���g�R���ݒ� */	
	SCI5.SCR.BIT.CKE  = 0;							// �����ު�ڰ��g�p�A�o�͖���
	SCI5.SMR.BIT.STOP = 0;							// �į���ޯĒ� = 1
	SCI5.SMR.BIT.PM   = 0;							// ���è EVEN
	SCI5.SMR.BIT.PE   = 0;							// ���è����
	SCI5.SMR.BIT.CHR  = 0;							// �ް��� 8bit
	SCI5.SMR.BIT.CM   = 0;							// ��������	
	SCI5.SMR.BIT.CKS  = 0;							// 115200bps�ݒ� n �ݒ�
	SCI5.BRR 	  	  = 6;						// 115200bps�ݒ� N �ݒ�

	ICU.IPR[222].BIT.IPR = 0xF;						// SCI5 ���荞�ݗD�惌�x���ݒ�	
		
	/* 1bit���҂� */
	for(i=0; i<100000; i++);
	
	ICU.IR[ IR_SCI5_ERI5 ].BIT.IR = 0;					// ERI5 ���荞�ݗv���N���A	
	ICU.IR[ IR_SCI5_RXI5 ].BIT.IR = 0;					// RXI5 ���荞�ݗv���N���A	
	ICU.IR[ IR_SCI5_TXI5 ].BIT.IR = 0;					// TXI5 ���荞�ݗv���N���A		
	ICU.IR[ IR_SCI5_TEI5 ].BIT.IR = 0;					// TEI5 ���荞�ݗv���N���A
	
	/* �ʐM��Ԑݒ� */
	SCI5.SCR.BIT.RIE   = 1;							// ��M�Ǝ�M�G���[����	�L��
	SCI5.SCR.BIT.RE    = 1;							// ��M					�L��
	SCI5.SCR.BIT.TE    = 1;							// ���M					�L��
	SCI5.SCR.BIT.TIE   = 1;							//���M����				�L��
	SCI5.SCR.BIT.TEIE  = 0;							// ���M�I������			����

	ICU.IER[0x1B].BIT.IEN6 = 1;						// ERI ��M�G���[����	����
	ICU.IER[0x1B].BIT.IEN7 = 1;						// RXI ��M����			����
//	ICU.IER[0x1C].BIT.IEN0 = 1;						// TXI ���M����			����
//	ICU.IER[0x1C].BIT.IEN1 = 1;						// TEI ���M�I������		����

	SCI5.SSR.BIT.ORER  = 0; 						// ORER�G���[���N���A
	SCI5.SSR.BIT.FER   = 0; 						// FER�G���[���N���A
	SCI5.SSR.BIT.PER   = 0; 						// PER�G���[���N���A
	
}

/*-------------------------------------------------------------------------------
	�֐���		: set_SCI6
	���e	 	: SCI1�̏����ݒ�
	����		: ����
	�ߒl		: ����
	�X�V��		: 20121/09/6
-------------------------------------------------------------------------------*/
void SCI6_set(void){
	
	int i;
	
	/* SCI6Ӽޭ�ٗL���� */
	SYSTEM.PRCR.WORD = 0xA502;									// �v���e�N�g����
	SYSTEM.MSTPCRB.BIT.MSTPB25 = 0;									// SCI6 ���W���[���X�g�b�v ����
	SYSTEM.PRCR.WORD = 0xA500;									// �v���e�N�g�ݒ�
	
	PORTB.PDR.BIT.B0 = 0;										// �|�[�g�ݒ� RXD6 ����	
	PORTB.PDR.BIT.B1 = 0;										// �|�[�g�ݒ� TXD6 �o��
	
	PORTB.PMR.BIT.B0 = 0;										// �|�[�g�ݒ� RXD6 �ėp���o�̓|�[�g
	PORTB.PMR.BIT.B1 = 0;										// �|�[�g�ݒ� TXD6 �ėp���o�̓|�[�g
	
	MPC.PWPR.BIT.B0WI = 0;										//  PWPR�v���e�N�g���W�X�^  B0WI  ����		
	MPC.PWPR.BIT.PFSWE = 1;										//  PWPR�v���e�N�g���W�X�^  PFSWE ����		
	MPC.PB1PFS.BYTE = 0x0A;										//  PB1 �� TXD6 �[�q�Ƃ��ė��p����
	MPC.PB0PFS.BYTE = 0x0A;										//  PB0 �� RXD6 �[�q�Ƃ��ė��p����
	MPC.PWPR.BIT.PFSWE = 0;										//  PWPR�v���e�N�g���W�X�^  PFSWE ����
	MPC.PWPR.BIT.B0WI = 1;										//  PWPR�v���e�N�g���W�X�^  B0WI  ����
	
	PORTB.PMR.BIT.B0 = 1;										// �|�[�g�ݒ� RXD6 ���Ӌ@��|�[�g
	PORTB.PMR.BIT.B1 = 1;										// �|�[�g�ݒ� TXD6 ���Ӌ@��|�[�g
	
	/* �رٺ��۰�ڼ޽������� */
	SCI6.SCR.BYTE     = 0x00 ;	
	
	/* �������� 1:���� 0:�֎~ */

	ICU.IER[0x1C].BIT.IEN2 = 0;									// ERI6 ��M�G���[����	�֎~	
	ICU.IER[0x1C].BIT.IEN3 = 0;									// RXI6 ��M����		�֎~
	ICU.IER[0x1C].BIT.IEN4 = 0;									// TXI6 ���M�I������	�֎~
	ICU.IER[0x1C].BIT.IEN5 = 0;									// TEI6 ���M����		�֎~	
	
	
	/* �ʐM�v���g�R���ݒ� */	
	SCI6.SCR.BIT.CKE  = 0;										// �����ު�ڰ��g�p�A�o�͖���
	SCI6.SMR.BIT.STOP = 0;										// �į���ޯĒ� = 1
	SCI6.SMR.BIT.PM   = 0;										// ���è EVEN
	SCI6.SMR.BIT.PE   = 0;										// ���è����
	SCI6.SMR.BIT.CHR  = 0;										// �ް��� 8bit
	SCI6.SMR.BIT.CM   = 0;										// ��������	
	SCI6.SMR.BIT.CKS  = 0;										// 115200bps�ݒ� n �ݒ� PCLK�N���b�N
	SCI6.BRR 	  = 6;										// 115200bps�ݒ� N �ݒ�

	ICU.IPR[226].BIT.IPR = 0xF;									// SCI6 ���荞�ݗD�惌�x���ݒ�	
		
	/* 1bit���҂� */
	for(i=0; i<100000; i++);
	
	ICU.IR[ IR_SCI6_ERI6 ].BIT.IR = 0;								// ERI6 ���荞�ݗv���N���A	
	ICU.IR[ IR_SCI6_RXI6 ].BIT.IR = 0;								// RXI6 ���荞�ݗv���N���A	
	ICU.IR[ IR_SCI6_TXI6 ].BIT.IR = 0;								// TXI6 ���荞�ݗv���N���A		
	ICU.IR[ IR_SCI6_TEI6 ].BIT.IR = 0;								// TEI6 ���荞�ݗv���N���A
	
	/* �ʐM��Ԑݒ� */
	SCI6.SCR.BIT.RIE   = 1;										// ��M�Ǝ�M�G���[����			�L��
	SCI6.SCR.BIT.RE    = 1;										// ��M					�L��
	SCI6.SCR.BIT.TE    = 1;										// ���M					�L��
	SCI6.SCR.BIT.TIE   = 1;										// ���M����				�L��
	SCI6.SCR.BIT.TEIE  = 0;										// ���M�I������				����

	ICU.IER[0x1C].BIT.IEN2 = 1;									// ERI6 ��M�G���[����			����
	ICU.IER[0x1C].BIT.IEN3 = 1;									// RXI6 ��M����			����
	ICU.IER[0x1C].BIT.IEN4 = 1;									// TXI6 ���M����			����
	ICU.IER[0x1C].BIT.IEN5 = 1;									// TEI6 ���M�I������			����

	SCI6.SSR.BIT.ORER  = 0; 									// ORER�G���[���N���A
	SCI6.SSR.BIT.FER   = 0; 									// FER�G���[���N���A
	SCI6.SSR.BIT.PER   = 0; 									// PER�G���[���N���A

}
/*-------------------------------------------------------------------------------
	�֐���		: hw_set
	���e	 	: �֐��v���g�^�C�v�錾
	����		: ����
	�ߒl		: ����
	�X�V��		: 2021/04/21
-------------------------------------------------------------------------------*/
void hw_set(void){
	set_main_clk();
//	set_IOport();
	set_AD_Convert();
	set_IRQ();
	set_CMT();
	set_MTU();
	//set_I2C_intr();
	SCI1_set();
	SCI6_set();
}
