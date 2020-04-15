#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAXDIGITS 16

int invalidnum(char *numarg, char *end, long long seconds);
int negative(long long seconds);
int nonnumeric(char *end);
int oversize(char *numarg);

void linedel();
void tickprint(long long sec);
void usage();

int main(int argc, char **argv) {
	if (argc != 2) {
		usage();
		return 0;
	}

	char **endptr = calloc(2, sizeof(endptr));
	long long seconds = strtoll(*(argv + 1), endptr, 10);

	if (invalidnum(*(argv + 1), *endptr, seconds)) {
		usage();
		return 0;
	}

	free(endptr);

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

	return 0;
}

int invalidnum(char *numarg, char *end, long long seconds) {
	return (oversize(numarg) || nonnumeric(end) || negative(seconds));
}

int negative(long long seconds) {
	if (seconds >= 0) return 0;
	else return 1;
}

int nonnumeric(char *end) {
	return (strnlen(end, 2) != '\0');
}

int oversize(char *numarg) {
	if (strnlen(numarg, MAXDIGITS * 2) <= MAXDIGITS) return 0;
	else return 1;
}

void linedel() {
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
	 * "\33[2K" deletes all text on the present line; "\r" sends the cursor  *
	 * back to the beginning of the line.  This is necessary to allow the    *
	 * counter to appear to decrement in place.  Flushing stdout ensures all *
	 * non-displaying characters will actually print to clear the text.      *
	\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	printf("\33[2K\r");
	fflush(stdout);
}

void tickprint(long long sec) {
	linedel();
	printf("\t%lld\t", sec);
	fflush(stdout);
}

void usage() {
	puts("USAGE:");
	printf("     %s <NUM>\n\n", getprogname());

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
