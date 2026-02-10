#include "stm32f10x.h"  // Device header
#include "LED.h"
#include "timer.h"
#include "button.h"

int main(void)
{
	LED_InitA();
	LED_InitB();
	
	Key_Init();
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	
	while(1)
	{
		
		
	}
	
}

