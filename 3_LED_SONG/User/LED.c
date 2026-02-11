#include "stm32f10x.h"  // Device header

void LED_InitA(void)
{
	//GPIO初始化 PA0
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //打开GPIOA外设时钟
	
	GPIO_InitTypeDef GPIO_Initstructure;  //声明结构体
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;  //GPIO输出模式：推挽输出
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;  //选择初始化引脚
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;  //GPIO速率
	GPIO_Init(GPIOA,&GPIO_Initstructure);  //初始化函数：初始化GPIOA 引脚0
	//配置GPIO的PA0引脚
	
}

void LED_InitB(void)
{
	//GPIO初始化 PB0
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //打开GPIOB外设时钟
	
	GPIO_InitTypeDef GPIO_Initstructure;  //声明结构体
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;  //GPIO输出模式：推挽输出
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;  //选择初始化引脚
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;  //GPIO速率
	GPIO_Init(GPIOB,&GPIO_Initstructure);  //初始化函数：初始化GPIOA 引脚0
	//配置GPIO的PB0引脚
}

void LED_Turn(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)  //翻转灯的状态，不是开关灯
{
	if(GPIO_ReadOutputDataBit(GPIOx,GPIO_Pin)==1)
		GPIO_ResetBits(GPIOx,GPIO_Pin);
	else
		GPIO_SetBits(GPIOx,GPIO_Pin);
}

void LED_Set(uint8_t mask)
{
	GPIO_Write(GPIOA, mask);
}
