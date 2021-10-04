#include "SCI1.h"
#include "iodefine.h"
#include "RS232C.h"

void RS232C(void){
	
	SCI6.TDR = 0x30;			//送信データ格納レジスタ　TDR
	
	while(1){
		
		while(SCI6.SSR.BIT.TEND == 0){}		//トランスミットエンドフラグ　データ送信中は0
		
		SCI6.TDR++;
		if(SCI6.TDR == 0x3a){
			SCI6.TDR = 0x0a;
			while(SCI6.SSR.BIT.TEND == 0){}		//トランスミットエンドフラグ　データ送信中は0
			SCI6.TDR = 0x0d;
			while(SCI6.SSR.BIT.TEND == 0){}		//トランスミットエンドフラグ　データ送信中は0
			SCI6.TDR = 0x30;
		}
		delay_s(1);
	}
	
}