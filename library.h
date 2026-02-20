#ifndef SAMPLE_LIBRARY_H
#define SAMPLE_LIBRARY_H

#include <time.h>
#include <sys/time.h>

static struct timeval us_start, us_end;

/* Start in microseconds */
void start()
{
    gettimeofday(&us_start, NULL);
}

/* Stop in microseconds */
double stop()
{
    gettimeofday(&us_end, NULL);

    double start_val = us_start.tv_sec  + us_start.tv_usec/1000000.0;
    double end_val   = us_end.tv_sec  + us_end.tv_usec/1000000.0;

    return end_val - start_val;
}


#endif
