#include <stdlib.h>

#include "util/log.h"
#include "player.h"

struct player_impl
{
};

player *player_create(user_id user, champion_t champion_type, vector pos)
{
    debug_log("Creating a player for [userid:%d]", user);
    player *p = (player *)malloc(sizeof(player));
    if (!p)
        debug_log("Unable to create a player!");

    return p;
}
