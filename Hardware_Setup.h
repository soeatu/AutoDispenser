#include "iodefine.h"

#define MTU0_TGRA 24038
#define MTU0_TGRB_1 1682
#define MTU0_TGRB_2 2884

void set_main_clk(void);		//���C���N���b�N�ݒ�
void set_IOport(void);			//IO�|�[�g�ݒ�
void set_AD_Convert(void);		//AD�ϊ��ݒ�
void set_IRQ(void);			//���͊��荞�ݐݒ�
void set_CMT(void);			//�R���y�A�}�b�`�^�C�}�ݒ�
void set_MTU(void);			//�}���`�t�@���N�V�����^�C�}�p���X�ݒ�