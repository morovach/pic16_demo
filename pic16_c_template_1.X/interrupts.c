/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "interrupt.h"
#include "uart.h"
#include "timer.h"
#include "LCD_screen.h"
#include "misc.h"
#include "game_timer/header/game_timer.h"

#include <stdlib.h>

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Baseline devices don't have interrupts. Note that some PIC16's 
 * are baseline devices.  Unfortunately the baseline detection macro is 
 * _PIC12 */
#ifndef _PIC12

int timer1_tick_nbr =0;
int timer2_tick_nbr =0;
unsigned int elapsed_time = 0;

void init_interrupt(){
        //Enable interrupts
    INTCONbits.GIE = 1;
    INTCONbits.PEIE =1;
}

void interrupt isr(void)
{
    
    //UART receiver interrupt
    if (PIR1bits.RCIF)
    {

        if (RCSTAbits.FERR)
        {
            RCSTAbits.SPEN = 0;
            RCSTAbits.SPEN = 1;
            return;
        }
        /*****************************
         *  Put action below
         * **************************/
        uart_putc(uart_getc());
        switch_player();
        return;
        /*****************************
         *  Stop of action
         * **************************/
    }

    //Timer 1 interrupt
    if (TMR1IF)
    {
        char string [8];
        TMR1IF = 0;
        set_tick_period_timer1_us(1000);
        timer1_tick_nbr ++;
        if (timer1_tick_nbr== 1000){
            timer1_tick_nbr = 0;
            elapsed_time++;
            RC2 = 1- RC2;
            utoa (string, elapsed_time, 10);
            Lcd4_Set_Cursor(0,0);
            Lcd4_Write_String(string);
        }
        return;
    }

    //Prefer to use the timer 2 for a periodic time because we don't
    //have to reinitialize the counter every time it is done by hardware
    if (TMR2IF)
    {
        char string [9];

        TMR2IF = 0;
        timer2_tick_nbr ++;
        //The timer 2 ticks every 0.010 second => *100 = 1s
        if (timer2_tick_nbr== 100){
            timer2_tick_nbr = 0;
            elapsed_time++;
            RC2 = 1- RC2;
            game_phase();
        }
        
        return;
    }

}
#endif


