#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
	struct timeval current_time;
	gettimeofday(&current_time, NULL);

	printf("%lld%ld", current_time.tv_sec, current_time.tv_usec);
	if (isatty(fileno(stdout))) printf("\n");

	return 0;
}
