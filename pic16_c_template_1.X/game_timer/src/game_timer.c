#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../header/game_timer.h"
#include "../../system.h"
#include "../../LCD_screen.h"
#include "../../misc.h"

int initiate_game ( char player_nb,
                      game_type_t type_of_game,
                      unsigned int game_time){

    extern game_type_t gtype_of_game;
    extern unsigned int ggame_time;
    extern player * gcurrent_player;

    extern player player_array[10];

    //We create a circular list so that it is easy to catch the next player
    for (int i =0;i<player_nb;i++)
    {
        player_array[i].played_time = 0;
        player_array[i].player_number = i;
        player_array[i].next_player = &player_array[(i+1)%player_nb];
    }

    gcurrent_player = &player_array[0];
    display_player_nbr(gcurrent_player->player_number);

    gtype_of_game = type_of_game;
    ggame_time = game_time;

    return OK;
}

void game_phase(){
    extern player * gcurrent_player;
    extern unsigned int ggame_time;
    unsigned int remaining_time;
    char time_str[9];
    extern char gGameIsStarted;

    if (gGameIsStarted)
    {
        (gcurrent_player->played_time) ++;
        remaining_time = ggame_time - (gcurrent_player->played_time);
        time_shapping(time_str, remaining_time);
        Lcd4_Set_Cursor(0,0);
        Lcd4_Write_String(time_str);
    }

}

void switch_player(){
    extern player * gcurrent_player;
    extern game_type_t gtype_of_game;

    gcurrent_player = (gcurrent_player->next_player);
    display_player_nbr(gcurrent_player->player_number);
    if (gtype_of_game == TIME_PER_ROUND)
    {
    gcurrent_player->played_time = 0;
    }
}

void display_player_nbr(unsigned char player_number)
{
    char string[16];
    char string_player_number [2];
    strcpy(string, "Joueur ");
    utoa(string_player_number,player_number,10);
    strcat (string, string_player_number);

    Lcd4_Set_Cursor(1,0);
    Lcd4_Write_String(string);
}