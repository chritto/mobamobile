#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "run/run.h"
#include "game/game.h"
#include "math/vector.h"
#include "util/log.h"

#define CHRIS_USER_ID 0
#define JADE_USER_ID 1

void die();

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

    // Pass the game into a run loop
    runnable *r = run_begin(game);
    if (!r)
        die();

    // We collect user input here
    while (true) {
        sleep(1);
    }

    return 0;
}

void die()
{
    debug_log("Catastrophic error. Quitting.");
    exit(1);
}
