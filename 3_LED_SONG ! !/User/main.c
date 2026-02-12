#include "stm32f10x.h"  // Device header
#include "LED.h"
#include "music.h"
#include "button.h"
#include "buzzer.h"


int main(void)
{
	LED_InitA();
	LED_InitB();
	
	Key_Init();
	Buzzer_Init();
	TIM_I();
	
	while(1)
	{
		if(Key_Pressed_Release()==1)
		{
			cnt++;
			
			TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);
			
			note_timer=0;
			current_note=0;
			
			for(int i=0;i<1500000;i++)
			{
				Buzzer_Stop();
				LED_Set(0);
			}
			
			TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
			
			Buzzer_PlayTone(songs[cnt%SONG_COUNT].notes[0].frequency);
			LED_Set(songs[cnt%SONG_COUNT].notes[0].led_mask);
		}
		
	}
	
}

