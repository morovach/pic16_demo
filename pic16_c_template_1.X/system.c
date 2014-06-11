/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"

/* Refer to the device datasheet for information about available
oscillator configurations. */
void ConfigureOscillator(void)
{

    //Timer is set to 4MHz
    OSCCONbits.SCS=0x1;
    OSCCONbits.IRCF=0x6;

    //Timer mode, clocked by the system clock (Fosc/4)
    OPTION_REGbits.T0CS = 0;
    //Enable the prescaler
    OPTION_REGbits.PSA = 0;
    //Prescaler = 256
    OPTION_REGbits.PS = 0x7;

    //Final clock of the timer: 8MHz /(4 *256) = 8 KHz;

    //Wait for the oscillator to be ready
    while(OSCCONbits.HTS==0)
    {
        ;
    }

}


void initUart(void)
{
    TXSTAbits.TXEN = 0;
    //The baudrate for the UART is : FOSC/((64*[SPBRGH:SPBRG])+1) where : means a concatenation
    //Here we have thus a 9600 bauds for the UART
    SPBRG  =   (_XTAL_FREQ/(BAUDRATE*64))-1;
    //SPBRGH = 0x00;

    ANSEL =0;
    ANSELH= 0;

    //Set RX pin as input and TX as output
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB7 = 0;

    //PUT the UART in Asynchronous mode and enables it

    //8Bits in a frame
    TXSTAbits.TX9 = 0;

    //Asynchronous
    TXSTAbits.SYNC = 0;
    TXREG = 0;

    //On divise la frequence d'horloge par 64
    TXSTAbits.BRGH = 0;
    BAUDCTLbits.BRG16 = 0;
    
    BAUDCTLbits.ABDEN = 0;

    //Reset the uart and enable it
    //Enable the USART TX RX and Whole block
    
    TXSTAbits.TXEN = 1;
    RCSTAbits.CREN = 1;
    RCSTAbits.SPEN = 1;


}