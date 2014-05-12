#include <getopt.h>
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
	int opt, optnum;
	int hflag, lflag;

	optnum = 1;

	hflag = lflag = 0;

	struct option longopts[] = {
		{ "help",       no_argument, NULL, 'h' },
		{ "unbuffered", no_argument, NULL, 'u' },
		{ "version",    no_argument, NULL, 'v' }
	};

	while ((opt = getopt_long(argc, argv, "hul", longopts, NULL)) != -1) {
		switch (opt) {
		case 'h':
			usage(argv[0]);
			++optnum;
			hflag = 1;
			break;
		case 'u':
			/* do something here */
			break;
		case 'v':
			version(argv[0]);
			++optnum;
			lflag = 1;
			break;
		default:
			if (hflag == 0) {
				usage(argv[0]);
				hflag = 1;
			}
		}
	}

	return 0;
}
