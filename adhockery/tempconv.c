#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_c(char *arg) {
	return (!strncmp(arg, "c", 2) || !strncmp(arg, "C", 2));
}

int is_f(char *arg) {
	return (!strncmp(arg, "f", 2) || !strncmp(arg, "F", 2));
}

void print_usage(char *command) {
	printf("USAGE: %s <INPUT> <TEMP> [TEMP [. . .]]\n", command);
	printf("       %s h[elp]\n", command);
	printf("       %s [-]h[elp]\n", command);
	printf("       %s --help\n", command);
	puts("");
	puts(
		"INPUT is \"c\" or \"f\" and indicates whether input TEMPs are\n"
		"celsius or fahrenheit, respectively.  All TEMPs must use the same\n"
		"temperature scale, and will be translated to the other scale.\n"
	);
	puts(
		"TEMP is a temperature number in the indicated scale.  All TEMPs\n"
		"will be translated to the other scale and printed.  Non-numeric\n"
		"values for TEMP are treated as 0.  Non-numeric suffices for TEMP\n"
		"are ignored.\n"
	);
	puts(
		"Any help command (h, help, -h, -help, or --help) or invalid usage\n"
		"syntax should result in printing this usage information.\n"
	);
}

void print_c2f(char *temp) {
	double tempnum = strtod(temp, NULL);
	printf("%f C = %f F\n", tempnum, tempnum * 9.0 / 5.0 + 32.0);
}

void print_f2c(char *temp) {
	double tempnum = strtod(temp, NULL);
	printf("%f F = %f C\n", tempnum, (tempnum - 32.0) * 5.0 / 9.0);
}

int main(int argc, char **argv) {
	if (argc > 2) {
		if (is_c(*(argv + 1))) {
			for (int i = 2; i < argc; ++i) print_c2f(*(argv + i));
		} else if (is_f(*(argv + 1))) {
			for (int i = 2; i < argc; ++i) print_f2c(*(argv + i));
		} else {
			print_usage(*(argv));
		}
	} else {
		print_usage(*(argv));
	}

	return 0;
}
