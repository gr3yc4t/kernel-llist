#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "utils.h"

/**
 * \brief   Initialize srand using the time in seconds and useconds.
 *          Sleep for 10usecs in order not to have the same useconds.
 */
void init_seed_srand(void)
{
    struct timeval t;

    // Sleep 10 usec in order 
    // not to have the same seed
    usleep(10);

    gettimeofday(&t, NULL);

    srand(t.tv_usec * t.tv_sec);
}

