
// �ʐM���荞��
void SCI1_TXI1();		  						//���M�o�b�t�@�G���v�e�B�[���荞��
void SCI1_TEI1();		  						//���M�I�����荞��
void SCI1_ERI1();		  						//��M�G���[���荞��
void SCI1_RXI1();		  						//��M���荞��

// ������
void firm_SCI1_ini_send_buf(); 							// ���M�o�b�t�@������
void firm_SCI1_ini_rec_buf();  							// ��M�o�b�t�@������
void set_send_strl_time_SCI1(void);						// ���M�Ԋu����ϐ��@������

// �ʐM����
void CHK_REC_DATA_SCI1();							// ��M�f�[�^�m�F
unsigned char END_REC_DATA_SCI1();						// ��M�f�[�^�[CRC�m�F
unsigned char SCI1_rec_data_chk();						// ��M�f�[�^�[�m�F�v���t���O�̊m�F

void send_intr_SCI1();								// ���M���荞�݋����W�X�^����
void ctl_send_SCI1(void);							// ���M�Ԋu����
void SCI1_send_reserve_ON(void);						// ���M�\��

// ���M�o�b�t�@�쐬
//void set_SCI5_send_buf_CRC(void);
void set_SCI1_data(unsigned char,unsigned char *);			// 

// ��M�f�[�^�[�m�F
// char chk_SCI5_rec_buf_DestADDR(void);				// ����̊m�F 
// char chk_SCI5_rec_buf_MyADDR(void);					// ���茳�̊m�F
// char chk_SCI5_rec_buf_Total(void);					// ���v�o�C�g���̊m�F
// char chk_SCI5_rec_buf_CC(void);					// �f�[�^�[�R�[�h�̊m�F
//unsigned char *chk_SCI5_rec_buf_Data(void);				// �f�[�^�[�擪�A�h���X�̊m�F



//extern unsigned int rec_counter;