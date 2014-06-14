/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/



#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif
#include <string.h>
#include <stdio.h>



#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "uart.h"
#include "LCD_screen.h"
/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{



    /* Configure the oscillator for the device */
    ConfigureOscillator();

    initUart();


    //TRISA = 0xFF; // set all port D bits to be output

    TRISC = 0x0; // set all port D bits to be output
    PORTC = 0x0;


    char * string;
    strcpy(string, "end of line\n");

    int j=1;

    TRISA = 0x0;
    TRISB = 0x0;
    TRISC = 0x0;

    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;

    __delay_ms(2000);

    Lcd4_Init();
    char character = 0x49;
    char address = 0x00;
    Lcd4_Cmd(0x08);
    Lcd4_Cmd(address);
    int i = 0;
    while(1){

    //SSet DDR ADDRESS TO 0
    

    Lcd4_Cmd(0x08);
    Lcd4_Cmd(address);
    __delay_ms(10);
    
    Lcd4_Write_String("salut");

    __delay_ms(500);

     for(i=0;i<15;i++){
         Lcd4_Shift_Right();
         __delay_ms(300);
     }
    
     Lcd4_Clear();
    //RS =1;
    }

   



}
