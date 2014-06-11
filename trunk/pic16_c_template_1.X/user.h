/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

void wait_1_ms(void);
void delay_ms(int delay_ms);
void wait_1_sec(void);
void UART_send_char(unsigned char c);
void putch_JEC(unsigned char data);