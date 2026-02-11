#ifndef _MUSIC_H_  //如果不包含
#define _MUSIC_H_  //那就定义。。

#include "stm32f10x.h"

#define NOTE_C4  262  // Do
#define NOTE_D4  294  // Re
#define NOTE_E4  330  // Mi
#define NOTE_F4  349
#define NOTE_F4u  370  // Fa#
#define NOTE_G4  392  // Sol
#define NOTE_A4  440  // La
#define NOTE_B4  494  // Ti
#define NOTE_C5  523  // Do高
#define NOTE_D5  587  // Re高
#define NOTE_E5  659  // Mi高
#define NOTE_F5  698
#define NOTE_F5u  740
#define NOTE_G5  784
#define NOTE_REST 0   // 休止符

// 歌曲最大音符数
#define MAX_NOTES 64

typedef struct{
	uint16_t frequency;
	uint16_t duration;  //用中断次数表示时间
	uint8_t led_mask; //LED亮灭掩码
} Note;

typedef struct{
	const char* name;
	const Note* notes;
	uint16_t length; //音符数量
} Song;



void TIM_I(void);
void TIM2_IRQHandler(void);

extern volatile uint8_t current_song;
extern volatile uint16_t current_note;
extern volatile uint16_t note_timer;


#endif  //结束条件编译检查
