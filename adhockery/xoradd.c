#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int help(char *option);
int recurse(char *option);
int print_help();
long long i_add(long long x, long long y);
long long r_add(long long x, long long y);
int xoradd(char *x_arg, char *y_arg, int r_opt);

int main(int argc, char **argv) {
	int r_opt = 0;

	if (help(*(argv + 1))) {
		return print_help();
	} else if (recurse(*(argv + 1))) {
		++r_opt;
	}

	if ((argc == 3) || ((argc == 4) && r_opt)) {
		return xoradd(*(argv + 1 + r_opt), *(argv + 2 + r_opt), r_opt);
	} else {
		return print_help();
	}
}

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

int print_help() {
	puts("USAGE: xoradd <-h|--help|help>");
	puts("              [-r|--recurse|recurse] <num1> <num2>");
	puts("");
	puts("This program produces the sum of the numbers <num1> and <num2>");
	puts("using the xor operator instead of the addition operator.");
	puts("");
	puts("The recurse option instructs xoradd to use xor recursively to add");
	puts("the provided numbers, instead of iteratively.");
	puts("");
	puts("The help option displays this help text and exits.");

	return 0;
}

long long i_add(long long x, long long y) {
	while (y != 0) {
		long long carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}

	return x;
}

long long r_add(long long x, long long y) {
	if (y == 0) return x;
	else return r_add(x ^ y, (x & y) << 1);
}

int xoradd(char *x_arg, char *y_arg, int r_opt) {
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

	printf("%lld + %lld = ", x, y);
	printf("%lld\n", (r_opt ? r_add(x, y) : i_add(x, y)));

	return 0;
}
