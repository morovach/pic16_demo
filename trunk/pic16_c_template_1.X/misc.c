#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "misc.h"
#include "uart.h"
#include "system.h"

#if 0
int itoh(int n){
    int i=0;
    int tot=0;
    while (n!=0)
    {
        tot+=pow(10,i)*(n%16);
        n /= 16;
        n = (int)trunc(n);
        i++;
    }
}
#endif

void time_shapping(char * buffer, int time){
    int secondes = time % 60;
    int minutes = (time%3600)/60;
    int hours = time / 3600;

    char secondes_buf [2];
    utoa (secondes_buf, secondes, 10);
    if (secondes_buf[1] == '\0')
    {
        secondes_buf [1] = secondes_buf [0];
        secondes_buf [0] = '0';
    }

    char minutes_buf [2];
    utoa (minutes_buf, minutes, 10);
    if (minutes_buf[1] == '\0')
    {
        minutes_buf [1] = minutes_buf [0];
        minutes_buf [0] = '0';
    }

    char hours_buf [2];
    utoa (hours_buf, hours, 10);
    if (hours_buf[1] == '\0')
    {
        hours_buf [1] = hours_buf [0];
        hours_buf [0] = '0';
    }

    buffer [0] = hours_buf [0];
    buffer [1] = hours_buf [1];
    buffer [2] = ':';
    buffer [3] = minutes_buf [0];
    buffer [4] = minutes_buf [1];
    buffer [5] = ':';
    buffer [6] = secondes_buf [0];
    buffer [7] = secondes_buf [1];
    buffer [8] = '\0';

}

void LOG(char * string, char level){
    extern char glog_level;
    if (level >= glog_level);
    {
        uart_printf(string);
    }
}