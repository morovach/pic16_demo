/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/
#define _XTAL_FREQ 8000000UL
#define BAUDRATE 9600

/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        _XTAL_FREQ
#define FCY             SYS_FREQ/4

//LCD SCREEN
#define DB7 RB6
#define DB6 RC6
#define DB5 RB4
#define DB4 RC3
#define  EN RC0
#define  RS RA2

/******************************************************************************/
/* System structure definition                                                 */
/******************************************************************************/
typedef enum {
    OK      ,
    SIZEERR ,
    MISC_ERR

}  err_t;



/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
void system_init(void);
void initUart(void);

/******************************************************************************/
/*custom define                                                               */
/******************************************************************************/
#define DBG_LVL 0
#define INFO_LVL 1
#define ALARM_LVL 2

/******************************************************************************/
/* Global varriable instanciation                                             */
/******************************************************************************/
