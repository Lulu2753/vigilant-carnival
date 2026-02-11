#include "stm32f10x.h"  // Device header
#include "LED.h"
#include "music.h"
#include "button.h"
#include "buzzer.h"

int main(void)
{
	LED_InitA();
	LED_InitB();
	
	//Key_Init();
	Buzzer_Init();
	TIM_I();
	
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	
	while(1)
	{
		
		
	}
	
}

