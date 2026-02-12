#include "stm32f10x.h"  
#include "LED.h"
#include "button.h"
#include "music.h"
#include "buzzer.h"
#include "music_songs.h"

const Song songs[]={
		{Happy_New_Year, SIZE(Happy_New_Year)},
		{Comes_the_Good_Luck, SIZE(Comes_the_Good_Luck)},
		{Party_Animal, SIZE(Party_Animal)},
		{Motherlands_Flower, SIZE(Motherlands_Flower)}
};


volatile uint16_t cnt=0;
volatile uint16_t current_note=0;
volatile uint16_t note_timer=0;  //音符已播时间
volatile uint16_t SONG_COUNT=sizeof(songs)/sizeof(songs[0]);

void TIM_I(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  //打开定时器时钟

	//配置定时器参数 1ms中断
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_ClockDivision= TIM_CKD_DIV1; //不二次分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数
	TIM_TimeBaseStructure.TIM_Period=99; //ARR
	TIM_TimeBaseStructure.TIM_Prescaler=719; //PSC
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
	
	Buzzer_PlayTone(songs[cnt].notes[0].frequency);
	LED_Set(songs[cnt].notes[0].led_mask);
	
	//开始运行定时器
	TIM_Cmd(TIM2,ENABLE);
	
}

//定时器中断函数
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)  //判断标志位，看是不是tim2
	{
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);  //更新（清除）标志位
		
		note_timer++;
		
		if(note_timer<=songs[cnt%SONG_COUNT].notes[current_note].duration);
		
		else if(note_timer<=songs[cnt%SONG_COUNT].notes[current_note].duration+30)
		{
			Buzzer_Stop();
			LED_Set(0);
			
		}
		
		else
		{	
			current_note++;
				
			if(current_note>songs[cnt%SONG_COUNT].length-1)
				current_note=0;
			
			note_timer=0;
			
			Buzzer_PlayTone(songs[cnt%SONG_COUNT].notes[current_note].frequency);
			
			LED_Set(songs[cnt%SONG_COUNT].notes[current_note].led_mask);
		}
		
		
	}
}
