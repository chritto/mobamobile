#ifndef _RUN_RUN_H_
#define _RUN_RUN_H_

#include "game/game.h"
#include "input/input.h"

typedef struct runnable_impl runnable;
typedef struct runnable_client_impl
{
    // The game state
    game *game;

    // Callback to render the game state
    void (*render)(game *g);
    user_input *(*get_input)(void);
} runnable_client;

// Run a game with a client struct for rendering/input etc
runnable *run_begin(runnable_client *client);

// Client function wrappers
void render_client(runnable_client *client);
user_input *get_input(runnable_client *client);

#endif // _RUN_RUN_H_
