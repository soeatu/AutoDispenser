#include "iodefine.h"

#define MTU0_TGRA 24038
#define MTU0_TGRB_1 1682
#define MTU0_TGRB_2 2884

void set_main_clk(void);		//メインクロック設定
void set_IOport(void);			//IOポート設定
void set_AD_Convert(void);		//AD変換設定
void set_IRQ(void);			//入力割り込み設定
void set_CMT(void);			//コンペアマッチタイマ設定
void set_MTU(void);			//マルチファンクションタイマパルス設定