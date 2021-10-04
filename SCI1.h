
// 通信割り込み
void SCI1_TXI1();		  						//送信バッファエンプティー割り込み
void SCI1_TEI1();		  						//送信終了割り込み
void SCI1_ERI1();		  						//受信エラー割り込み
void SCI1_RXI1();		  						//受信割り込み

// 初期化
void firm_SCI1_ini_send_buf(); 							// 送信バッファ初期化
void firm_SCI1_ini_rec_buf();  							// 受信バッファ初期化
void set_send_strl_time_SCI1(void);						// 送信間隔制御変数　初期化

// 通信制御
void CHK_REC_DATA_SCI1();							// 受信データ確認
unsigned char END_REC_DATA_SCI1();						// 受信データーCRC確認
unsigned char SCI1_rec_data_chk();						// 受信データー確認要求フラグの確認

void send_intr_SCI1();								// 送信割り込み許可レジスタ制御
void ctl_send_SCI1(void);							// 送信間隔制御
void SCI1_send_reserve_ON(void);						// 送信予約

// 送信バッファ作成
//void set_SCI5_send_buf_CRC(void);
void set_SCI1_data(unsigned char,unsigned char *);			// 

// 受信データー確認
// char chk_SCI5_rec_buf_DestADDR(void);				// 宛先の確認 
// char chk_SCI5_rec_buf_MyADDR(void);					// 送り元の確認
// char chk_SCI5_rec_buf_Total(void);					// 合計バイト数の確認
// char chk_SCI5_rec_buf_CC(void);					// データーコードの確認
//unsigned char *chk_SCI5_rec_buf_Data(void);				// データー先頭アドレスの確認



//extern unsigned int rec_counter;