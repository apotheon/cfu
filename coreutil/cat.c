#include <stdio.h>
#include <string.h>

void usage() {
	puts("");
	puts("usage: cat [-huv] [file [...]] [post-options]");
	puts("");
	puts("Concatenate and print files.");
	puts("");
	puts("OPTIONS:");
	puts("");
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
	puts("");
	puts("     |sed -n '/./,/^$/p'");               /* -s */
	puts("             Squeeze multiple adjacent empty lines.");
	puts("");
	puts("     |sed -n l");                         /* -e */
	puts("             Display non-printing character escapes, and");
	puts("             dollar signs \"$\" indicating ends of lines.");
	puts("");
	puts("     |nl -ba");                           /* -n */
	puts("             Number lines of output, starting at 1.");
	puts("");
	puts("     |nl");                               /* -b */
	puts("             Number non-empty output lines, starting at 1.");
	puts("");

	/* additional needed post-options:
	 *
	 * -t      Display non-printing characters (see the -v option), and
	 *         display tab characters as ‘^I’.
	 *
	 * -v      Display non-printing characters so they are visible.  Control
	 *         characters print as ‘^X’ for control-X; the delete character
	 *         (octal 0177) prints as ‘^?’.  Non-ASCII characters (with the
	 *         high bit set) are printed as ‘M-’ (for meta) followed by the
	 *         character for the low 7 bits.
	 */
}

void version() {
	puts("0.1");
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
