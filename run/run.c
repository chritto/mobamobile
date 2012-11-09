#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#include "util/log.h"
#include "run.h"

struct runnable_impl
{
    pthread_t run_thread;
};

void *run_begin_in_new_thread(void *p);

runnable *run_begin(game *g)
{
    debug_log("Starting the main run loop");

    runnable *r = (runnable *)malloc(sizeof(runnable));

    // We start a new thread for the main game loop
    int err = pthread_create(&r->run_thread, NULL, run_begin_in_new_thread, g);
    if (err)
    {
        debug_log("Unable to create a run loop for the game");
        free(r);
        return NULL;
    } else {
        return r;
    }
}

void *run_begin_in_new_thread(void *p)
{
    game *g = (game *)p;
    (void)g;
    debug_log("Inside the game loop thread");

    while (true)
    {
        debug_log("Tick");
        sleep(1);
    }

    return NULL;
}
