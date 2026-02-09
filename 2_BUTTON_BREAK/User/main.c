#include "stm32f10x.h"  // Device header
#include "LED.h"
#include "key.h"


int main(void)
{
	LED_InitA();
	LED_InitB();
	Key_I_Init();
	
	while(1)
	{
		
		
	}
	
}

