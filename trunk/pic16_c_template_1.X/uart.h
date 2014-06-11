/* 
 * File:   uart.h
 * Author: moise
 *
 * Created on 11 juin 2014, 22:19
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

void uart_putc(unsigned char data);
void uart_printf(char * string);
unsigned char uart_getc(void);
char * uart_get_str(void);
void __interrupt ISR(void);
