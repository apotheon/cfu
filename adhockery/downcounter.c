#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define MAXDIGITS 16

int invalidnum(char *numarg, long long seconds);
int negative(long long seconds);
int oversize(char *numarg);

void linedel();
void tickprint(long long sec);
void usage(char *cmdtxt);

int main(int argc, char **argv) {
	if (argc != 2) {
		usage(*argv);
	} else {
		char **endptr = calloc(2, sizeof(endptr));
		long long seconds = strtoll(*(argv + 1), endptr, 10);

		if ((strnlen(*endptr, 2) != '\0') || invalidnum(*(argv + 1), seconds)) {
			usage(*argv);
		} else {
			time_t curtime = time(NULL);
			time_t newtime = 0;

			puts("");
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

			linedel();
			puts("\aTIME'S UP!\n");
		}
	}

	return 0;
}

int invalidnum(char *numarg, long long seconds) {
	return (oversize(numarg) || negative(seconds));
}

int negative(long long seconds) {
	if (seconds >= 0) return 0;
	else return 1;
}

int oversize(char *numarg) {
	if (strnlen(numarg, MAXDIGITS * 2) <= MAXDIGITS) return 0;
	else return 1;
}

void linedel() {
	printf("\33[2K\r");
	fflush(stdout);
}

void tickprint(long long sec) {
	linedel();
	printf("\t%lld\t", sec);
	fflush(stdout);
}

void usage(char *cmdtxt) {
	puts("USAGE:");
	printf("     %s <NUM>\n\n", cmdtxt);

	puts("DESCRIPTION:");
	printf("     Count down from NUM to 0, and beep.\n\n");

	puts("ARGUMENTS/OPTIONS:");
	printf("     NUM must be a positive base-10 number no more than ");
	printf("%d digits long.\n\n", MAXDIGITS);
	printf("     For any other argument, or for a missing argument, ");
	printf("print this message.\n\n");

	puts("CAVEATS:");
	printf("     This implementation is based on (Unix) clock time, not ");
	printf("the amount of\n");
	printf("     time that has elapsed.  As a result, the length of the ");
	printf("first \"second\"\n");
	printf("     lies in a range between zero seconds and one second.  ");
	printf("All subsequent\n");
	printf("     \"seconds\" should be of fairly accurate duration, to a ");
	printf("100 microsecond\n");
	printf("     level of precision.\n\n");
}
