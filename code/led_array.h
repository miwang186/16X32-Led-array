#ifndef __LED_ARRAY_H__
#define __LED_ARRAY_H__

#include <STC89C5xRC.H>
#include "stdint.h"

/*
���� 32
���� 16
*/
#define COLUMN_MAX			32
#define ROW_MAX				16
#define ROW_BYTE			(ROW_MAX / 8)
#define PICTURE_BYTE_MAX	(COLUMN_MAX * ROW_BYTE)

/*
74HC595 * 2 ��ɨ��
*/
#define SH_CP_PIN	P20
#define DS_PIN		P21
#define ST_CP_PIN	P22

/*
74HC154 ��ɨ��
*/
#define HC154_ABCD_PIN	P3

void led_picture_scan(const uint8_t *pic_data,int8_t col_offset);

#endif 
