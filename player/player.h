#ifndef _PLAYER_PLAYER_H_
#define _PLAYER_PLAYER_H_

#include "user/user.h"
#include "champion/champion.h"
#include "math/vector.h"

typedef struct player_impl player;

// Creates a player
// user: The user id of the person controlling the player
// champion_type: The type of champion
// pos: The starting position of the player
player *player_create(user_id user, champion_t champion_type, vector pos);

#endif
