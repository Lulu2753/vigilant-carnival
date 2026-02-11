#ifndef _LED_H_  //如果不包含LED_H
#define _LED_H_  //那就定义。。

#include "stm32f10x.h"

void LED_InitA(void);
void LED_InitB(void);   //声明、定义的时候加void即可，调用不加
void LED_Turn(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void LED_Off(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void LED_On(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void LED_Set(uint8_t mask);

#endif  //结束条件编译检查

/*头文件固定框架，防止重复编译*/
