#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include "led.h"

/************************************************
 淘宝店铺：https://shop475501589.taobao.com/?spm=pc_detail.29232929/evo365560b447259.shop_block.dshopinfo.5dd97dd6JvMuG3
 咸鱼店铺：https://www.goofish.com/personal?spm=a21ybx.item.itemHeader.1.c17a3da6hy8k28&userId=3890583014
 哔哩哔哩：https://space.bilibili.com/482024430?spm_id_from=333.788.upinfo.detail.click
 作者：胜磊电子
************************************************/


// 导出LED对象供外部使用
extern LED_TypeDef BOARD_LED1;
extern LED_TypeDef BOARD_LED2;


// 板子初始化函数
void BOARD_InitAll(void);


#endif /* BOARD_CONFIG_H */
