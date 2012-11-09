#include <stdlib.h>

#include "util/log.h"
#include "game.h"

struct game_impl
{
};

game *game_create(player **players, int num_players)
{
    debug_log("Creating a game with [players:%d]", num_players);

    game *g = (game *) malloc(sizeof(game));
    if (!g)
        return NULL;

    return g;
}
