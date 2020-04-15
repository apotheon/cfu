#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * This is a naive implementation, in that it bases its count on Unix time   *
 * seconds.  Ideally, it should instead check for millions of microseconds   *
 * since the last tick.  Given the only one-second precision based on clock  *
 * time, the first "second" may actually range anywhere from about a second  *
 * down to about zero seconds.  Subsequent seconds should be of fairly       *
 * accurate length, at a 100 microsecond level of precision.                 *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void usage(char *cmdtxt);
void tickprint(long long sec);

int main(int argc, char **argv) {
	if (argc == 2) {
		char **endptr = calloc(1000, sizeof(endptr));
		long long seconds = strtoll(*(argv + 1), endptr, 10);

		if (strnlen(*endptr, 2) == '\0') {
			time_t curtime = time(NULL);
			time_t newtime = 0;

			tickprint(seconds);

			while (seconds > 0) {
				usleep(100);
				newtime = time(NULL);

				if ((newtime - curtime) >= 1) {
					curtime = newtime;
					--seconds;
					tickprint(seconds);
				}
			}

			printf("\r\aTIME'S UP!\n");
		} else {
			usage(*argv);
		}
	} else {
		usage(*argv);
	}

	return 0;
}

void usage(char *cmdtxt) {
	printf("%s: downcounter <NUM>\n", cmdtxt);
	puts("        Count down from NUM to 0, and beep.");
}

void tickprint(long long sec) {
	printf("\r%lld\t", sec);
	fflush(stdout);
}
