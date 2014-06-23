/* 
 * File:   game_timer.h
 * Author: moise
 *
 * Created on 16 juin 2014, 21:17
 */

#ifndef GAME_TIMER_H
#define	GAME_TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GAME_TIMER_H */

typedef enum {TIME_PER_GAME, TIME_PER_ROUND} game_type_t;

typedef struct player_t
{
    unsigned char player_number;
    unsigned int played_time;
    struct player_t * next_player;
}player;








int initiate_game ( char player_nb,
                      game_type_t type_of_game,
                      unsigned int game_time);


void game_phase();
void switch_player();
void display_player_nbr(unsigned char player_number);