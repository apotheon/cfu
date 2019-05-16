#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long xoradd(long long x, long long y) {
	while (y != 0) {
		long long carry = x & y;

		x = x ^ y;
		y = carry << 1;
	}

	return x;
}

int help(char *option) {
	if (strncmp(option, "-h", 8) == 0) {
		return 1;
	} else if (strncmp(option, "--help", 8) == 0) {
		return 1;
	} else if (strncmp(option, "help", 8) == 0) {
		return 1;
	} else {
		return 0;
	}
}

void print_help() {
	puts("USAGE: xoradd <-h|--help|help>");
	puts("              <number1> <number2>");
	puts("");
	puts("This program produces the sum of the numbers <number1> and");
	puts("<number2> using the xor operator instead of the addition operator.");
	puts("");
	puts("If the <number1> an <number2> arguments are not numbers, something");
	puts("probably happens.");
}

int main(int argc, char **argv) {
	int help_opt = 0;

	if (argc == 3) {
		long long x, y;
		const char *errstr;

		x = strtonum(*(argv + 1), -1024, 1024, &errstr);
		if (errstr != NULL) {
			errx(1, "%s: %s", errstr, *(argv + 1));
			return 1;
		}

		y = strtonum(*(argv + 2), -1024, 1024, &errstr);
		if (errstr != NULL) {
			errx(1, "%s: %s", errstr, *(argv + 2));
			return 1;
		}

		printf("%lld, %lld\n", x, y);
		printf("%lld\n", xoradd(x, y));
	} else {
		print_help();
	}

	return 0;
}
