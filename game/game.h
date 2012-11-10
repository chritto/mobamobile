#ifndef _GAME_GAME_H_
#define _GAME_GAME_H_

#include "player/player.h"
#include "input/input.h"

typedef struct game_impl game;

// Create a game with players
game *game_create(player **players, int num_players);

// Set the current input command (move, attack, etc)
void game_set_input(game *g, user_input *input);

// Iterates on the game state based on the time that has passed
void game_update_state(game *g);

#endif // _GAME_GAME_H_
