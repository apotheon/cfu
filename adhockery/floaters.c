#include <stdio.h>

int main() {
	int count = 1;
	float x = 0.1;

	while (count <= 500) {
		x += 0.1;
		++count;
	}

	if ((0.1 + 0.2) == 0.3) {
		puts("Everything is peachy!");
	} else {
		puts("\nIf you expect decimal arithmetic behavior from your IEEE 457");
		puts("floating point numbers, you will eventually be disappointed.\n");
		printf("             0.1 + 0.2 != %20.19f\n", 0.1 + 0.2);
		printf("                         %d != %d\n\n", (int)(x * 10), count);
	}

	return 0;
}