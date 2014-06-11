
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdio.h>
#include <string.h>
#include "uart.h"


/*void UART_send_char(unsigned char c){
    //TX uart not empty
    while(!TXSTAbits.TRMT)
        continue;
    TXREG=c;
    //TX uart not empty
    while(!TXSTAbits.TRMT)
        continue;
}*/


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

char * uart_get_str(void)
{
    char * result;
    int i = 0;
    while(!RCIF)
    {
        result[i]=uart_getc();
        i++;
    }
}


