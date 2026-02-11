#include "stm32f10x.h"  
#include "LED.h"
#include "button.h"
#include "music.h"
#include "buzzer.h"

const Note song1_notes[]={
	  {NOTE_C4, 400, 0x01},  // LED0亮 (二进制000000001)
    {NOTE_C4, 400, 0x01},
    {NOTE_G4, 400, 0x02},  // LED1亮 (000000010)
    {NOTE_G4, 400, 0x02},
    {NOTE_A4, 400, 0x04},  // LED2亮 (000000100)
    {NOTE_A4, 400, 0x04},
    {NOTE_G4, 800, 0x02},  // LED1亮，二分音符
    {NOTE_F4, 400, 0x08},  // LED3亮
    {NOTE_F4, 400, 0x08},
    {NOTE_E4, 400, 0x10},  // LED4亮
    {NOTE_E4, 400, 0x10},
    {NOTE_D4, 400, 0x20},  // LED5亮
    {NOTE_D4, 400, 0x20},
    {NOTE_C4, 800, 0x01},  // LED0亮，二分音符
		{0, 0, 0} //要有结束标志
};


const Note song2_notes[]={
	  {NOTE_G4, 400, 0x01},  
    {NOTE_A4, 400, 0x01},
    {NOTE_B4, 200, 0x02},  
    {NOTE_B4, 200, 0x02},
    {NOTE_B4, 200, 0x04}, 
    {NOTE_A4, 200, 0x04},
    {NOTE_B4, 200, 0x02},  
    {NOTE_E5, 400, 0x08},  
    {NOTE_E5, 400, 0x08},
    {NOTE_F5u, 400, 0x10},  
    {NOTE_D5, 600, 0x10},
    {0, 200, 0},
		{NOTE_G4, 200, 0x20},  
    {NOTE_A4, 200, 0x20},
    {NOTE_A4, 200, 0x01},  
		{NOTE_A4, 200, 0x01}, 
		{NOTE_G4, 200, 0x01}, 
		{NOTE_A4, 200, 0x01}, 
		{NOTE_D5, 400, 0x01}, 
		{NOTE_C5, 400, 0x01}, 
		{NOTE_D5, 400, 0x01}, 
		{NOTE_D5, 400, 0x01}, 
		{NOTE_B4, 600, 0x01}, 
		
		{NOTE_G4, 200, 0x01},
		{NOTE_D5, 200, 0x01}, 
		{NOTE_E5, 200, 0x01}, 
		{NOTE_E5, 200, 0x01}, 
		{NOTE_D5, 200, 0x01}, 
		{NOTE_E5, 600, 0x01}, 
		{NOTE_E5, 200, 0x01}, 
		{NOTE_E5, 200, 0x01}, 
		{NOTE_F5u, 200, 0x01}, 
		{NOTE_F5u, 200, 0x01}, 
		{NOTE_E5, 200, 0x01}, 
		{NOTE_F5u, 600, 0x01}, 
		{NOTE_E5, 200, 0x01}, 
		{NOTE_F5u, 600, 0x01}, 
		{NOTE_F5u, 200, 0x01}, 
		{NOTE_E5, 400, 0x01}, 
		{NOTE_G5, 200, 0x01}, 
		{NOTE_F5u, 600, 0x01}, 
		{0, 0, 0} //要有结束标志
};

const Note song3_notes[] = {
    {NOTE_E4, 150, 0x01},
    {NOTE_E4, 150, 0x01},
    {NOTE_F4, 150, 0x02},
    {NOTE_G4, 150, 0x04},
    {NOTE_G4, 150, 0x04},
    {NOTE_F4, 150, 0x08},
    {NOTE_E4, 150, 0x10},
    {NOTE_D4, 150, 0x20},
    {NOTE_C4, 150, 0x40},
    {NOTE_C4, 150, 0x40},
    {NOTE_D4, 150, 0x80},
    {NOTE_E4, 150, 0x01},
    {NOTE_E4, 225, 0x02},  // 附点二分音符
    {NOTE_D4, 75, 0x04},
    {NOTE_D4, 300, 0x08},  // 全音符
    {0, 0, 0}
};

const Song songs[]={
		{"Twinkle Star", song1_notes, 14},
	  {"Party Animal", song2_notes, sizeof(song2_notes)/sizeof(song2_notes[0])},
    {"Ode to Joy", song3_notes, 15}
};

#define SONG_COUNT (sizeof(songs)/sizeof(songs[0]))

volatile uint8_t current_song=0;
volatile uint16_t current_note=0;
volatile uint16_t note_timer=0;  //音符已播时间
//volatile uint8_t led_mask_cache=0; //LED状态缓存


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
	
	Buzzer_PlayTone(song2_notes[0].frequency);
	LED_Set(song2_notes[0].led_mask);
	
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
		
		if(note_timer<=song2_notes[current_note].duration);
		
		else if(note_timer<=song2_notes[current_note].duration+30)
		{
			Buzzer_Stop();
			
		}
		
		else
		{	
			current_note++;
				
			if(current_note>songs[1].length-1)
				current_note=0;
			
			note_timer=0;
			
			Buzzer_PlayTone(song2_notes[current_note].frequency);
			
			LED_Set(song2_notes[current_note].led_mask);
		}
	}
}
