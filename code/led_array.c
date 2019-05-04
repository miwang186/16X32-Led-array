#include "led_array.h"

/*LED点阵列扫描*/
static void led_column_scan(const uint8_t *col_dat, int8_t col_offset)
{
	uint8_t i;
	uint16_t temp_data = col_dat[0] | col_dat[1] << 8;
	
	if(col_offset > 0)
		temp_data <<= col_offset;
	else if(col_offset < 0)
		temp_data >>= -col_offset;
		
	for(i = 0; i < 16; i++)
	{
		if(temp_data & (0x8000 >> i))
		{
			DS_PIN = 1;
		}
		else 
		{
			DS_PIN = 0;				
		}
		SH_CP_PIN = 0;
		SH_CP_PIN = 1;
	}
}

/*
LED行扫描
每次只显示一列
*/
static void led_row_scan(uint8_t index)
{
	HC154_ABCD_PIN = index;	
}

/*
图扫描
连续调用COLUMN_MAX次 
即可显示一幅图 COLUMN_MAX * ROW_MAX
*/
void led_picture_scan(const uint8_t *pic_data,int8_t col_offset)
{
	static uint8_t row_index = 0;
	const uint8_t *col_dat = pic_data + row_index * ROW_BYTE;
	
	led_column_scan(col_dat,col_offset);
	led_row_scan(row_index);
	ST_CP_PIN = 0;
	ST_CP_PIN = 1;

	row_index ++;
	row_index &= (COLUMN_MAX - 1);
}
