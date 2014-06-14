/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/
#define _XTAL_FREQ 8000000UL
#define BAUDRATE 9600

/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        _XTAL_FREQ
#define FCY             SYS_FREQ/4

#if 1
//LCD SCREEN
#define DB7 RB6
#define DB6 RC6
#define DB5 RB4
#define DB4 RC3
#define DB3 RC2
#define DB2 RC4
#define DB1 RC1
#define DB0 RC5
#define  EN RC0
#define  RS RA2
#define  RW RA5
#endif


#if 0
//LCD SCREEN
#define DB7 RB6
#define DB6 RB4
#define DB5 RC2
#define DB4 RC1
#define DB3 RC0
#define DB2 RA2
#define DB1 RA3
#define DB0 RC6
#define  EN RC3
#define  RW RC4
#define  RS RC5
#endif



/******************************************************************************/
/* System scruture definition                                                 */
/******************************************************************************/
typedef enum {
    OK      ,
    MISC_ERR

}  err_t;



/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
void initUart(void);