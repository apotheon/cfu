#include <stdio.h>
#include <string.h>

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
#define OPT(a) (strcmp(argv[i], a) == 0)
	for (int i = 1; i < argc; i++) {
		if (OPT("-h") || OPT("--help")) usage();

		if (OPT("-u") || OPT("--unbuffered")) {
			printf("Unbuffered use has not yet been implemented.\n");
		}

		if (OPT("-v") || OPT("--version")) version();
	}
	return 0;
}
