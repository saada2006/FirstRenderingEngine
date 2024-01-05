#ifndef CLOCK_H
#define CLOCK_H

#include <time.h>
#include <chrono>

#define MILLISECOND 1000
#define MICROSECOND 1000000
#define NANOSECOND 1000000000

long long time(int unit);
void stop(long long time, int unit);
void start(int unit);
long long end(int unit);

#endif