#include "Hardware_Setup.h"
#include "iodefine.h"

void HC_SR04set(void);
void HC_SR04_OnTrig(void);
void HC_SR04_OffTrig(void);
void echopuls_start_stop(void);
void count_echopuls(void);
void Weighted_moving_average(void);
int re_range_return(void);