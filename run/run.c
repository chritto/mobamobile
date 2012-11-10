#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

#include "util/log.h"
#include "run/run.h"
#include "game/game.h"

struct runnable_impl
{
    pthread_t run_thread;
};

void *run_begin_in_new_thread(void *p);

runnable *run_begin(runnable_client *client)
{
    debug_log("Starting the main run loop");
    assert(client);

    runnable *r = (runnable *)malloc(sizeof(runnable));

    // We start a new thread for the main game loop
    int err = pthread_create(&r->run_thread, NULL, run_begin_in_new_thread, client);
    if (err)
    {
        debug_log("Unable to create a run loop for the game");
        free(r);
        return NULL;
    } else {
        // Let's wait for the thread to exit
        pthread_join(r->run_thread, NULL);
        return r;
    }
}

void *run_begin_in_new_thread(void *p)
{
    debug_log("Inside the game loop thread");
    assert(p);

    runnable_client *client = (runnable_client *)p;
    game *g = client->game;

    while (true)
    {
        debug_log("Tick");

        // Take in user input
        user_input *input = get_input(client);
        game_set_input(g, input);

        // Iterate on the game state
        game_update_state(g);

        // Render the game in the client
        render_client(client);
        sleep(1);
    }

    return NULL;
}

void render_client(runnable_client *client)
{
    assert(client);
    assert(client->render);
    assert(client->game);
    client->render(client->game);
}
user_input *get_input(runnable_client *client)
{
    return client->get_input();
}
