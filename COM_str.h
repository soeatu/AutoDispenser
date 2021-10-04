/*　通信用構造体宣言　*/

#define MaxBuf_val     250		/*送受信バッファ最大値		250byte		*/
#define MaxDataBuf_val 250		/*送受信データ部バッファ最大値	250byte		*/
#define DataBuf_head   4		/*バッファ　ヘッダ部分の大きさ	4byte		*/
#define DataBuf_crc    2		/*バッファ　CRC部分の大きさ	2byte　誤り制御 */
#define SendCountDown  5		/*送信カウントダウン時間(ms)			*/
#define RecCountDown   30-1		/*受信タイムアウト　カウントダウン時間(ms)	*/

/*------通信バッファ構造体------*/
typedef struct{
	unsigned char Data[MaxDataBuf_val];		//データ部バッファ
}Comm_buf_str;

/*------通信バッファ管理構造体------*/
typedef struct{
	Comm_buf_str BUF;
	unsigned char *Buf_staddr;			//バッファ先頭アドレス
	unsigned char *Count;				//バッファカウンター(アドレスインクリメント用)
}Comm_Str;

/*------通信制御管理構造体------*/
typedef struct{
	unsigned char res;				//予約フラグ
	unsigned int  CountDown_ms;			//残り時間(ms)
	unsigned char flag;				//動作許可管理用
	unsigned char enter;				//改行コード確認フラグ
}Comm_ctrl_Str;