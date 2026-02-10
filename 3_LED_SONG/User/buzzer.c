#include "stm32f10x.h"  
#include "LED.h"
#include "button.h"

void Buzzer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);  //打开定时器时钟

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // GPIOB时钟
    
	//配置引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;          // PB8 = TIM4_CH3!!（都有对应）
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;    // 复用推挽输出，PWM必须用这个
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//配置定时器参数
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_ClockDivision= TIM_CKD_DIV1; //不二次分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数
	TIM_TimeBaseStructure.TIM_Period=999; //ARR，表示计数次数
	TIM_TimeBaseStructure.TIM_Prescaler=71; //PSC
	//时长计算方式：主频（72MHz）除以[（ARR+1）*（PSC+1）]，得到的频率是一秒钟多少次，一秒钟10次则是计时0.1秒
	//分母乘10就可以做到时间乘10，因为最后有一个倒过来的过程，不能超过65535
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseStructure);
	
	//配置PWM模式,输出比较功能
	TIM_OCInitTypeDef TIM_OCStruct; 
	TIM_OCStruct.TIM_OCMode=TIM_OCMode_PWM1; //模式1：定时器计数器的值小于比较寄存器（CCR）的值时，输出有效电平（由极性设置），否则输出无效电平
	TIM_OCStruct.TIM_OutputState=TIM_OutputState_Enable;//允许PWM信号从引脚输出
	TIM_OCStruct.TIM_Pulse=30; //CRR的值，决定PWM占空比=CRR/(ARR+1)，表示初始高电平时间为30个周期，低电平则为999-30个周期
	TIM_OCStruct.TIM_OCPolarity=TIM_OCPolarity_High;  //输出有效电平时，引脚输出高电平
	TIM_OC3Init(TIM4,&TIM_OCStruct);
	
	
	//开始运行定时器
	TIM_Cmd(TIM4,ENABLE);
	
}
//蜂鸣器音调由ARR决定，声音大小由占空比决定


