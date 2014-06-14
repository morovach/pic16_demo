/* 
 * File:   LCD_screen.h
 * Author: moise
 *
 * Created on 13 juin 2014, 20:00
 */

#ifndef LCD_SCREEN_H
#define	LCD_SCREEN_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_SCREEN_H */

err_t test_screen_1L();
err_t test_screen_2L();



void Lcd8_Port(char a);
void Lcd8_Cmd(char a);
void Lcd8_Clear();
void Lcd8_Set_Cursor(char a, char b);
void Lcd8_Init();
void Lcd8_Write_Char(char a);
void Lcd8_Write_String(char *a);
void Lcd8_Shift_Right();
void Lcd8_Shift_Left();



void Lcd4_Port(char a);
void Lcd4_Cmd(char a);
void Lcd4_Clear();
void Lcd4_Set_Cursor(char a, char b);
void Lcd4_Init();
void Lcd4_Write_Char(char a);
void Lcd4_Write_String(char *a);
void Lcd4_Shift_Right();
void Lcd4_Shift_Left();