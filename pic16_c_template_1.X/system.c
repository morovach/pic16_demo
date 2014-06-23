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
#include "interrupt.h"
#include "timer.h"
#include "uart.h"
#include "LCD_screen.h"
#include "game_timer/header/game_timer.h"

/******************************************
 Global variable definition
 */
char glog_level = INFO_LVL;
game_type_t gtype_of_game = TIME_PER_ROUND;
unsigned int ggame_time = 0;
player * gcurrent_player;
player player_array[10];

/* Refer to the device datasheet for information about available
oscillator configurations. */
void ConfigureOscillator(void)
{

    //Timer is set to 8MHz
    OSCCONbits.SCS=0x1;
    OSCCONbits.IRCF=0x7;

    //Wait for the oscillator to be ready
    while(OSCCONbits.HTS==0)
    {
        ;
    }

}


void system_init(void){
    //Set all ports to be output
    TRISA = 0x0;
    TRISB = 0x0;
    TRISC = 0x0;

    //Put all values to 0
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;

    
    ConfigureOscillator();
    init_interrupt();
    init_timer_0();
    //init_timer_1();
    init_timer_2();
    initUart();

    __delay_ms(500);
    Lcd4_Init();
}
