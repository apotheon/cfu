#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc == 1) {
		puts("USAGE: fizzbuzz <num> [num [...]]");
	} else if (argc > 1) {
		for (int n = 1; n < argc; ++n) {
			unsigned long num = strtoul(*(argv + n), NULL, 0);

			if (num > 0) {
				for (unsigned long i = 1; i <= num; ++i) {
					if ((i % 3) == 0) printf("fizz");
					if ((i % 5) == 0) printf("buzz");
					if (((i % 3) != 0) && ((i % 5) != 0)) printf("%lu", i);
					puts("");
				}
			}
		}
	}

	return 0;
}
