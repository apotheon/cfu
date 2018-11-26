#include <stdio.h>

int main() {
	int count = 1;
	float x = 0.1;

	while (count <= 500) {
		x += 0.1;
		++count;
	}

	puts("\n  If you expect decimal arithmetic behavior from your IEEE 457");
	puts("  floating point numbers, you will eventually be disappointed.\n");
	printf("                      %d != %d\n\n", (int)(x * 10), count);

	return 0;
}
