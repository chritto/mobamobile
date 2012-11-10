#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "run/run.h"
#include "game/game.h"
#include "math/vector.h"
#include "util/log.h"
#include "run/run.h"

#define CHRIS_USER_ID 0
#define JADE_USER_ID 1

void die();
void render(game *g);
user_input *collect_input(void);

int main(int argc, const char *argv[])
{
    // Create the players
    vector position = vector_create(0, 0, 0);
    player *chris = player_create(CHRIS_USER_ID, SINGED, position);

    position = vector_create(1, 1, 0);
    player *jade = player_create(JADE_USER_ID, JAYCE, position);

    if ((!chris) || (!jade))
        die();

    player *players[] = {chris, jade};

    // Create the game
    game *game = game_create(players, 2);
    if (!game)
        die();

    // Set up the client
    runnable_client client;
    client.game = game;
    client.render = render;
    client.get_input = collect_input;

    // Pass the game into a run loop. Does not return.
    runnable *r = run_begin(&client);
    if (!r)
        die();

    return 0;
}

void die()
{
    debug_log("Unrecoverable error. Quitting.");
    exit(1);
}

void render(game *g)
{
    debug_log("Rendering the game state");
}

user_input *collect_input(void)
{
    debug_log("Collecting user input");
    return NULL;
}
