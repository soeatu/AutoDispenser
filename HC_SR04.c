#include "Hardware_Setup.h"
#include "iodefine.h"
#include "HC_SR04.h"

int CountPlus = 0;
int Range[5] = { 0 };
int i = 0;
int re_range = 0;


//trig Pin PB5 		Echo Pin P31 

void HC_SR04Set(void){
	PORT3.PDR.BIT.B1 = 0;		//EchoPuls入力ポート設定
	PORT3.PIDR.BIT.B1;
}

void HC_SR04_OnTrig(void){
	MTU.TSTR.BIT.CST2 = 1;		//タイマスタートレジスタ　カウンタスタートビット　0:MTU0カウント停止 1:MTU0カウント動作
}

void HC_SR04_OffTrig(void){
	MTU.TSTR.BIT.CST2 = 0;		//タイマスタートレジスタ　カウンタスタートビット　0:MTU0カウント停止 1:MTU0カウント動作
}

void echopuls_start_stop(void){
	
	if(PORT3.PIDR.BIT.B1 == 1){
		CMT.CMSTR0.BIT.STR0 = 1;	//コンペアマッチタイマスタートレジスタ　0:停止　1:開始
	}
	
	if(PORT3.PIDR.BIT.B1 == 0){
		CMT.CMSTR0.BIT.STR0 = 0;	//コンペアマッチタイマスタートレジスタ　0:停止　1:開始
		CMT0.CMCNT = 0;
		Range[i] = CountPlus;
		CountPlus = 0;
		i++;
	}
	
	if(i > 4){
		Weighted_moving_average();
		i = 0;
	}
}
  

void count_echopuls(void){
	
	CountPlus++;
}


void Weighted_moving_average(void){
	
	re_range = ((Range[0]*1)+(Range[1]*2)+(Range[2]*3)+(Range[3]*4)+(Range[4]*5))/15;
	
}

int re_range_return(void){
	return re_range;
}
