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

void game_set_input(game *g, user_input *input)
{
    debug_log("Setting the current user input");
}

// Iterates on the game state based on the time that has passed
void game_update_state(game *g)
{
    debug_log("Iterating on the game state");
}

