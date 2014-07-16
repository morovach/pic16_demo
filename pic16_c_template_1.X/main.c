/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/



#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "uart.h"
#include "LCD_screen.h"
#include "timer.h"
#include "game_timer/header/game_timer.h"
/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
    system_init();
    initiate_game(2,TIME_PER_GAME,900U);

    while(1)
    {
        ;
    }
}
