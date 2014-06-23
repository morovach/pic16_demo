
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "system.h"


/*void UART_send_char(unsigned char c){
    //TX uart not empty
    while(!TXSTAbits.TRMT)
        continue;
    TXREG=c;
    //TX uart not empty
    while(!TXSTAbits.TRMT)
        continue;
}*/


void initUart(void)
{

    PIE1bits.RCIE =1;

    TXSTAbits.TXEN = 0;
    //The baudrate for the UART is : FOSC/((64*[SPBRGH:SPBRG])+1) where : means a concatenation
    //Here we have thus a 9600 bauds for the UART

    SPBRG  = (_XTAL_FREQ/BAUDRATE/64)-1;
    //SPBRG  = 12;
    SPBRGH = 0x00;

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


void uart_putc(unsigned char data) {
    while( ! TXIF) // check buffer
    continue; // wait till ready
    TXREG = data; // send data
}



void uart_printf(char * string){
    int i = 0;
    for (i=0; i<strlen(string); i++){
        uart_putc(string[i]);
    }
}

unsigned char uart_getc(void){
    if (RCSTAbits.OERR){
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
    }

    while(!RCIF)
        ;
    return RCREG;
}

int uart_get_str(char * buffer)
{
    int i = 0;
    while(!RCIF)
    {
        if (buffer[i])
        {
            buffer[i]=uart_getc();
            if (buffer[i]== '\0')
            {
                return OK;
            }
            i++;
        }
        else
        {
            return SIZEERR;
        }
    }
    return OK;
}


