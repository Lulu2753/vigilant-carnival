#ifndef _TIMER_H_  //如果不包含LED_H
#define _TIMER_H_  //那就定义。。

#include "stm32f10x.h"

void TIM_I(void);
void TIM2_IRQHandler(void);

#endif  //结束条件编译检查
