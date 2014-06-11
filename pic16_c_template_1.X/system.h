/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/
#define _XTAL_FREQ 8000000L
#define BAUDRATE 9600

/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        SYS_FREQ
#define FCY             SYS_FREQ/4

/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
void initUart(void);