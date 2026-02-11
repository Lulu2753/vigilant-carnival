#include "stm32f10x.h"  
#include "LED.h"

void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入，默认引脚高电平，被拉低则触发
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure);
}
//extern uint8_t cnt = 0;

/*uint8_t Key_Pressed_Release(void)
{
	static uint8_t key_state=0;
	
	uint8_t current = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1);
	
	switch(key_state)
	{
		case 0:
			if(current == 0)
			{
				for(volatile uint16_t i=0;i<1000;i++); //消抖
				
				if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
					key_state=1;
			}break;
			
		case 1:
			if(current==1)
			{
				for(volatile uint16_t i=0;i<1000;i++)
				
				if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==1)
				{
					key_state=0;
					return 1;  //表示有效按键动作
				}
			}break;
			
			return 0;
			
	}
}*/
