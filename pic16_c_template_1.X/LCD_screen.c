#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include "system.h"
#include "misc.h"

//LCD 4 Bit Interfacing Functions
void Lcd4_Port(char a)
{
	if(a & 1)
		DB4 = 1;
	else
		DB4 = 0;

	if(a & 2)
		DB5 = 1;
	else
		DB5 = 0;

	if(a & 4)
		DB6 = 1;
	else
		DB6 = 0;

	if(a & 8)
		DB7 = 1;
	else
		DB7 = 0;
}
void Lcd4_Cmd(char a)
{
    RS = 0;             // => RS = 0
    Lcd4_Port(a);
    EN  = 1;             // => E = 1
    __delay_ms(4);
    EN  = 0;             // => E = 0
}

Lcd4_Clear()
{
	Lcd4_Cmd(0);
	Lcd4_Cmd(1);
}

void Lcd4_Set_Cursor(char ligne, char pixel_nb)
{
    char lCmdMsb,lCmdLsb;
    lCmdMsb = 0x08 | (ligne <<2) | ( ((pixel_nb)& (0x30)) >> 4);
    lCmdLsb = pixel_nb & 0x0F;
    Lcd4_Cmd(lCmdMsb);
    Lcd4_Cmd(lCmdLsb);
}

void Lcd4_Init()
{

    RW = 0;
    RS = 0;

    __delay_ms(10);
    Lcd4_Cmd(0x02);

    //Two lines mode
    Lcd4_Cmd(0x02);
    Lcd4_Cmd(0x0C);

    //display on
    Lcd4_Cmd(0x00);
    Lcd4_Cmd(0x0F);

    //Clear display
     __delay_ms(10);

    //Clear display
    Lcd4_Clear();



}

void Lcd4_Write_Char(char a)
{
   char temp,y;
   temp = a&0x0F;
   y = a&0xF0;
	 RS = 1;             // => RS = 1
   Lcd4_Port(y>>4);             //Data transfer
__delay_ms(5);
   EN = 1;
	 __delay_ms(5);
	 EN = 0;
	 Lcd4_Port(temp);
	 EN = 1;
	 __delay_ms(5);
	 EN = 0;
}

void Lcd4_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 Lcd4_Write_Char(a[i]);
        LOG(a,0);
}

void Lcd4_Shift_Right()
{
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x0C);
}

void Lcd4_Shift_Left()
{
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x08);
}
//End LCD 4 Bit Interfacing Functions
