#include <stdio.h>
#include <stdlib.h>

char *copystr(char *dest, const char *source);

int main() {
	int units = 16;
	char *arr = calloc(units, sizeof(*arr));

	copystr(arr, "Copy my string.");
	puts(arr);

	free(arr);

	return 0;
}

char *copystr(char *dest, const char *source) {
	int i = 0;

	do {
		*(dest + i) = *(source + i);
		++i;
	} while (*(source + i) != '\0');

	return dest;
}
