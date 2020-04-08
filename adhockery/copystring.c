#include <stdio.h>
#include <stdlib.h>

char *copystr(char *dest, const char *source);

int main() {
	int units = 16;

	char *arr0 = calloc(units, sizeof(*arr0));
	printf("copystr:        %s\n", copystr(arr0, "Copy my string."));
	free(arr0);

	return 0;
}

char *copystr(char *dest, const char *source) {
	int i = 0;

	do {
		*(dest + i) = *(source + i);
		++i;
	} while (*(source + i));

	return dest;
}
