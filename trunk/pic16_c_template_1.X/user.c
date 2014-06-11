/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */


//This function waits for 1 ms(8/8000 secs)
void wait_1_ms(void){
    //TMR0 will increment every tick. (See system.c to see what is a tick).
    //When it overflows to 0 we have waited 8 ticks.
    TMR0 = 0xF8;
    while (TMR0!=0xFF)
        {;}
}


void delay_ms(int delay){
    int i =0;
    for(i=0;i<(delay+1);i++){
        wait_1_ms();
    }
}


void wait_1_sec(void){
    int i=0;
    for (i=0;i<1000;i++)
    {
        wait_1_ms();
    }
}
