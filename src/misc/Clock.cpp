#include "Clock.h"
/*
unsigned long long getMicroseconds() {
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}


double CPUTime(void) {
	return clock() / CLOCKS_PER_SEC;
}

long long MilliTime(void) {
	return time(NULL);
}

long long MicroTime(void) {
	struct timeval time;
}
*/

long long time(int unit) {
	switch (unit) {
	case MILLISECOND: {
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}break;
	case MICROSECOND: {
		return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}break;
	case NANOSECOND: {
		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}break;
	default: {
		return 0;
	}break;
	}
}

void stop(long long duration, int unit) {
	long long end = time(unit) + duration;
	while (time(unit) < end) {}
}

long long delta, stime, etime;

void start(int unit) {
	stime = time(unit);
}

long long end(int unit) {
	etime = time(unit);
	delta = etime - stime;
	return delta;
}
