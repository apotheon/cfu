#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include "commonopts.h"*/


/* begin informational output strings */

const char *version_number = "1.0";


const char *help_text = "mimic - write arguments to standard output\n"
"\n"
/*
"usage: mimic [-n|--no-newline] [operand [...]]\n"
"       mimic (-h|--help|--license|--version)\n"
*/
"usage: mimic [-n] [operand [...]]\n"
"       mimic [-h|-W COMMAND]\n"
"\n"
"The mimic utility writes any specified operands, separarated by single\n"
"blank (' ') characters and followed by a newline ('\\n') character, to\n"
"standard output.  Only the first argument may be recognized as a com-\n"
"mand line option.  If it is an informational option (help, license, or\n"
"version), that option will be executed and the program will then exit.\n"
"\n"
"OPTIONS:\n"
"\n"
"     -h\n"
"     --help\n"
"             Print this help information.\n"
"\n"
"     -l\n"
"     --license\n"
"             Print license text.\n"
"\n"
"     -n\n"
"     --no-newline\n"
"             Do not print trailing newline character.\n"
"\n"
"     -v\n"
"     --version\n"
"             Print version information.\n"
"\n"
"     -W <COMMAND>\n"
"             Print out information specified by <COMMAND>.\n"
"             (No commands are currently implemented.)\n"
"\n"
"     --\n"
"             Disable further option handling on the command line.\n";


const char *license_text = "Copyright 2016 Chad Perrin, released under the "
"terms of version 0.4 of\nthe Copyfree Open Innovation License.\n"
"\n"
"## Terms and Conditions\n"
"\n"
"Redistributions, modified or unmodified, in whole or in part, must retain\n"
"applicable copyright or other legal privilege notices, these conditions, "
"and\nthe following license terms and disclaimer.  Subject to these "
"conditions, the\nholder(s) of copyright or other legal privileges, author(s) "
"or assembler(s),\nand contributors of this work hereby grant to any person "
"who obtains a copy of\nthis work in any form:\n"
"\n"
"1. Permission to reproduce, modify, distribute, publish, sell, sublicense, "
"use,\nand/or otherwise deal in the licensed material without restriction.\n"
"\n"
"2. A perpetual, worldwide, non-exclusive, royalty-free, irrevocable patent\n"
"license to reproduce, modify, distribute, publish, sell, use, and/or "
"otherwise\ndeal in the licensed material without restriction, for any and all "
"patents:\n"
"\n"
"    a. Held presently or in the future by each such holder of copyright or\n"
"    other legal privilege, author or assembler, or contributor, necessarily\n"
"    infringed by the contributions alone or by combination with the work, of\n"
"    that privilege holder, author or assembler, or contributor.\n"
"\n"
"    b. Necessarily infringed by the work at the time that holder of "
"copyright\n    or other privilege, author or assembler, or contributor made "
"any\n    contribution to the work.\n"
"\n"
"NO WARRANTY OF ANY KIND IS IMPLIED BY, OR SHOULD BE INFERRED FROM, THIS "
"LICENSE\nOR THE ACT OF DISTRIBUTION UNDER THE TERMS OF THIS LICENSE, "
"INCLUDING BUT NOT\nLIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR "
"A PARTICULAR PURPOSE,\nAND NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS, "
"ASSEMBLERS, OR HOLDERS OF\nCOPYRIGHT OR OTHER LEGAL PRIVILEGE BE LIABLE FOR "
"ANY CLAIM, DAMAGES, OR OTHER\nLIABILITY, WHETHER IN ACTION OF CONTRACT, TORT, "
"OR OTHERWISE ARISING FROM, OUT\nOF, OR IN CONNECTION WITH THE WORK OR THE USE "
"OF OR OTHER DEALINGS IN THE WORK.\n";

/* end informational output strings */


/* begin informational option handling */

int help() {
	printf("\n%s\n", help_text);
	exit(0);
}

int license() {
	printf("\n%s\n", license_text);
	exit(0);
}

int version() {
	printf("echo version %s, copyright 2014\n", version_number);
	exit(0);
}

/* end informational option handling */


void mimic(int newline, char **args, int start, int end) {
	if (start > end) {
		puts("");
	} else {
		for (int i = start; i < end; ++i) {
			printf("%s", *(args+i));
			if ((i+1) < end) printf(" ");
			else if (newline) puts("");
		}
	}
}


int main(int argc, char **argv) {
#define OPT(a) (strcmp(*(argv + 1), a) == 0)
	int nflag = 1;
	int startopt = 2;

	if (argc > 1) {
		if (OPT("-h") || OPT("--help")) {
			help();
		} else if (OPT("-l") || OPT("--license")) {
			license();
		} else if (OPT("-v") || OPT("--version")) {
			version();
		} else if (OPT("-n") || OPT("--no-newline")) {
			nflag = 0;
		} else if (OPT("-W")) {
			if (argc > 2) {
				startopt = 3;
			} else exit(0);
		} else {
			startopt = 1;
		}
	}

	mimic(nflag, argv, startopt, argc);

	return 0;
}
