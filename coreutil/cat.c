#include <stdio.h>
#include <string.h>

void usage() {
	puts("");
	puts("usage: cat [-huv] [file [...]] [post-options]");
	puts("");
	puts("Concatenate and print files.");
	puts("");
	puts("OPTIONS:");
	puts("     --help");
	puts("     -h      Print this help information.");
	puts("");
	puts("     --unbuffered");
	puts("     -u      Disable output buffering.");
	puts("");
	puts("     --version");
	puts("     -v      Print version information.");
	puts("");
	puts("POST-OPTIONS:");
	puts("     |nl     Number lines of output, starting at 1.");
	puts("");
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
