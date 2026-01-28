#include "stm32f10x.h"  // Device header
#include "LED.h"


int main(void)
{
	LED_InitA();
	LED_InitB();
	
	
	while(1)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_7|GPIO_Pin_6);
		GPIO_ResetBits(GPIOA,GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5);
		
		
	}
	
}

