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
		
		//LED_On(GPIOA,GPIO_Pin_1);
	
		//LED_Off(GPIOA,GPIO_Pin_0);
		//for(int i=0;i<10000000;i++);   //8个零延迟5秒，7个零1秒

		//LED_Turn(GPIOA,GPIO_Pin_0);
		//for(int i=0;i<10000000;i++);
		
		
		
		LED_On(GPIOA,GPIO_Pin_2);
		//LED_On(GPIOA,GPIO_Pin_3);
		LED_On(GPIOA,GPIO_Pin_4);
		//LED_On(GPIOA,GPIO_Pin_5);
		LED_On(GPIOA,GPIO_Pin_6);
		//LED_On(GPIOA,GPIO_Pin_7);
		//LED_On(GPIOB,GPIO_Pin_0);
		LED_On(GPIOB,GPIO_Pin_1);
		
	}
	
}

