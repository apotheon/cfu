#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void usage(char *cmdtxt) {
	printf("%s: downcounter <NUM>\n", cmdtxt);
	puts("        Count down from NUM to 0, and beep.");
}

int main(int argc, char **argv) {
	if (argc == 2) {
		char **endptr = calloc(1000, sizeof(endptr));
		long long seconds = strtoll(*(argv + 1), endptr, 10);

		if (strnlen(*endptr, 2) == '\0') {
			time_t curtime = time(NULL);
			time_t newtime = 0;

			printf("%lld\t", seconds);
			fflush(stdout);

			while (seconds > 0) {
				usleep(100);
				newtime = time(NULL);

				if ((newtime - curtime) >= 1) {
					curtime = newtime;
					--seconds;
					printf("\r%lld\t", seconds);
					fflush(stdout);
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
