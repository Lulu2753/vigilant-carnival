#include "stm32f10x.h"  
#include "LED.h"

void TIM_I(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  //打开定时器时钟

	//配置定时器参数
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_ClockDivision= TIM_CKD_DIV1; //不二次分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数
	TIM_TimeBaseStructure.TIM_Period=999; //ARR
	TIM_TimeBaseStructure.TIM_Prescaler=7199; //PSC
	//时长计算方式：主频（72MHz）除以[（ARR+1）*（PSC+1）]，得到的频率是一秒钟多少次，一秒钟10次则是计时0.1秒
	//分母乘10就可以做到时间乘10，因为最后有一个倒过来的过程，不能超过65535
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
	
	//配置NVIC（中断）
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;  //注意是打开的tim2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;  //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;  //响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	//打开定时器中断
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	//开始运行定时器
	TIM_Cmd(TIM2,ENABLE);
	
}

typedef struct {
    GPIO_TypeDef* GPIOx;  
    uint16_t GPIO_Pin;    
} LED_TypeDef;

LED_TypeDef LEDS[]=
{
	{GPIOA, GPIO_Pin_0},
	{GPIOA, GPIO_Pin_1},
	{GPIOA, GPIO_Pin_2},
	{GPIOA, GPIO_Pin_3},
	{GPIOA, GPIO_Pin_4},
	{GPIOA, GPIO_Pin_5},
	{GPIOA, GPIO_Pin_6},
	{GPIOA, GPIO_Pin_7},
	{GPIOB, GPIO_Pin_0},
};

volatile uint8_t current_led = 0; 
#define LED_COUNT (sizeof(LEDS)/sizeof(LEDS[0]))

//定时器中断函数
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)  //判断标志位，看是不是tim2
	{
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //标志位清空
		
		//执行中断内容
		LED_Off(LEDS[current_led].GPIOx,LEDS[current_led].GPIO_Pin);
		
		current_led++;
		if(current_led>=LED_COUNT)
			current_led=0;
			
		LED_On(LEDS[current_led].GPIOx,LEDS[current_led].GPIO_Pin);
		
	}

}
