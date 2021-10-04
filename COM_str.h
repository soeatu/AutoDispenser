/*�@�ʐM�p�\���̐錾�@*/

#define MaxBuf_val     250		/*����M�o�b�t�@�ő�l		250byte		*/
#define MaxDataBuf_val 250		/*����M�f�[�^���o�b�t�@�ő�l	250byte		*/
#define DataBuf_head   4		/*�o�b�t�@�@�w�b�_�����̑傫��	4byte		*/
#define DataBuf_crc    2		/*�o�b�t�@�@CRC�����̑傫��	2byte�@��萧�� */
#define SendCountDown  5		/*���M�J�E���g�_�E������(ms)			*/
#define RecCountDown   30-1		/*��M�^�C���A�E�g�@�J�E���g�_�E������(ms)	*/

/*------�ʐM�o�b�t�@�\����------*/
typedef struct{
	unsigned char Data[MaxDataBuf_val];		//�f�[�^���o�b�t�@
}Comm_buf_str;

/*------�ʐM�o�b�t�@�Ǘ��\����------*/
typedef struct{
	Comm_buf_str BUF;
	unsigned char *Buf_staddr;			//�o�b�t�@�擪�A�h���X
	unsigned char *Count;				//�o�b�t�@�J�E���^�[(�A�h���X�C���N�������g�p)
}Comm_Str;

/*------�ʐM����Ǘ��\����------*/
typedef struct{
	unsigned char res;				//�\��t���O
	unsigned int  CountDown_ms;			//�c�莞��(ms)
	unsigned char flag;				//���싖�Ǘ��p
	unsigned char enter;				//���s�R�[�h�m�F�t���O
}Comm_ctrl_Str;