#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int xoradd(char *x_arg, char *y_arg) {
	long long x, y;
	const char *errstr;

	x = strtonum(x_arg, -1024, 1024, &errstr);
	if (errstr != NULL) {
		errx(1, "%s: %s", errstr, x_arg);
		return 1;
	}

	y = strtonum(y_arg, -1024, 1024, &errstr);
	if (errstr != NULL) {
		errx(1, "%s: %s", errstr, y_arg);
		return 1;
	}

	printf("%lld, %lld\n", x, y);

	while (y != 0) {
		long long carry = x & y;

		x = x ^ y;
		y = carry << 1;
	}

	printf("%lld\n", x);

	return 0;
}

int main(int argc, char **argv) {
	int help_opt = 0;

	if (argc == 3) {
		return xoradd(*(argv + 1), *(argv + 2));
	} else if (argc == 4) {
		help_opt = help(*(argv + 1));

		/*
		int recurse = 0;
		if (strncmp(*(argv + 1), "-r", 8) == 0) ++recurse;
		if (strncmp(*(argv + 1), "--recurse", 8) == 0) ++recurse;
		if (strncmp(*(argv + 1), "recurse", 8) == 0) ++recurse;
		*/
	} else {
		print_help();
	}

	return 0;
}
