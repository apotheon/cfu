#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
/*
"     -h\n"
"     --help\n"
"             Print this help information.\n"
"\n"
"     --license\n"
"             Print license text.\n"
"\n"
"     -n\n"
"     --no-newline\n"
"             Do not print trailing newline character.\n"
"\n"
"     --version\n"
"             Print version information.\n";
*/
"    -h            Print this help information.\n"
"\n"
"    -n            Do not print a trailing newline character.\n"
"\n"
"    -W <COMMAND>  Print out information specified by <COMMAND>.\n"
"\n"
"    --            If the first option, the -- option disables\n"
"                  further option handling on the command line.\n";


const char *license_text = "Copyright 2014 Chad Perrin\n"
"\n"
"Permission is hereby granted by the holder(s) of copyright or other le-\n"
"gal privileges, author(s) or assembler(s), and contributor(s) of this\n"
"work, to any person who obtains a copy of this work in any form, to re-\n"
"produce, modify, distribute, publish, sell, sublicense, use, and/or\n"
"otherwise deal in the licensed material without restriction, provided\n"
"the following conditions are met:\n"
"\n"
"Redistributions, modified or unmodified, in whole or in part, must re-\n"
"tain applicable copyright and other legal privilege notices, the above\n"
"license notice, these conditions, and the following disclaimer.\n"
"\n"
"NO WARRANTY OF ANY KIND IS IMPLIED BY, OR SHOULD BE INFERRED FROM, THIS\n"
"LICENSE OR THE ACT OF DISTRIBUTION UNDER THE TERMS OF THIS LICENSE, IN-\n"
"CLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS\n"
"FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.  IN NO EVENT SHALL THE\n"
"AUTHORS, ASSEMBLERS, OR HOLDERS OF COPYRIGHT OR OTHER LEGAL PRIVILEGE\n"
"BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN ACTION\n"
"OF CONTRACT, TORT, OR OTHERWISE ARISING FROM, OUT OF, OR IN CONNECTION\n"
"WITH THE WORK OR THE USE OF OR OTHER DEALINGS IN THE WORK.\n";

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
	printf("mimic version %s, copyright 2014\n", version_number);
	puts(
		"This software may be distributed under the terms of the Open\n"
		"Works License (OWL).  See http://owl.apotheon.org for details."
	);

	exit(0);
}

/* end informational option handling */


void mimic(int newline, char *args[], int start, int end) {
	if (start > end) {
		puts("");
	} else {
		for (int i = start; i < end; i++) {
			printf("%s", args[i]);
			if ((i+1) < end) printf(" ");
			else if (newline) puts("");
		}
	}
}


int main(int argc, char *argv[]) {
#define OPT(a) (strcmp(argv[1], a) == 0)
	int nflag = 1;
	int startopt = 2;

	if (argc > 1) {
		if (OPT("-h") || OPT("--help")) {
			help();
		} else if (OPT("--license")) {
			license();
		} else if (OPT("--version")) {
			version();
		} else if (OPT("-n") || OPT("--no-newline")) {
			nflag = 0;
		} else {
			startopt = 1;
		}
	}

	mimic(nflag, argv, startopt, argc);

	return 0;
}
