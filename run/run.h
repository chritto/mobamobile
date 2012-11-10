#ifndef _RUN_RUN_H_
#define _RUN_RUN_H_

#include "game/game.h"
#include "input/input.h"

typedef struct runnable_impl runnable;
typedef struct runnable_client_impl
{
    // Callback to render the game state
    void (*render)(game *g);
    user_input *(*get_input)(void);
} runnable_client;

// Run a game with a client struct for rendering/input etc
runnable *run_begin(game *g, runnable_client *client);

#endif // _RUN_RUN_H_
