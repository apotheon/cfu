#include <stdio.h>
#include <string.h>

void usage() {
	puts("");
	puts("cat - concatenate and print files");
	puts("");
	puts("usage: cat [-u|--unbuffered] [file[ ...]] [post-options]");
	puts("       cat (-h|--help|--license|--version]");
	puts("");
	puts("The cat utility reads files sequentially, writing them");
	puts("to standard output.  The file operands are processed in");
	puts("command line order.  If file is a single dash or absent,");
	puts("cat reads from standard input.  If file is a Unix domain");
	puts("socket, cat connects to it and reads it until EOF.");
	puts("");
	puts("OPTIONS:");
	puts("");
	puts("     -h");
	puts("     --help");
	puts("             Print this help information.");
	puts("");
	puts("     --license");
	puts("             Print license text.");
	puts("");
	puts("     -u");
	puts("     --unbuffered");
	puts("             Disable output buffering.");
	puts("");
	puts("     --version");
	puts("             Print version information.");
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

void license() {
	puts("");
	puts("Copyright 2014 Chad Perrin");
	puts("");
	puts(
		"Permission is hereby granted by the holder(s) of copyright or other"
		"legal priv-\nileges, author(s) or assembler(s), and contributor(s)"
		"of this work, to any per-\nson who obtains a copy of this work in"
		"any form, to reproduce, modify, distrib-\nute, publish, sell,"
		"sublicense, use, and/or otherwise deal in the licensed mat-\nerial"
		"without restriction, provided the following conditions are met:"
	);
	puts("");
	puts(
		"Redistributions, modified or unmodified, in whole or in part, must"
		"retain app-\nlicable copyright and other legal privilege notices,"
		"the above license notice,\n these conditions, and the following"
		"disclaimer."
	);
	puts("");
	puts(
		"NO WARRANTY OF ANY KIND IS IMPLIED BY, OR SHOULD BE INFERRED FROM,"
		"THIS LICENSE\nOR THE ACT OF DISTRIBUTION UNDER THE TERMS OF THIS"
		"LICENSE, INCLUDING BUT NOT\nLIMITED TO THE WARRANTIES OF"
		"MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,\nAND"
		"NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS, ASSEMBLERS, OR"
		"HOLDERS OF\nCOPYRIGHT OR OTHER LEGAL PRIVILEGE BE LIABLE FOR ANY"
		"CLAIM, DAMAGES, OR OTHER\nLIABILITY, WHETHER IN ACTION OF CONTRACT,"
		"TORT, OR OTHERWISE ARISING FROM, OUT\nOF, OR IN CONNECTION WITH THE"
		"WORK OR THE USE OF OR OTHER DEALINGS IN THE WORK."
	);
	puts("");
}

void version() {
	puts("cat version 0.1, copyright 2014");
	puts(
		"This software may be distributed under the terms of the Open\n"
		"Works License (OWL).  See http://owl.apotheon.org for details."
	);
}


int main(int argc, char *argv[]) {
#define OPT(a) (strcmp(argv[i], a) == 0)
	for (int i = 1; i < argc; i++) {
		if (OPT("-h") || OPT("--help")) usage();

		if (OPT("--license")) license();

		if (OPT("-u") || OPT("--unbuffered")) {
			printf("Unbuffered use has not yet been implemented.\n");
		}

		if OPT("--version") version();
	}
	return 0;
}
