#include "stm32f10x.h"  // Device header

void LED_Init()
{
	//GPIO初始化 PA0
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //打开GPIOA外设时钟
	
	GPIO_InitTypeDef GPIO_Initstructure;  //声明结构体
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;  //GPIO输出模式：推挽输出
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_0;  //选择初始化引脚
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;  //GPIO速率
	GPIO_Init(GPIOA,&GPIO_Initstructure);  //初始化函数：初始化GPIOA 引脚0
	//配置GPIO的PA0引脚
	
}

void LED_ON()
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0); //高电平
	
}

void LED_OFF()
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_0); //reset低电平
}

