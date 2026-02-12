#ifndef _BUZZER_H_  //如果不包含
#define _BUZZER_H_  //那就定义。。

#include "stm32f10x.h"

void Buzzer_Init(void);
void Buzzer_PlayTone(uint16_t frequency);
void Buzzer_Stop(void);

#endif  //结束条件编译检查
