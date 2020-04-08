#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copystr(char *dest, const char *source);
int cpstr_bylen(char *dest, int len, const char *source);

int main() {
	int units = 16;

	char *arr0 = calloc(units, sizeof(*arr0));
	printf("copystr:        %s\n", copystr(arr0, "Copy my string."));
	free(arr0);

	puts("");

	char *arr1 = calloc(units, sizeof(*arr1));
	printf(
		"cpstr_bylen:    %i char difference\ncopied text:    %s\n",
		cpstr_bylen(arr1, (units - 1), "Copy my string."),
		arr1
	);
	free(arr1);

	puts("");

	char *arr2 = calloc(units, sizeof(*arr2));
	printf(
		"cpstr_bylen:    %i char difference\ncopied text:    %s\n",
		cpstr_bylen(arr2, (units - 1), "Copy as much of my string as you can."),
		arr2
	);
	free(arr2);

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

int cpstr_bylen(char *dest, int len, const char *source) {
	int i = 0;

	do {
		*(dest + i) = *(source + i);
		++i;
	} while (*(source + i) && (i < len));

	if (i >= len) return strlen(dest) - strlen(source);
	else return 0;
}
