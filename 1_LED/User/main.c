#include "stm32f10x.h"  // Device header
#include "LED.h"
#include "timer.h"

int main(void)
{
	LED_InitA();
	LED_InitB();
	TIM_I();
	
	while(1)
	{
		
		
		
	}
	
}

