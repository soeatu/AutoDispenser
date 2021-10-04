#include "iodefine.h"
#include "Hardware_Setup.h"

/*-------------------------------------------------------------------------------
	関数名		: set_main_clk
	内容	 	: CPU CLOCK の初期化
	引数		: 無し
	戻値		: 無し
	更新日		: 2017/08/16
-------------------------------------------------------------------------------*/
void set_main_clk(void){

unsigned int i; 	


	// クロック発生 ( HOCO 50MHz発振 )

	SYSTEM.PRCR.WORD   = 0xA507;						// プロテクト解除
	
	SYSTEM.HOCOWTCR2.BYTE = 0x03;						// 9216cyc発振安定期間
	SYSTEM.HOCOCR2.BYTE   = 0x03;						// 50MHzを選択  03
	SYSTEM.HOCOCR.BYTE    = 0x00;						// HOCO発振
	for( i = 0 ; i<11 ; i++ );						// 350μsの発振待機時間

	// 動作モード/クロック分周比/クロック源選択
	SYSTEM.OPCCR.BYTE  = 0x06;						// 低速動作モード１に切り替え	
	while( SYSTEM.OPCCR.BIT.OPCMTSF );					// 書き換え完了待ち													
	SYSTEM.SCKCR.LONG  = 0x10821115;					// クロック分周比設定
	while( SYSTEM.SCKCR.LONG!=0x10821115 );					// 書き換え完了待ち			
	*(char*)0x00080200 = 0x00;						// SCKCR3変更手続き
	SYSTEM.SCKCR3.WORD = 0x0100;						// クロック源をHOCO

	RTC.RCR3.BYTE = 0x0C;							// クロック入力禁止
	while(RTC.RCR3.BIT.RTCEN);						// 書き換え完了待ち
	
	SYSTEM.PRCR.WORD   = 0xA500;						// プロテクト設定	
	
}

/*-------------------------------------------------------------------------------
	関数名		: set_IOport
	内容	 	: 入出力ポートを一括宣言
	引数		: 無し
	戻値		: 無し
	更新日		: 2021/04/21
-------------------------------------------------------------------------------*/
/*------------     IOポート設定     ------------*/
void set_IOport(void){

	//PDR　入力/出力を指定するポート方向レジスタ　0:入力 1:出力
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

	//PODR　ポート出力データレジスタ　汎用出力ポートとして使用する端子の出力データを格納するレジスタ　0:出力Low　1:出力High
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

	//PIDR　ポート入力データレジスタ　ポートの端子の状態を反映するレジスタです　
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

	//PMR　レジスタの各ビットはそれぞれのポートの端子一本ずつに対応しており、１ビット単位で指定できる　1:汎用入力ポートとして使用　2:周辺機器として使用
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

	//ODR0　オープンドレイン制御レジスタ0　マニュアル参照
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

	//ODR1　オープンドレイン制御レジスタ1　マニュアル参照
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

	//PCR　プルアップ制御レジスタ　端子が入力状態のとき、PORTm.PCRレジスタが"1"のビットに対応する端子の入力プルアップ抵抗が有効になる　0:入力プルアップ抵抗無効　1:入力プルアップ抵抗有効
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

	//DSCR  駆動制御レジスタ　0:通常出力　1:高駆動出力
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
	関数名		: set_AD_Convert
	内容	 	: A/D変換レジスタ設定
	引数		: 無し
	戻値		: 無し
	更新日		: 2021/04/21
-------------------------------------------------------------------------------*/
void set_AD_Convert(void){
	//32bit指定はWORDを用いる
	SYSTEM.PRCR.WORD = 0xA502;		//プロテクトレジスタ　　　　　　　　　　　　プロテクトレジスタの消費電力低減機能を書き込み許可　上位8ビットはA5固定　下位8ビットに設定を書き込み
	SYSTEM.MSTPCRA.BIT.MSTPA17 = 0;		//モジュールストップコントロールレジスタA   消費電力低減機能の17bitを指定してモジュールストップ状態を解除
	SYSTEM.PRCR.WORD = 0xA500;		//プロテクトレジスタ　　　　　　　　　　　　プロテクトレジスタの消費電力低減機能を書き込み禁止　上位8ビットはA5固定　下位8ビットに設定を書き込み
	
	MPC.PWPR.BIT.PFSWE = 1;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 0;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	
	MPC.P40PFS.BIT.ASEL = 1;		//P40端子機能制御レジスタ　P40PFS　AN000 ASELビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する 
//	MPC.P41PFS.BIT.ASEL = 1;		//P41端子機能制御レジスタ　P41PFS　AN001 ASELビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.P42PFS.BIT.ASEL = 1;		//P42端子機能制御レジスタ　P42PFS　AN002 ASELビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.P43PFS.BIT.ASEL = 1;		//P43端子機能制御レジスタ　P43PFS　AN003 ASELビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.P44PFS.BIT.ASEL = 1;		//P44端子機能制御レジスタ　P44PFS　AN004 ASELビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.P45PFS.BIT.ASEL = 1;		//P45端子機能制御レジスタ　P45PFS　AN005 ASELビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する 100pin Only
//	MPC.P46PFS.BIT.ASEL = 1;		//P46端子機能制御レジスタ　P46PFS　AN006 ASELビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.P47PFS.BIT.ASEL = 1;		//P47端子機能制御レジスタ　P47PFS　AN007 ASELビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する 100pin Only

	MPC.PE0PFS.BIT.ASEL = 1;		//PE0端子機能制御レジスタ　PE0PFS　AN008 AESLビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.PE1PFS.BIT.ASEL = 1;		//PE1端子機能制御レジスタ　PE0PFS　AN008 AESLビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.PE2PFS.BIT.ASEL = 1;		//PE2端子機能制御レジスタ　PE0PFS　AN008 AESLビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.PE3PFS.BIT.ASEL = 1;		//PE3端子機能制御レジスタ　PE0PFS　AN008 AESLビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.PE4PFS.BIT.ASEL = 1;		//PE4端子機能制御レジスタ　PE0PFS　AN008 AESLビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.PE5PFS.BIT.ASEL = 1;		//PE5端子機能制御レジスタ　PE0PFS　AN008 AESLビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する
//	MPC.PE6PFS.BIT.ASEL = 1;		//PE6端子機能制御レジスタ　PE0PFS　AN008 AESLビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する 100pin Only
//	MPC.PE7PFS.BIT.ASEL = 1;		//PE7端子機能制御レジスタ　PE0PFS　AN008 AESLビット　0:アナログ端子以外に使用する　1:アナログ端子として使用する 100pin Only

	MPC.PWPR.BIT.PFSWE = 0;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 1;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	
	S12AD.ADANSA.BIT.ANSA0 = 1;		//A/D変換チャネル選択ビット[0]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA1 = 1;		//A/D変換チャネル選択ビット[1]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA2 = 1;		//A/D変換チャネル選択ビット[2]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA3 = 1;		//A/D変換チャネル選択ビット[3]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA4 = 1;		//A/D変換チャネル選択ビット[4]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA5 = 1;		//A/D変換チャネル選択ビット[5]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA6 = 1;		//A/D変換チャネル選択ビット[6]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA7 = 1;		//A/D変換チャネル選択ビット[7]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA8 = 1;		//A/D変換チャネル選択ビット[8]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA9 = 1;		//A/D変換チャネル選択ビット[9]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA10 = 1;		//A/D変換チャネル選択ビット[10]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA11 = 1;		//A/D変換チャネル選択ビット[11]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA12 = 1;		//A/D変換チャネル選択ビット[12]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA13 = 1;		//A/D変換チャネル選択ビット[13]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA14 = 1;		//A/D変換チャネル選択ビット[14]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする
//	S12AD.ADANSA.BIT.ANSA15 = 1;		//A/D変換チャネル選択ビット[15]　0:AN000～AN015を変換対象から外す　1:AN000～AN015を変換対象とする

//	S12AD.ADCSR.BIT.DBLANS = 0;		//A/Dコントロールレジスタ　A/D変換データ2重化チャネル選択ビット
//	S12AD.ADCSR.BIT.GBADIE = 0;		//A/Dコントロールレジスタ　グループBスキャン終了割り込み許可ビット
//	S12AD.ADCSR.BIT.DBLE = 0;		//A/Dコントロールレジスタ　ダブルトリガモード選択ビット
//	S12AD.ADCSR.BIT.EXTRG = 0;		//A/Dコントロールレジスタ　トリガ選択ビット
//	S12AD.ADCSR.BIT.TRGE = 0;		//A/Dコントロールレジスタ　トリガ開始許可ビット
//	S12AD.ADCSR.BIT.ADIE = 0;		//A/Dコントロールレジスタ　スキャン終了割り込みビット
	S12AD.ADCSR.BIT.ADCS = 2;		//A/Dコントロールレジスタ　スキャンモード選択ビット[1:0] 00:シングル 01:グループ 10:連続スキャン 11:禁止
	S12AD.ADCSR.BIT.ADST = 1;		//A/Dコントロールレジスタ　A/D変換スタートビット　0:A/D変換停止　1:A/D変換開始
}

/*-------------------------------------------------------------------------------
	関数名		: set_IRQ
	内容	 	: 外部割込み設定
	引数		: 無し
	戻値		: 無し
	更新日		: 2021/04/21
-------------------------------------------------------------------------------*/
void set_IRQ(void){
	//IRQ0
	ICU.IER[0x08].BIT.IEN0 = 0;		//割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	ICU.IPR[64].BYTE = 0x0F;		//IRQ0割り込み要因プライオリティレジスタ0　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	ICU.IRQFLTE0.BIT.FLTEN0 = 0;		//IRQ端子デジタルフィルタ許可レジスタ0　IRQ0デジタルフィルタ許可ビット　0:無効　1:有効
	ICU.IRQFLTC0.BIT.FCLKSEL0 = 3;		//IRQ端子デジタルフィルタ設定レジスタ0　IRQ0デジタルフィルタサンプリングクロック設定ビット　00:PCLK　01:PCLK8 10:PCLK32 11:PCLK64
	PORT3.PDR.BIT.B0 = 0;			//ポート設定　P30入力
	MPC.PWPR.BIT.B0WI  = 0;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	MPC.PWPR.BIT.PFSWE = 1;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.P30PFS.BIT.ISEL = 1;		//P30端子機能制御レジスタ　P30PFS　0:IRQ入力端子として使用しなし　1:IRQ入力端子として使用
	MPC.PWPR.BIT.PFSWE = 0;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 1;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	PORT3.PMR.BIT.B0 = 1;			//ポートモードレジスタ　端子モード制御ビット　0:汎用入出力ポートとして使用　1:周辺機器として使用
	ICU.IRQCR[0].BIT.IRQMD = 3;		//IRQコントロールレジスタ　IRQ検出設定ビット　00:Low 01:立ち上がりエッジ 10:立下りエッジ 11:両エッジ
	ICU.IR[64].BIT.IR = 0;			//割り込み要求レジスタ　割り込みステータスフラグ　0:割り込み要求なし　1:割り込み要求あり　エッジ検出要因の場合0のみ　レベル検出要因の場合書き込みNG
	ICU.IRQFLTE0.BIT.FLTEN0 = 1;		//IRQ端子デジタルフィルタ許可レジスタ0　IRQ0デジタルフィルタ許可ビット　0:無効　1:有効
	ICU.IER[0x02].BIT.IEN0 = 1;		//割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	
	
	//IRQ1
	ICU.IER[0x08].BIT.IEN1 = 0;		//割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	ICU.IPR[65].BYTE = 0x0F;		//IRQ0割り込み要因プライオリティレジスタ0　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	ICU.IRQFLTE0.BIT.FLTEN1 = 0;		//IRQ端子デジタルフィルタ許可レジスタ1　IRQ1デジタルフィルタ許可ビット　0:無効　1:有効
	ICU.IRQFLTC0.BIT.FCLKSEL1 = 3;		//IRQ端子デジタルフィルタ設定レジスタ1　IRQ1デジタルフィルタサンプリングクロック設定ビット　00:PCLK　01:PCLK8 10:PCLK32 11:PCLK64
	PORT3.PDR.BIT.B1 = 0;			//ポート設定　P31入力
	MPC.PWPR.BIT.B0WI  = 0;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	MPC.PWPR.BIT.PFSWE = 1;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.P31PFS.BIT.ISEL = 1;		//P31端子機能制御レジスタ　P31PFS　0:IRQ入力端子として使用しなし　1:IRQ入力端子として使用
	MPC.PWPR.BIT.PFSWE = 0;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 1;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	PORT3.PMR.BIT.B1 = 1;			//ポートモードレジスタ　端子モード制御ビット　0:汎用入出力ポートとして使用　1:周辺機器として使用
	ICU.IRQCR[1].BIT.IRQMD = 3;		//IRQコントロールレジスタ　IRQ検出設定ビット　00:Low 01:立ち上がりエッジ 10:立下りエッジ 11:両エッジ
	ICU.IR[65].BIT.IR = 0;			//割り込み要求レジスタ　割り込みステータスフラグ　0:割り込み要求なし　1:割り込み要求あり　エッジ検出要因の場合0のみ　レベル検出要因の場合書き込みNG
	ICU.IRQFLTE0.BIT.FLTEN1 = 1;		//IRQ端子デジタルフィルタ許可レジスタ0　IRQ0デジタルフィルタ許可ビット　0:無効　1:有効
	ICU.IER[0x08].BIT.IEN1 = 1;		//割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	
	/*
	//IRQ2
	ICU.IER[0x02].BIT.IEN0 = 0;		//割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	ICU.IPR[67].BYTE = 0x0f;			//IRQ0割り込み要因プライオリティレジスタ0　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	ICU.IRQFLTE0.BIT.FLTEN0 = 0;		//IRQ端子デジタルフィルタ許可レジスタ0　IRQ0デジタルフィルタ許可ビット　0:無効　1:有効
	ICU.IRQFLTC0.BIT.FCLKSEL0 = 3;		//IRQ端子デジタルフィルタ設定レジスタ0　IRQ0デジタルフィルタサンプリングクロック設定ビット　00:PCLK　01:PCLK8 10:PCLK32 11:PCLK64
	PORT3.PDR.BIT.B1 = 0;			//ポート設定　P31入力
	MPC.PWPR.BIT.PFSWE = 1;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 0;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	MPC.P30PFS.BIT.ISEL = 1;		//P30端子機能制御レジスタ　P30PFS　0:IRQ入力端子として使用しなし　1:IRQ入力端子として使用
	MPC.PWPR.BIT.PFSWE = 0;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 1;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	PORT3.PMR.BIT.B1 = 1;			//ポートモードレジスタ　端子モード制御ビット　0:汎用入出力ポートとして使用　1:周辺機器として使用
	ICU.IRQCR[0].BIT.IRQMD = 1;		//IRQコントロールレジスタ　IRQ検出設定ビット　00:Low 01:立ち上がりエッジ 10:立下りエッジ 11:両エッジ
	ICU.IR[066].BIT.IR = 0;			//割り込み要求レジスタ　割り込みステータスフラグ　0:割り込み要求なし　1:割り込み要求あり　エッジ検出要因の場合0のみ　レベル検出要因の場合書き込みNG
	ICU.IRQFLTE0.BIT.FLTEN2 = 1;		//IRQ端子デジタルフィルタ許可レジスタ0　IRQ0デジタルフィルタ許可ビット　0:無効　1:有効
	ICU.IER[0x02].BIT.IEN0 = 1;		//割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	*/
}

/*-------------------------------------------------------------------------------
	関数名		: set_CMT
	内容	 	: コンペアマッチタイマ割り込み設定
	引数		: 無し
	戻値		: 無し
	更新日		: 2021/04/21
-------------------------------------------------------------------------------*/
void set_CMT(void){
	SYSTEM.PRCR.WORD = 0xA502;		//プロテクトレジスタ プロテクトレジスタの消費電力低減機能を書き込み許可　上位8ビットはA5固定　下位8ビットに設定を書き込み
	
	SYSTEM.MSTPCRA.BIT.MSTPA14 = 0;		//モジュールストップコントロールレジスタA   消費電力低減機能の14bit目を指定してコンペアマッチタイマユニット1モジュールストップ状態を解除　CMT0,CMT1
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;		//モジュールストップコントロールレジスタA   消費電力低減機能の14bit目を指定してコンペアマッチタイマユニット0モジュールストップ状態を解除  CMT2,CMT3
	
	SYSTEM.PRCR.WORD = 0xA500;		//プロテクトレジスタ プロテクトレジスタの消費電力低減機能を書き込み禁止　上位8ビットはA5固定　下位8ビットに設定を書き込み
	
	ICU.IER[0x03].BIT.IEN4 = 1;		//CMT0割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	ICU.IER[0x03].BIT.IEN5 = 1;		//CMT1割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	ICU.IER[0x03].BIT.IEN6 = 1;		//CMT2割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	ICU.IER[0x03].BIT.IEN7 = 1;		//CMT3割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	
	ICU.IPR[4].BYTE = 0x01;			//CMT0割り込み要因プライオリティレジスタ1　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	ICU.IPR[5].BYTE = 0x01;			//CMT1割り込み要因プライオリティレジスタ2　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	ICU.IPR[6].BYTE = 0x01;			//CMT2割り込み要因プライオリティレジスタ3　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	ICU.IPR[7].BYTE = 0x01;			//CMT3割り込み要因プライオリティレジスタ4　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	
	//CMT0
	//PCLKB=25MHz  s = 1/f = 0.04us
	//8分周の場合:0.04us * 8 = 0.32us
	CMT0.CMCR.BIT.CKS = 0;			//コンペアマッチタイマコントロールレジスタ　クロック選択ビット　CKS[2:0]　00:PCLK8(8分周) 01:PCLK32(32分周) 10:PCLK128(128分周) 11:PCLK512(512分周)
	CMT0.CMCR.BIT.CMIE = 1;			//コンペアマッチタイマコントロールレジスタ　コンペアマッチ割り込み許可ビット　0:禁止　1:許可
	
	//CMT1
	//32分周の場合:0.04us * 32 = 1.28us
	CMT1.CMCR.BIT.CKS = 1;			//コンペアマッチタイマコントロールレジスタ　クロック選択ビット　CKS[2:0]　00:PCLK8(8分周) 01:PCLK32(32分周) 10:PCLK128(128分周) 11:PCLK512(512分周)
	CMT1.CMCR.BIT.CMIE = 1;			//コンペアマッチタイマコントロールレジスタ　コンペアマッチ割り込み許可ビット　0:禁止　1:許可
	
	//CMT2
	//128分周の場合:0.04us * 128 = 5.12us
	CMT2.CMCR.BIT.CKS = 2;			//コンペアマッチタイマコントロールレジスタ　クロック選択ビット　CKS[2:0]　00:PCLK8(8分周) 01:PCLK32(32分周) 10:PCLK128(128分周) 11:PCLK512(512分周)
	CMT2.CMCR.BIT.CMIE = 1;			//コンペアマッチタイマコントロールレジスタ　コンペアマッチ割り込み許可ビット　0:禁止　1:許可
	
	//CMT3
	//512分周の場合:0.04us * 512 = 20.48us
	CMT3.CMCR.BIT.CKS = 3;			//コンペアマッチタイマコントロールレジスタ　クロック選択ビット　CKS[2:0]　00:PCLK8(8分周) 01:PCLK32(32分周) 10:PCLK128(128分周) 11:PCLK512(512分周)
	CMT3.CMCR.BIT.CMIE = 1;			//コンペアマッチタイマコントロールレジスタ　コンペアマッチ割り込み許可ビット　0:禁止　1:許可
	
	
	
	
	//CMT0
	CMT0.CMCNT = 0;				//カウンタレジスタ初期化
	CMT0.CMCOR = 181 - 1;			//カウント設定　0.32us * 3カウント　= 30us

	//CMT1
	CMT1.CMCNT = 0;				//カウンタレジスタ初期化
	CMT1.CMCOR = 7810 - 1;			//カウント設定　1.28us * 781カウント　= 10ms

	//CMT2
	CMT2.CMCNT = 0;				//カウンタレジスタ初期化
	CMT2.CMCOR = 50 -1;			//カウント設定　5.12us * 50カウント　= 256us

	//CMT3
	CMT3.CMCNT = 0;				//カウンタレジスタ初期化
	CMT3.CMCOR = 50 -1;			//カウント設定　20.48us * 50カウント　= 1024us

}

/*-------------------------------------------------------------------------------
	関数名		: set_CMT
	内容	 	: コンペアマッチタイマ割り込み設定
	引数		: 無し
	戻値		: 無し
	更新日		: 2021/04/21
-------------------------------------------------------------------------------*/
void set_MTU(void){
	SYSTEM.PRCR.WORD = 0xA502;		//プロテクトレジスタ　　　　　　　　　　　　プロテクトレジスタの消費電力低減機能を書き込み許可　上位8ビットはA5固定　下位8ビットに設定を書き込み
	
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;		//モジュールストップコントロールレジスタA   消費電力低減機能の9bit目を指定してマルチファンクションタイマパルスユニット1モジュールストップ状態を解除　CMT0,CMT1
	
	SYSTEM.PRCR.WORD = 0xA500;		//プロテクトレジスタ　　　　　　　　　　　　プロテクトレジスタの消費電力低減機能を書き込み禁止　上位8ビットはA5固定　下位8ビットに設定を書き込み
	//MTU0
	ICU.IER[0x0E].BIT.IEN2 = 1;		//MTU0A割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	ICU.IER[0x0E].BIT.IEN3 = 1;		//MTU0B割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	//MTU1
//	ICU.IER[0x0F].BIT.IEN1 = 1;		//MTU1A割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
//	ICU.IER[0x0F].BIT.IEN2 = 1;		//MTU1B割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	//MTU2
	ICU.IER[0x0F].BIT.IEN5 = 1;		//MTU2A割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	ICU.IER[0x0F].BIT.IEN6 = 1;		//MTU2B割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	//MTU3
//	ICU.IER[0x10].BIT.IEN1 = 1;		//MTU3A割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
//	ICU.IER[0x10].BIT.IEN2 = 1;		//MTU3B割り込み要求許可レジスタ　割り込み要求許可ビット　0:禁止　1:許可
	
	//MTU0
	ICU.IPR[114].BYTE = 0x01;		//MTU0A割り込み要因プライオリティレジスタ　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	ICU.IPR[115].BYTE = 0x01;		//MTU0B割り込み要因プライオリティレジスタ　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	//MTU1
//	ICU.IPR[121].BYTE = 0x01;		//MTU1A割り込み要因プライオリティレジスタ　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
//	ICU.IPR[122].BYTE = 0x01;		//MTU1B割り込み要因プライオリティレジスタ　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	//MTU2
	ICU.IPR[125].BYTE = 0x01;		//MTU2A割り込み要因プライオリティレジスタ　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	ICU.IPR[126].BYTE = 0x01;		//MTU2B割り込み要因プライオリティレジスタ　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	//MTU3
//	ICU.IPR[129].BYTE = 0x01;		//MTU3A割り込み要因プライオリティレジスタ　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
//	ICU.IPR[130].BYTE = 0x01;		//MTU3B割り込み要因プライオリティレジスタ　割り込み優先レベル設定ビット　IPR[3:0] 0～15(最高)レベル
	
	//MTU0
	PORTB.PDR.BIT.B3 = 1;			//ポートB3を出力設定　PWM出力先
	PORTB.PMR.BIT.B3 = 0;			//ポートB3を汎用入出力ポートとして設定
//	MPC.PWPR.BYTE = 0x40;
	//書き込みプロテクトレジスタはB0WIから解除しないとPFSWEは書き換わらない
	MPC.PWPR.BIT.B0WI  = 0;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止	
	MPC.PWPR.BIT.PFSWE = 1;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	
	MPC.PB3PFS.BIT.PSEL = 1;		//PB3端子機能制御レジスタ　PB3PFS　0:MTIOC0A端子として使用しなし　1:MTIOC0A端子として使用

	MPC.PWPR.BIT.PFSWE = 0;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 1;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	PORTB.PMR.BIT.B3 = 1;			//ポートB3を周辺機器ポートとして設定
	
	MTU0.TMDR.BIT.MD = 2;   		//MTU　タイムモードレジスタ　モード選択ビット　PWMモード1
	MTU0.TIORH.BIT.IOA = 2;			//MTU　タイマI/Oコントロールレジスタ　IOA 初期出力はLow コンペアマッチでLow
	MTU0.TIORH.BIT.IOB = 1;			//MTU　タイマI/Oコントロールレジスタ　IOB 初期出力はLow コンペアマッチでHigh
	MTU0.TIORL.BYTE = 0x00;			//MTU　タイマI/Oコントロールレジスタ　IOA&IOB 出力禁止
	MTU0.TCR.BIT.TPSC = 2;			//MTU　タイマコントロールレジスタ タイマプリスケーラ選択ビット 0:25.000MHz=0.04us 1:12.500MHz=0.16us 2:15.625MHz=0.64us 3:0.390MHz=2.56us
	MTU0.TCR.BIT.CCLR = 1;			//MTU　タイマコントロールレジスタ　カウンタリセット選択ビット　MTU0_Bをコンペアマッチでクリア
	MTU0.TIER.BIT.TGIEA = 1;		//MTU　タイマ割り込み許可レジスタ　TGR割り込み許可Aビット　0:禁止　1:許可
	MTU0.TIER.BIT.TGIEB = 1;		//MTU　タイマ割り込み許可レジスタ　TGR割り込み許可Bビット　0:禁止　1:許可
	
	MTU0.TCNT = 0;				//MTU　タイマカウンタ　初期化
	//周波数設定　1 / (0.64us * 12500) = 125Hz 
	MTU0.TGRA =  MTU0_TGRA;			//MTU　タイマジェネラルレジスタ　アウトプットコンペア/インプットキャプチャ コンペアマッチ　MTU.TPSC*MTU_TGRA ON時間　0us
	MTU0.TGRB =  0;			//MTU　タイマジェネラルレジスタ　アウトプットコンペア/インプットキャプチャ コンペアマッチ　MTU.TPSC*MTU_TGRA*MTU_TGRB　キャリア(時間) 0.64us*31250=20ms
	
	//MTU1
	PORTE.PDR.BIT.B4 = 1;			//ポートE4を出力設定　PWM出力先
	PORTE.PMR.BIT.B4 = 0;			//ポートE4を汎用入出力ポートとして設定
	MPC.PWPR.BIT.PFSWE = 1;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 0;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	MPC.PE4PFS.BIT.PSEL = 1;		//PE4端子機能制御レジスタ　PB3PFS　0:MTIOC0A端子として使用しなし　1:MTIOC0A端子として使用
	MPC.PWPR.BIT.PFSWE = 0;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 1;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	PORTE.PMR.BIT.B4 = 1;			//ポートB3を周辺機器ポートとして設定
	
	MTU1.TMDR.BIT.MD = 2;			//MTU　タイムモードレジスタ　モード選択ビット　PWMモード1
	MTU1.TIOR.BIT.IOA = 1;			//MTU　タイマI/Oコントロールレジスタ　IOA 初期出力はLow コンペアマッチでLow
	MTU1.TIOR.BIT.IOB = 2;			//MTU　タイマI/Oコントロールレジスタ　IOB 初期出力はLow コンペアマッチでHigh
	MTU1.TCR.BIT.TPSC = 2;			//MTU　タイマコントロールレジスタ タイマプリスケーラ選択ビット 0:25.000MHz=0.04us 1:12.500MHz=0.08us 2:15.625MHz=0.64us 3:0.390MHz=2.56us
	MTU1.TCR.BIT.CCLR = 2;			//MTU　タイマコントロールレジスタ　カウンタリセット選択ビット　MTU0_Bをコンペアマッチでクリア
	MTU1.TIER.BIT.TGIEA = 1;		//MTU　タイマ割り込み許可レジスタ　TGR割り込み許可Aビット　0:禁止　1:許可
	MTU1.TIER.BIT.TGIEB = 1;		//MTU　タイマ割り込み許可レジスタ　TGR割り込み許可Bビット　0:禁止　1:許可
	MTU1.TCNT = 0;				//MTU　タイマカウンタ　初期化
	MTU1.TGRA = 0;				//MTU　タイマジェネラルレジスタ　アウトプットコンペア/インプットキャプチャ コンペアマッチ　MTU.TPSC*MTU_TGRA ON時間　0us
	MTU1.TGRB = 31250;			//MTU　タイマジェネラルレジスタ　アウトプットコンペア/インプットキャプチャ コンペアマッチ　MTU.TPSC*MTU_TGRA*MTU_TGRB　キャリア(時間) 0.64us*31250=20ms
	
	//MTU2 超音波センサ　トリガ用パルス
	PORTB.PDR.BIT.B5 = 1;			//ポートB5を出力設定　PWM出力先
	PORTB.PMR.BIT.B5 = 0;			//ポートB5を汎用入出力ポートとして設定
	MPC.PWPR.BIT.B0WI  = 0;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	MPC.PWPR.BIT.PFSWE = 1;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	
	MPC.PB5PFS.BIT.PSEL = 1;		//PB5端子機能制御レジスタ　PB3PFS　0:MTIOC0A端子として使用しなし　1:MTIOC0A端子として使用
	
	MPC.PWPR.BIT.PFSWE = 0;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 1;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	PORTB.PMR.BIT.B5 = 1;			//ポートB5を周辺機器ポートとして設定
	
	MTU2.TMDR.BIT.MD = 2;			//MTU　タイムモードレジスタ　モード選択ビット　PWMモード1
	MTU2.TIOR.BIT.IOA = 6;			//MTU　タイマI/Oコントロールレジスタ　IOA 初期出力はLow コンペアマッチでLow
	MTU2.TIOR.BIT.IOB = 1;			//MTU　タイマI/Oコントロールレジスタ　IOB 初期出力はLow コンペアマッチでHigh
	MTU2.TCR.BIT.TPSC = 2;			//MTU　タイマコントロールレジスタ タイマプリスケーラ選択ビット 0:25.000MHz=0.04us 1:12.500MHz=0.08us 2:15.625MHz=0.64us 3:0.390MHz=2.56us
	MTU2.TCR.BIT.CCLR = 1;			//MTU　タイマコントロールレジスタ　カウンタリセット選択ビット　MTU0_Aをコンペアマッチでクリア
	MTU2.TIER.BIT.TGIEA = 1;		//MTU　タイマ割り込み許可レジスタ　TGR割り込み許可Aビット　0:禁止　1:許可
	MTU2.TIER.BIT.TGIEB = 1;		//MTU　タイマ割り込み許可レジスタ　TGR割り込み許可Bビット　0:禁止　1:許可
	MTU2.TCNT = 0;				//MTU　タイマカウンタ　初期化
	MTU2.TGRA = 15000;			//MTU　タイマジェネラルレジスタ　アウトプットコンペア/インプットキャプチャ コンペアマッチ　MTU.TPSC*MTU_TGRA ON時間　0us
	MTU2.TGRB = 15;				//MTU　タイマジェネラルレジスタ　アウトプットコンペア/インプットキャプチャ コンペアマッチ　MTU.TPSC*MTU_TGRA*MTU_TGRB　キャリア(時間) 0.64us*31250=20ms
	
	//MTU3
	PORT1.PDR.BIT.B4 = 1;			//ポート14を出力設定　PWM出力先
	PORT1.PMR.BIT.B4 = 0;			//ポート14を汎用入出力ポートとして設定
	MPC.PWPR.BIT.PFSWE = 1;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 0;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	MPC.P14PFS.BIT.PSEL = 1;		//P14端子機能制御レジスタ　PB3PFS　0:MTIOC0A端子として使用しなし　1:MTIOC0A端子として使用
	MPC.PWPR.BIT.PFSWE = 0;			//書き込みプロテクトレジスタ　PFSレジスタの書き込み許可ビット　  0:禁止　1:許可
	MPC.PWPR.BIT.B0WI  = 1;			//書き込みプロテクトレジスタ　PFSWEレジスタの書き込み許可ビット　0:許可  1:禁止
	PORT1.PMR.BIT.B4 = 1;			//ポートB3を周辺機器ポートとして設定
	
	MTU3.TMDR.BIT.MD = 2;			//MTU　タイムモードレジスタ　モード選択ビット　PWMモード1
	MTU3.TIORH.BIT.IOA = 1;			//MTU　タイマI/Oコントロールレジスタ　IOA 初期出力はLow コンペアマッチでLow
	MTU3.TIORH.BIT.IOB = 2;			//MTU　タイマI/Oコントロールレジスタ　IOB 初期出力はLow コンペアマッチでHigh
	MTU3.TIORL.BYTE = 0x00;			//MTU　タイマI/Oコントロールレジスタ　IOA&IOB 出力禁止
	MTU3.TCR.BIT.TPSC = 2;			//MTU　タイマコントロールレジスタ タイマプリスケーラ選択ビット 0:25.000MHz=0.04us 1:12.500MHz=0.08us 2:15.625MHz=0.64us 3:0.390MHz=2.56us
	MTU3.TCR.BIT.CCLR = 2;			//MTU　タイマコントロールレジスタ　カウンタリセット選択ビット　MTU0_Bをコンペアマッチでクリア
	MTU3.TIER.BIT.TGIEA = 1;		//MTU　タイマ割り込み許可レジスタ　TGR割り込み許可Aビット　0:禁止　1:許可
	MTU3.TIER.BIT.TGIEB = 1;		//MTU　タイマ割り込み許可レジスタ　TGR割り込み許可Bビット　0:禁止　1:許可
	MTU3.TCNT = 0;				//MTU　タイマカウンタ　初期化
	MTU3.TGRA = 0;				//MTU　タイマジェネラルレジスタ　アウトプットコンペア/インプットキャプチャ コンペアマッチ　MTU.TPSC*MTU_TGRA ON時間　0us
	MTU3.TGRB = 31250;			//MTU　タイマジェネラルレジスタ　アウトプットコンペア/インプットキャプチャ コンペアマッチ　MTU.TPSC*MTU_TGRA*MTU_TGRB　キャリア(時間) 0.64us*31250=20ms
}

/*-------------------------------------------------------------------------------
	関数名		: set_I2C
	内容	 	: I2Cの初期設定
	引数		: 無し
	戻値		: 無し
	更新日		: 2017/08/16
-------------------------------------------------------------------------------*/
void set_I2C_intr(void){		
	
//	int i;
	
	/* I2Cﾓｼﾞｭｰﾙ有効化 */
	SYSTEM.PRCR.WORD = 0xA502;						// プロテクト解除
	SYSTEM.MSTPCRB.BIT.MSTPB21 = 0;						// I2C(RIIC0) モジュールストップ 解除
	SYSTEM.PRCR.WORD = 0xA500;						// プロテクト設定
	
	PORT1.PDR.BIT.B6 = 0;							// ポート設定 P16 SCL-DS 入力
	PORT1.PDR.BIT.B7 = 0;							// ポート設定 P17 SDA-DS 入力
	
	PORT1.PMR.BIT.B6 = 0;							// ポート設定 P16 汎用入出力ポート
	PORT1.PMR.BIT.B7 = 0;							// ポート設定 P17 汎用入出力ポート
	
	MPC.PWPR.BIT.B0WI = 0;							//  PWPRプロテクトレジスタ  B0WI  許可		
	MPC.PWPR.BIT.PFSWE = 1;							//  PWPRプロテクトレジスタ  PFSWE 許可		
	MPC.P16PFS.BYTE = 0x0F;							//  P16 を SCL 端子として利用する
	MPC.P17PFS.BYTE = 0x0F;							//  P17 を SDA 端子として利用する
	MPC.PWPR.BIT.PFSWE = 0;							//  PWPRプロテクトレジスタ  PFSWE 許可
	MPC.PWPR.BIT.B0WI = 1;							//  PWPRプロテクトレジスタ  B0WI  許可
	
	PORT1.PMR.BIT.B6 = 1;							// ポート設定 SCL 周辺機器ポート
	PORT1.PMR.BIT.B7 = 1;							// ポート設定 SDA 周辺機器ポート
	
//  I2C 初期設定	
	RIIC0.ICCR1.BIT.ICE = 0;						// SCL、SDA端子 動作禁止
	RIIC0.ICCR1.BIT.IICRST=1;						// RIICリセット
	RIIC0.ICCR1.BIT.ICE = 1;						// 内部リセット
	
	// SAR0 設定
	RIIC0.SARU0.BIT.FS = 0;							// 7ビットアドレスフォーマット選択
	RIIC0.SARL0.BIT.SVA = 0x6B;						// スレーブアドレスレジスタ 0x6B

	// SAR1 設定
	RIIC0.SARU1.BIT.FS = 0;							// 7ビットアドレスフォーマット選択
	RIIC0.SARL1.BIT.SVA = 0x1D;						// スレーブアドレスレジスタ	


	RIIC0.ICSER.BIT.SAR0E = 1;						// SARL0、SARU0の設定値 	 有効
	RIIC0.ICSER.BIT.SAR1E = 1;						// SARL1、SARU1の設定値 	 有効
	RIIC0.ICSER.BIT.GCAE = 0;						// ジェネラルコールアドレス　無効
	
	/*
	RIIC0.ICMR3.BIT.ACKWP = 1;						// NACk/ACK信号の送信選択許可(RIIC0.ICMR3.BIT.ACKBTへの書き込み許可)
	
	
	RIIC0.ICMR1.BIT.CKS = 2;						// 通信ビットレートを設定 pclk 25MHz時 b010設定 (100kbps)

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
    RIIC0.ICMR3.BIT.ACKWP = 1;        						// NACk/ACK信号の送信選択許可(RIIC0.ICMR3.BIT.ACKBTへの書き込み許可)
    RIIC0.ICCR1.BIT.IICRST = 0;       						// RIICリセット解除	
	
/*	
	ICMR2、ICMR3を設定							// 必要に応じて設定	
	ICMR2.TMWE=1								// 必要に応じて設定  タイムアウト内部カウンタ書き込み許可	
	TMOCNTL=00h								// タイムアウト内部カウンタの初期化	
	TMOCNTU=00h								// タイムアウト内部カウンタの初期化			
	ICFER.TMOE=1				 				// タイムアウト機能有効(使用する場合有効)
	ICFERを設定
*/	
/*
//	ICIER の設定								// 割り込み許可を設定
	RIIC0.ICIER.BIT.TMOIE = 1;						// タイムアウト割り込み（TMOI）の許可
	RIIC0.ICIER.BIT.ALIE  = 1;						// アービトレーションロスト割り込み（ALI）の許可
	RIIC0.ICIER.BIT.STIE  = 1;						// スタートコンディション検出割り込み（STI）の許可	
	RIIC0.ICIER.BIT.SPIE  = 1;						// ストップコンディション検出割り込み（SPI）の許可
	RIIC0.ICIER.BIT.NAKIE = 1;						// NACK受信割り込み（NAKI）の許可
	RIIC0.ICIER.BIT.RIE   = 1;						// 受信データフル割り込み（RXI）の許可
	RIIC0.ICIER.BIT.TEIE  = 1;						// 送信終了割り込み（TEI）の許可
	RIIC0.ICIER.BIT.TIE   = 1;						// 送信データエンプティ割り込み（TXI）の許可
*/

//	RIIC0.ICFER.BIT.NFE = 1;						// デジタルノイズフィルタ回路を使用する
//	RIIC0.ICCR1.BIT.IICRST = 0;						// IICRST 内部リセット解除

	RIIC0.ICCR1.BIT.ICE = 1;						// SCL、SDA端子 動作許可
		
/*	
	RIIC0.ICCR2.BIT.ST=1;
	while(!RIIC0.ICCR2.BIT.ST){}
	
	RIIC0.ICDRT=0x0A;
*/
	return;	
}

/*-------------------------------------------------------------------------------
	関数名		: set_SCI1
	内容	 	: SCI1の初期設定
	引数		: 無し
	戻値		: 無し
	更新日		: 2017/08/16
-------------------------------------------------------------------------------*/
void SCI1_set(void){
	
	int i;
	
	/* SCI1ﾓｼﾞｭｰﾙ有効化 */
	SYSTEM.PRCR.WORD = 0xA502;									// プロテクト解除
	SYSTEM.MSTPCRB.BIT.MSTPB30 = 0;									// SCI1 モジュールストップ 解除
	SYSTEM.PRCR.WORD = 0xA500;									// プロテクト設定
	
	PORT3.PDR.BIT.B0 = 0;										// ポート設定 RXD1 入力:0	
	PORT2.PDR.BIT.B6 = 0;										// ポート設定 TXD1 出力:1
	
	PORT3.PMR.BIT.B0 = 0;										// ポート設定 RXD1 汎用入出力ポート
	PORT2.PMR.BIT.B6 = 0;										// ポート設定 TXD1 汎用入出力ポート
	
	MPC.PWPR.BIT.B0WI = 0;										//  PWPRプロテクトレジスタ  B0WI  許可		
	MPC.PWPR.BIT.PFSWE = 1;										//  PWPRプロテクトレジスタ  PFSWE 許可		
	MPC.P30PFS.BYTE = 0x0A;										//  P30 を TXD1 端子として利用する
	MPC.P26PFS.BYTE = 0x0A;										//  P26 を RXD1 端子として利用する
	MPC.PWPR.BIT.PFSWE = 0;										//  PWPRプロテクトレジスタ  PFSWE 許可
	MPC.PWPR.BIT.B0WI = 1;										//  PWPRプロテクトレジスタ  B0WI  許可
	
	PORT3.PMR.BIT.B0 = 1;										// ポート設定 RXD1 周辺機器ポート
	PORT2.PMR.BIT.B6 = 1;										// ポート設定 TXD1 周辺機器ポート
	
	/* ｼﾘｱﾙｺﾝﾄﾛｰﾙﾚｼﾞｽﾀ初期化 */
	SCI1.SCR.BYTE     = 0x00 ;	
	
	/* 割込許可 1:許可 0:禁止 */

	ICU.IER[0x1B].BIT.IEN2 = 0;									// ERI 受信エラー割込	禁止	
	ICU.IER[0x1B].BIT.IEN3 = 0;									// RXI 受信割込		禁止
	ICU.IER[0x1B].BIT.IEN4 = 0;									// TXI 送信終了割込	禁止
	ICU.IER[0x1B].BIT.IEN5 = 0;									// TEI 送信割込		禁止	
	
	
	/* 通信プロトコル設定 */	
	SCI1.SCR.BIT.CKE  = 0;										// 内蔵ｼﾞｪﾈﾚｰﾀ使用、出力無し
	SCI1.SMR.BIT.STOP = 0;										// ｽﾄｯﾌﾟﾋﾞｯﾄ長 = 1
	SCI1.SMR.BIT.PM   = 0;										// ﾊﾟﾘﾃｨ EVEN
	SCI1.SMR.BIT.PE   = 0;										// ﾊﾟﾘﾃｨ許可
	SCI1.SMR.BIT.CHR  = 0;										// ﾃﾞｰﾀ長 8bit
	SCI1.SMR.BIT.CM   = 0;										// 調歩同期	
	SCI1.SMR.BIT.CKS  = 0;										// 115200bps設定 n 設定
	SCI1.BRR 	  = 6;										// 115200bps設定 N 設定

	ICU.IPR[218].BIT.IPR = 0xF;									// SCI1 割り込み優先レベル設定	
		
	/* 1bit分待ち */
	for(i=0; i<100000; i++);
	
	ICU.IR[ IR_SCI1_ERI1 ].BIT.IR = 0;								// ERI1 割り込み要求クリア	
	ICU.IR[ IR_SCI1_RXI1 ].BIT.IR = 0;								// RXI1 割り込み要求クリア	
	ICU.IR[ IR_SCI1_TXI1 ].BIT.IR = 0;								// TXI1 割り込み要求クリア		
	ICU.IR[ IR_SCI1_TEI1 ].BIT.IR = 0;								// TEI1 割り込み要求クリア
	
	/* 通信状態設定 */
	SCI1.SCR.BIT.RIE   = 1;										// 受信と受信エラー割込			有効
	SCI1.SCR.BIT.RE    = 1;										// 受信					有効
	SCI1.SCR.BIT.TE    = 1;										// 送信					有効
	SCI1.SCR.BIT.TIE   = 1;										// 送信割込				有効
	SCI1.SCR.BIT.TEIE  = 0;										// 送信終了割込				無効

	ICU.IER[0x1B].BIT.IEN2 = 1;									// ERI 受信エラー割込	許可
	ICU.IER[0x1B].BIT.IEN3 = 1;									// RXI 受信割込			許可
	ICU.IER[0x1B].BIT.IEN4 = 1;									// TXI 送信割込			許可
	ICU.IER[0x1B].BIT.IEN5 = 1;									// TEI 送信終了割込		許可

	SCI1.SSR.BIT.ORER  = 0; 									// ORERエラーをクリア
	SCI1.SSR.BIT.FER   = 0; 									// FERエラーをクリア
	SCI1.SSR.BIT.PER   = 0; 									// PERエラーをクリア

}

/*-------------------------------------------------------------------------------
	関数名		: set_SCI5
	内容	 	: SCI5の初期設定
	引数		: 無し
	戻値		: 無し
	更新日		: 2017/08/16
-------------------------------------------------------------------------------*/
void set_SCI5(void){	
	
	int i;
	
	/* SCI5ﾓｼﾞｭｰﾙ有効化 */
	SYSTEM.PRCR.WORD = 0xA502;						// プロテクト解除
	SYSTEM.MSTPCRB.BIT.MSTPB26 = 0;						// SCI5 モジュールストップ 解除
	SYSTEM.PRCR.WORD = 0xA500;						// プロテクト設定
	
	PORTC.PDR.BIT.B2 = 0;							// ポート設定 RXD5 入力
	PORTC.PDR.BIT.B3 = 0;							// ポート設定 TXD5 出力
	
	PORTC.PMR.BIT.B2 = 0;							// ポート設定 RXD5 汎用入出力ポート
	PORTC.PMR.BIT.B3 = 0;							// ポート設定 TXD5 汎用入出力ポート
	
	MPC.PWPR.BIT.B0WI = 0;							//  PWPRプロテクトレジスタ  B0WI  許可		
	MPC.PWPR.BIT.PFSWE = 1;							//  PWPRプロテクトレジスタ  PFSWE 許可		
	MPC.PC2PFS.BYTE = 0x0A;							//  PC2 を RXD5 端子として利用する
	MPC.PC3PFS.BYTE = 0x0A;							//  PC3 を TXD5 端子として利用する
	MPC.PWPR.BIT.PFSWE = 0;							//  PWPRプロテクトレジスタ  PFSWE 許可
	MPC.PWPR.BIT.B0WI = 1;							//  PWPRプロテクトレジスタ  B0WI  許可
	
	PORTC.PMR.BIT.B2 = 1;							// ポート設定 RXD5 周辺機器ポート
	PORTC.PMR.BIT.B3 = 1;							// ポート設定 TXD5 周辺機器ポート
	
	/* ｼﾘｱﾙｺﾝﾄﾛｰﾙﾚｼﾞｽﾀ初期化 */
	SCI5.SCR.BYTE     = 0x00 ;	
	
	/* 割込許可 1:許可 0:禁止 */

	ICU.IER[0x1B].BIT.IEN6 = 0;						// ERI 受信エラー割込		禁止	
	ICU.IER[0x1B].BIT.IEN7 = 0;						// RXI 受信割込			禁止
	ICU.IER[0x1C].BIT.IEN0 = 0;						// TXI 送信終了割込		禁止
	ICU.IER[0x1C].BIT.IEN1 = 0;						// TEI 送信割込			禁止	


	/* 通信プロトコル設定 */	
	SCI5.SCR.BIT.CKE  = 0;							// 内蔵ｼﾞｪﾈﾚｰﾀ使用、出力無し
	SCI5.SMR.BIT.STOP = 0;							// ｽﾄｯﾌﾟﾋﾞｯﾄ長 = 1
	SCI5.SMR.BIT.PM   = 0;							// ﾊﾟﾘﾃｨ EVEN
	SCI5.SMR.BIT.PE   = 0;							// ﾊﾟﾘﾃｨ許可
	SCI5.SMR.BIT.CHR  = 0;							// ﾃﾞｰﾀ長 8bit
	SCI5.SMR.BIT.CM   = 0;							// 調歩同期	
	SCI5.SMR.BIT.CKS  = 0;							// 115200bps設定 n 設定
	SCI5.BRR 	  	  = 6;						// 115200bps設定 N 設定

	ICU.IPR[222].BIT.IPR = 0xF;						// SCI5 割り込み優先レベル設定	
		
	/* 1bit分待ち */
	for(i=0; i<100000; i++);
	
	ICU.IR[ IR_SCI5_ERI5 ].BIT.IR = 0;					// ERI5 割り込み要求クリア	
	ICU.IR[ IR_SCI5_RXI5 ].BIT.IR = 0;					// RXI5 割り込み要求クリア	
	ICU.IR[ IR_SCI5_TXI5 ].BIT.IR = 0;					// TXI5 割り込み要求クリア		
	ICU.IR[ IR_SCI5_TEI5 ].BIT.IR = 0;					// TEI5 割り込み要求クリア
	
	/* 通信状態設定 */
	SCI5.SCR.BIT.RIE   = 1;							// 受信と受信エラー割込	有効
	SCI5.SCR.BIT.RE    = 1;							// 受信					有効
	SCI5.SCR.BIT.TE    = 1;							// 送信					有効
	SCI5.SCR.BIT.TIE   = 1;							//送信割込				有効
	SCI5.SCR.BIT.TEIE  = 0;							// 送信終了割込			無効

	ICU.IER[0x1B].BIT.IEN6 = 1;						// ERI 受信エラー割込	許可
	ICU.IER[0x1B].BIT.IEN7 = 1;						// RXI 受信割込			許可
//	ICU.IER[0x1C].BIT.IEN0 = 1;						// TXI 送信割込			許可
//	ICU.IER[0x1C].BIT.IEN1 = 1;						// TEI 送信終了割込		許可

	SCI5.SSR.BIT.ORER  = 0; 						// ORERエラーをクリア
	SCI5.SSR.BIT.FER   = 0; 						// FERエラーをクリア
	SCI5.SSR.BIT.PER   = 0; 						// PERエラーをクリア
	
}

/*-------------------------------------------------------------------------------
	関数名		: set_SCI6
	内容	 	: SCI1の初期設定
	引数		: 無し
	戻値		: 無し
	更新日		: 20121/09/6
-------------------------------------------------------------------------------*/
void SCI6_set(void){
	
	int i;
	
	/* SCI6ﾓｼﾞｭｰﾙ有効化 */
	SYSTEM.PRCR.WORD = 0xA502;									// プロテクト解除
	SYSTEM.MSTPCRB.BIT.MSTPB25 = 0;									// SCI6 モジュールストップ 解除
	SYSTEM.PRCR.WORD = 0xA500;									// プロテクト設定
	
	PORTB.PDR.BIT.B0 = 0;										// ポート設定 RXD6 入力	
	PORTB.PDR.BIT.B1 = 0;										// ポート設定 TXD6 出力
	
	PORTB.PMR.BIT.B0 = 0;										// ポート設定 RXD6 汎用入出力ポート
	PORTB.PMR.BIT.B1 = 0;										// ポート設定 TXD6 汎用入出力ポート
	
	MPC.PWPR.BIT.B0WI = 0;										//  PWPRプロテクトレジスタ  B0WI  許可		
	MPC.PWPR.BIT.PFSWE = 1;										//  PWPRプロテクトレジスタ  PFSWE 許可		
	MPC.PB1PFS.BYTE = 0x0A;										//  PB1 を TXD6 端子として利用する
	MPC.PB0PFS.BYTE = 0x0A;										//  PB0 を RXD6 端子として利用する
	MPC.PWPR.BIT.PFSWE = 0;										//  PWPRプロテクトレジスタ  PFSWE 許可
	MPC.PWPR.BIT.B0WI = 1;										//  PWPRプロテクトレジスタ  B0WI  許可
	
	PORTB.PMR.BIT.B0 = 1;										// ポート設定 RXD6 周辺機器ポート
	PORTB.PMR.BIT.B1 = 1;										// ポート設定 TXD6 周辺機器ポート
	
	/* ｼﾘｱﾙｺﾝﾄﾛｰﾙﾚｼﾞｽﾀ初期化 */
	SCI6.SCR.BYTE     = 0x00 ;	
	
	/* 割込許可 1:許可 0:禁止 */

	ICU.IER[0x1C].BIT.IEN2 = 0;									// ERI6 受信エラー割込	禁止	
	ICU.IER[0x1C].BIT.IEN3 = 0;									// RXI6 受信割込		禁止
	ICU.IER[0x1C].BIT.IEN4 = 0;									// TXI6 送信終了割込	禁止
	ICU.IER[0x1C].BIT.IEN5 = 0;									// TEI6 送信割込		禁止	
	
	
	/* 通信プロトコル設定 */	
	SCI6.SCR.BIT.CKE  = 0;										// 内蔵ｼﾞｪﾈﾚｰﾀ使用、出力無し
	SCI6.SMR.BIT.STOP = 0;										// ｽﾄｯﾌﾟﾋﾞｯﾄ長 = 1
	SCI6.SMR.BIT.PM   = 0;										// ﾊﾟﾘﾃｨ EVEN
	SCI6.SMR.BIT.PE   = 0;										// ﾊﾟﾘﾃｨ許可
	SCI6.SMR.BIT.CHR  = 0;										// ﾃﾞｰﾀ長 8bit
	SCI6.SMR.BIT.CM   = 0;										// 調歩同期	
	SCI6.SMR.BIT.CKS  = 0;										// 115200bps設定 n 設定 PCLKクロック
	SCI6.BRR 	  = 6;										// 115200bps設定 N 設定

	ICU.IPR[226].BIT.IPR = 0xF;									// SCI6 割り込み優先レベル設定	
		
	/* 1bit分待ち */
	for(i=0; i<100000; i++);
	
	ICU.IR[ IR_SCI6_ERI6 ].BIT.IR = 0;								// ERI6 割り込み要求クリア	
	ICU.IR[ IR_SCI6_RXI6 ].BIT.IR = 0;								// RXI6 割り込み要求クリア	
	ICU.IR[ IR_SCI6_TXI6 ].BIT.IR = 0;								// TXI6 割り込み要求クリア		
	ICU.IR[ IR_SCI6_TEI6 ].BIT.IR = 0;								// TEI6 割り込み要求クリア
	
	/* 通信状態設定 */
	SCI6.SCR.BIT.RIE   = 1;										// 受信と受信エラー割込			有効
	SCI6.SCR.BIT.RE    = 1;										// 受信					有効
	SCI6.SCR.BIT.TE    = 1;										// 送信					有効
	SCI6.SCR.BIT.TIE   = 1;										// 送信割込				有効
	SCI6.SCR.BIT.TEIE  = 0;										// 送信終了割込				無効

	ICU.IER[0x1C].BIT.IEN2 = 1;									// ERI6 受信エラー割込			許可
	ICU.IER[0x1C].BIT.IEN3 = 1;									// RXI6 受信割込			許可
	ICU.IER[0x1C].BIT.IEN4 = 1;									// TXI6 送信割込			許可
	ICU.IER[0x1C].BIT.IEN5 = 1;									// TEI6 送信終了割込			許可

	SCI6.SSR.BIT.ORER  = 0; 									// ORERエラーをクリア
	SCI6.SSR.BIT.FER   = 0; 									// FERエラーをクリア
	SCI6.SSR.BIT.PER   = 0; 									// PERエラーをクリア

}
/*-------------------------------------------------------------------------------
	関数名		: hw_set
	内容	 	: 関数プロトタイプ宣言
	引数		: 無し
	戻値		: 無し
	更新日		: 2021/04/21
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
