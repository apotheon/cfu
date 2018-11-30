#include <stdio.h>

int main() {
	for (uint8_t i = 1; i <= 100; ++i) {
		if (i % 3 == 0) printf("Fizz");
		if (i % 5 == 0) printf("Buzz");
		if ((0 < i % 3) && (0 < i % 5)) printf("%d", i);
		puts("");
	}

	return 0;
}
