#include "stm32f10x.h"  // Device header
#include "LED.h"


int main(void)
{
	LED_InitA();
	LED_InitB();
	
	
	
	while(1)
	{
		
		LED_On(GPIOA,GPIO_Pin_1);
	
		LED_Off(GPIOA,GPIO_Pin_0);
		for(int i=0;i<10000000;i++);   //8个零延迟5秒，7个零1秒
		
		LED_Turn(GPIOA,GPIO_Pin_0);
		for(int i=0;i<10000000;i++);
		
	}
	
}

