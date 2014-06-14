#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include "system.h"


err_t test_screen(){

    EN = 0;
    __delay_ms(10);

    DB7 = 0;
    DB6 = 0;
    DB5 = 1;
    DB4 = 1;
    DB3 = 0;
    DB2 = 0;
    //DB1 = 0;
    DB0 = 0;

    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(10);
    EN = 0;
    __delay_ms(1);

    return OK;
}




err_t test_screen_2L(){
    
    EN = 0;
    __delay_ms(10);

    DB7 = 0;
    DB6 = 0;
    DB5 = 1;
    DB4 = 0;
    DB3 = 1;
    DB2 = 0;
    //DB1 = 0;
    DB0 = 0;
    
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(10);
    EN = 0;
    __delay_ms(1);

    return OK;
}



err_t test_screen_1L(){

    EN = 0;
    __delay_ms(10);

    DB7 = 0;
    DB6 = 0;
    DB5 = 0;
    DB4 = 1;
    DB3 = 0;
    DB2 = 0;
    //DB1 = 0;
    DB0 = 0;

    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(10);
    EN = 0;
    __delay_ms(1);

    return OK;
}





//LCD 8 Bit Interfacing Functions
void Lcd8_Port(char a)
{
	if(a & 1)
		DB0 = 1;
	else
		DB0 = 0;

	if(a & 2)
		DB1 = 1;
	else
		DB1 = 0;
        
	if(a & 4)
		DB2 = 1;
	else
		DB2 = 0;

	if(a & 8)
		DB3 = 1;
	else
		DB3 = 0;

	if(a & 16)
		DB4 = 1;
	else
		DB4 = 0;

	if(a & 32)
		DB5 = 1;
	else
		DB5 = 0;

	if(a & 64)
		DB6 = 1;
	else
		DB6 = 0;

	if(a & 128)
		DB7 = 1;
	else
		DB7 = 0;
}
void Lcd8_Cmd(char a)
{
  RS = 0;             // => RS = 0
  Lcd8_Port(a);             //Data transfer
  EN  = 1;             // => E = 1
  __delay_ms(5);
  EN  = 0;             // => E = 0
}

void Lcd8_Clear()
{
      Lcd8_Cmd(1);
}

void Lcd8_Set_Cursor(char a, char b)
{
	if(a == 1)
	  Lcd8_Cmd(0x80 + b);
	else if(a == 2)
		Lcd8_Cmd(0xC0 + b);
}

void Lcd8_Init()
{
	Lcd8_Port(0x00);
	RS = 0;
	__delay_ms(25);
	///////////// Reset process from datasheet /////////
  Lcd8_Cmd(0x30);
  __delay_ms(5);
  Lcd8_Cmd(0x30);
  __delay_ms(15);
  Lcd8_Cmd(0x30);
  /////////////////////////////////////////////////////
  Lcd8_Cmd(0x38);    //function set
  Lcd8_Cmd(0x0C);    //display on,cursor off,blink off
  Lcd8_Cmd(0x01);    //clear display
  Lcd8_Cmd(0x06);    //entry mode, set increment
}

void Lcd8_Write_Char(char a)
{
   RS = 1;             // => RS = 1
   Lcd8_Port(a);             //Data transfer
   EN  = 1;             // => E = 1
  __delay_ms(4);
   EN  = 0;             // => E = 04
}

void Lcd8_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	 Lcd8_Write_Char(a[i]);
}

void Lcd8_Shift_Right()
{
	Lcd8_Cmd(0x1C);
}

void Lcd8_Shift_Left()
{
	Lcd8_Cmd(0x18);
}
//End LCD 8 Bit Interfacing Functions











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

void Lcd4_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
	  temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		Lcd4_Cmd(z);
		Lcd4_Cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		Lcd4_Cmd(z);
		Lcd4_Cmd(y);
	}
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
    Lcd4_Cmd(0x00);
    Lcd4_Cmd(0x01);



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
