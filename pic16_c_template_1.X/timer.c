#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include "timer.h"
#include "system.h"

void init_timer_0(){
    //Timer mode, clocked by the system clock (Fosc/4)
    OPTION_REGbits.T0CS = 0;
    //Enable the prescaler
    OPTION_REGbits.PSA = 0;
    //Prescaler = 256
    OPTION_REGbits.PS = 0x7;
        //Final clock of the timer: 8MHz /(4 *256) = 8 KHz;
}
    
void init_timer_1(){

    //Chose internal clock
    T1CONbits.TMR1CS = 0;
    //Prescaler = 2
    T1CONbits.T1CKPS = 1;
    //The timer will then increment each 8 system clock cycle.
    //(if sys_clk = 8MHz => it will tick at 1 Mhz)

    //Enable the gate of the timer 1
    T1CONbits.TMR1GE = 0;
    //Turn on the timer 1
    T1CONbits.TMR1ON = 1;


    TMR1 = 0;
    TMR1IF = 0;
    //Enable timer 1 interrupt
    PIE1bits.TMR1IE = 1;
}


void set_tick_period_timer1_us(unsigned period_us){
    //The counter is 16 bits, so the value of the overflow is 0x1000000UL
    //We have to counter the number of ticks to create an overflow:
    TMR1 = (0x10000UL - FCY/2/1000000UL*period_us);
    //TMR1 = 0xFE0C;
    //TMR1H = ((char)start_counter_value & 0xFF00) >> 8;
    //TMR1L = ((char)start_counter_value & 0x00FF);
    // = 0;
}





//This timer ticks every 10 ms
void init_timer_2(){
    TMR2ON = 1;
    
    
    // Set prescaler to 1:16
    T2CONbits.T2CKPS=3;

    //Set postscaler to 1 : 10
    T2CONbits.TOUTPS = 9;

    //we have to tick when we have counted :   Fosc/4/prescaler/1000
    PR2 = FCY/16/1000;
    
    //Enables interrupt
    PIE1bits.TMR2IE = 1;

}