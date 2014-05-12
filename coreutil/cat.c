#include <stdio.h>

void usage() {
	printf("usage: cat [-huv] [file [...]]\n");
	printf("    concatenate and print files\n");
	printf("\n");
	printf("OPTIONS:\n");
	printf("     -h      Print this help information.\n");
	printf("     -u      Disable output buffering.\n");
	printf("     -v      Print version information.\n");
}

void version() {
	printf("cat v0.1\n");
}

int main(int argc, char *argv[]) {
	return 0;
}
