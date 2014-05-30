#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *version_number = "1.0";

/* begin informational option handling */

int w_usage() {
	puts("");
	puts("usage: cat [-u] [file[ ...]] [post-options]");
	puts("       cat -W (help|license|version)");
	puts("");
	puts("The -W option can take one of three command arguments:");
	puts("");
	puts("     help          Print this help information.");
	puts("");
	puts("     license       Print license text.");
	puts("");
	puts("     version       Print version information.");
	puts("");

	exit(1);
}

int help() {
	puts("");
	puts("cat - concatenate and print files");
	puts("");
	puts("usage: cat [-u] [file[ ...]] [post-options]");
	puts("       cat -W (help|license|version)");
	puts("");
	puts("The cat utility reads files sequentially, writing them to stan-");
	puts("dard output.  The file operands are processed in command line");
	puts("order.  If file is a single dash or absent, cat reads from stan-");
	puts("dard input.  If file is a Unix domain socket, cat connects to it");
	puts("and reads it until EOF.  If any the help or any informational");
	puts("command (license, version) is selected, the first of them will");
	puts("be executed, and the program will then immediately exit.  All");
	puts("options are mutually exclusive with other options.");
	puts("");
	puts("A single hyphen character as a file operand is interpreted as");
	puts("referring to the standard input file descriptor.");
	puts("");
	puts("OPTIONS:");
	puts("");
	puts("     -h            Print this help information.");
	puts("");
	puts("     -u            Disable output buffering.");
	puts("");
	puts("     -W <COMMAND>");
	puts("");
	puts("COMMANDS:");
	puts("");
	puts("     help          Print this help information.");
	puts("");
	puts("     license       Print license text.");
	puts("");
	puts("     version       Print version information.");
	puts("");
	puts("POST-OPTIONS:");
	puts("");
	puts("Post-options are guidelines for applying filtering capabilities");
	puts("to cat commands after all operands, using the Unix pipeline to");
	puts("duplicate the effects of options harmfully integrated with POSIX");
	puts("noncompliant or otherwise undesirable implementations.");
	puts("");
	puts("     |sed -n '/./,/^$/p'");               /* -s */
	puts("                   Squeeze multiple adjacent empty lines.");
	puts("");
	puts("     |sed -n l");                         /* -e */
	puts("                   Display non-printing character escapes, and");
	puts("                   dollar signs \"$\" indicating ends of lines.");
	puts("");
	puts("     |nl -ba");                           /* -n */
	puts("             Number lines of output, starting at 1.");
	puts("");
	puts("     |nl");                               /* -b */
	puts("             Number non-empty output lines, starting at 1.");
	puts("");

	exit(0);

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

int license() {
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

	exit(0);
}

int version() {
	printf("cat version %s, copyright 2014\n", version_number);
	puts(
		"This software may be distributed under the terms of the Open\n"
		"Works License (OWL).  See http://owl.apotheon.org for details."
	);

	exit(0);
}

/* end informational option handling */

int main(int argc, char *argv[]) {
#define OPT(a) (strcmp(argv[i], a) == 0)
	int i = 1;
	if (OPT("-h")) {
		help();
	} else if (OPT("-W")) {
		if (++i < argc) {
			if (OPT("help")) help();
			if (OPT("license")) license();
			if (OPT("version")) version();
		}
		w_usage();
	} else if (OPT("-u")) {
		setbuf(stdout, NULL);
		++i;
	}

	while (i < argc) {
		/* do something here */
		++i;
	}

	return 0;
}
