/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/



#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <stdio.h>
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

#include<pic.h>


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

    unsigned char sender=0x41;
    int j=1;

    while(1)
    {

        __delay_ms(500);
        PORTC = j;
        j = (j<<1) % 0x0F;

       
        putch_JEC(sender);
        //sender++;




    }

}

