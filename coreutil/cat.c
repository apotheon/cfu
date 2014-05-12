#include <stdio.h>

void usage(char *arg) {
	printf("usage: %s [-huv] [file [...]]\n", arg);
	printf("    concatenate and print files\n");
	printf("\n");
	printf("OPTIONS:\n");
	printf("     -h      Print this help information.\n");
	printf("     -u      Disable output buffering.\n");
	printf("     -v      Print version information.\n");
}

void version(char *arg) {
	printf("%s v0.1\n", arg);
}

int main(int argc, char *argv[]) {
	return 0;
}
