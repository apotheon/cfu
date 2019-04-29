#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <unistd.h>

int main () {
	static char *buf;
	static size_t bufsz;

	if (bufsz < MAXBSIZE && (buf = realloc(buf, MAXBSIZE)) == NULL) {
		err(1, NULL);
	}

	int fd;
	struct stat sbuf;
	FILE *stream;
	ssize_t len;

	while ((len = getline(&buf, &bufsz, stream)) > 0) {
		/* do stuff */
		puts("do stuff here");
	}

	return 0;
}
