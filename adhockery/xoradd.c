#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int help(char *option) {
	if (strncmp(option, "-h", 8) == 0) return 1;
	else if (strncmp(option, "--help", 8) == 0) return 1;
	else if (strncmp(option, "help", 8) == 0) return 1;
	else return 0;
}

int recurse(char *option) {
	if (strncmp(option, "-r", 16) == 0) return 1;
	else if (strncmp(option, "--recurse", 16) == 0) return 1;
	else if (strncmp(option, "recurse", 16) == 0) return 1;
	else return 0;
}

void print_help() {
	puts("USAGE: xoradd <-h|--help|help>");
	puts("              <number1> <number2>");
	puts("");
	puts("This program produces the sum of the numbers <number1> and");
	puts("<number2> using the xor operator instead of the addition operator.");
}

long long iterative_add(long long x, long long y) {
	while (y != 0) {
		long long carry = x & y;

		x = x ^ y;
		y = carry << 1;
	}

	return x;
}

int xoradd(char *x_arg, char *y_arg, int recurse_opt) {
	long long x, y;
	const char *errstr;

	x_arg = x_arg + recurse_opt;
	x = strtonum(x_arg, -1024, 1024, &errstr);

	if (errstr != NULL) {
		errx(1, "%s: %s", errstr, x_arg);
		return 1;
	}

	y_arg = y_arg + recurse_opt;
	y = strtonum(y_arg, -1024, 1024, &errstr);

	if (errstr != NULL) {
		errx(1, "%s: %s", errstr, y_arg);
		return 1;
	}

	printf("%lld + %lld = ", x, y);
	printf("%lld\n", iterative_add(x, y));

	return 0;
}

int main(int argc, char **argv) {
	int recurse_opt = 0;

	if (help(*(argv + 1))) {
		print_help();
	} else if (recurse(*(argv + 1))) {
		++recurse_opt;
	} else if (argc >= 3) {
		return xoradd(*(argv + 1), *(argv + 2), recurse_opt);
	} else {
		print_help();
	}

	return 0;
}
