#include "board_config.h"

/************************************************
 串口驱动
 实验现象：
 
 淘宝店铺：https://shop475501589.taobao.com/?spm=pc_detail.29232929/evo365560b447259.shop_block.dshopinfo.5dd97dd6JvMuG3
 咸鱼店铺：https://www.goofish.com/personal?spm=a21ybx.item.itemHeader.1.c17a3da6hy8k28&userId=3890583014
 哔哩哔哩：https://space.bilibili.com/482024430?spm_id_from=333.788.upinfo.detail.click
 作者：胜磊电子
************************************************/




/*
************************************************************
*	函数名称：	main
*
*	函数功能：	
*
*	入口参数：	无
*
*	返回参数：	0
*
*	说明：
************************************************************
*/
int main(void)
{
	// 初始化所有外设
    BOARD_InitAll();
    
    while (1) {
		// 闪烁LED1
        LED_Toggle(&BOARD_LED1);
		
		for(uint32_t i=0;i<100000;i++){}
		
		// 闪烁LED1
        LED_Toggle(&BOARD_LED2);
		
		for(uint32_t i=0;i<100000;i++){}
    }
}
