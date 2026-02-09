#include "stm32f10x.h"
#include "LED.h"

void Key_I_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //打开GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);   //打开AFIO时钟
	
	//开始配置GPIO引脚
	GPIO_InitTypeDef GPIO_Initstructure;  //声明结构体
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_IPU;  //改成上拉输出输出
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_0;  //选择初始化引脚
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;  //GPIO速率
	GPIO_Init(GPIOA,&GPIO_Initstructure);  //初始化函数：初始化GPIOA 引脚0
	
	//开始配置AFIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); //引脚字母和数字要对应
	/*以上两个一致*/
	
	
	//配置EXTI
	EXTI_InitTypeDef EXTI_InitStructure;  //定义结构体
	EXTI_InitStructure.EXTI_Line=EXTI_Line0; //选择中断线第几号口，可以不和GPIO的一样
	EXTI_InitStructure.EXTI_LineCmd=ENABLE; //指定中断线的新状态——开启
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt; //指定中断线模式——中断模式
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling; //指定触发信号的有效边沿——上升沿或下降沿或both
	EXTI_Init(&EXTI_InitStructure);
	
	//配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //这个分组每个工程只能有一个
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;  //指定中断通道，EXTI后面跟数字：01234,9_5,15_10，与EXTI选的中断口一致
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;  //指定通道是否开启
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1; //指定抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;  //指定响应优先级
	NVIC_Init(&NVIC_InitStructure);
	
}


void EXTI0_IRQHandler(void)
{ 
	LED_Turn(GPIOA,GPIO_Pin_0);
	
	EXTI_ClearITPendingBit(EXTI_Line0);
}

