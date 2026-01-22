#include "board_config.h"

/************************************************
 淘宝店铺：https://shop475501589.taobao.com/?spm=pc_detail.29232929/evo365560b447259.shop_block.dshopinfo.5dd97dd6JvMuG3
 咸鱼店铺：https://www.goofish.com/personal?spm=a21ybx.item.itemHeader.1.c17a3da6hy8k28&userId=3890583014
 哔哩哔哩：https://space.bilibili.com/482024430?spm_id_from=333.788.upinfo.detail.click
 作者：胜磊电子
************************************************/

/**
 * @file    board_config.c
 * @brief   开发板外设配置与初始化
 * @details 本文件实现了开发板上所有外设的配置与初始化函数，
 *          包括LED、蜂鸣器、按键、SPI、USART等模块的初始化。
 */

/************************************* 变量定义 *******************************************************/

/** 
 * @brief 开发板LED对象定义
 * @details 定义了开发板上三个LED的控制结构体
 */
LED_TypeDef BOARD_LED1; /**< 开发板LED1对象 (PB0) */
LED_TypeDef BOARD_LED2; /**< 开发板LED2对象 (PB1) */

/************************************* 局部初始化函数 *******************************************************/

/**
 * @brief 初始化开发板LED
 * @details 配置开发板上LED的GPIO引脚，使其可以被控制
 * @return 无
 */
static void BOARD_InitLEDs(void) {
    // 初始化LED1 (PB0)
    LED_Init(&BOARD_LED1, GPIOB, GPIO_Pin_0);
    
    // 初始化LED2 (PB1)
    LED_Init(&BOARD_LED2, GPIOB, GPIO_Pin_1);
}


/************************************* 全局初始化函数 *******************************************************/

/**
 * @brief 初始化开发板上的所有外设
 * @details 调用各个外设的初始化函数，完成整个开发板的初始化工作
 * @return 无
 */
void BOARD_InitAll(void) {
    // 配置中断优先级分组为2 (2位抢占优先级，2位子优先级)
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
	
    // 初始化LED
    BOARD_InitLEDs();				
}
