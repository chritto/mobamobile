#ifndef _GAME_GAME_H_
#define _GAME_GAME_H_

#include "../player/player.h"

typedef struct game_impl game;

// Create a game with players
game *game_create(player **players, size_t num_players);

#endif // _GAME_GAME_H_
