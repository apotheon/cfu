#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 *
 * Permission is hereby granted by the holder(s) of copyright or other legal
 * privileges, author(s) or assembler(s), and contributor(s) of this work, to
 * any person who obtains a copy of this work in any form, to reproduce,
 * modify, distribute, publish, sell, sublicense, use, and/or otherwise deal in
 * the licensed material without restriction, provided the following conditions
 * are met:
 * 
 * Redistributions, modified or unmodified, in whole or in part, must retain
 * applicable copyright and other legal privilege notices, the above license
 * notice, these conditions, and the following disclaimer.
 * 
 * NO WARRANTY OF ANY KIND IS IMPLIED BY, OR SHOULD BE INFERRED FROM, THIS
 * LICENSE OR THE ACT OF DISTRIBUTION UNDER THE TERMS OF THIS LICENSE,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 * A PARTICULAR PURPOSE, AND NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS,
 * ASSEMBLERS, OR HOLDERS OF COPYRIGHT OR OTHER LEGAL PRIVILEGE BE LIABLE FOR
 * ANY CLAIM, DAMAGES, OR OTHER LIABILITY, WHETHER IN ACTION OF CONTRACT, TORT,
 * OR OTHERWISE ARISING FROM, OUT OF, OR IN CONNECTION WITH THE WORK OR THE USE
 * OF OR OTHER DEALINGS IN THE WORK.
 *
 */


const char *usage_text = "echo - write arguments to standard output\n"
"\n"
"usage: echo [-n] [operand [...]]\n"
"\n"
"The echo utility writes any specified operands, separarated by single\n"
"blank (' ') characters and followed by a newline ('\\n') character, to\n"
"standard output.  Only the first argument may be recognized as a com-\n"
"mand line option.  If it is an informational option (help, license,ver-\n"
"sion), that option will be executed and the program will then exit.\n"
"\n"
"The -n option eliminates the newline character when there are other op-\n"
"erands.  In cases where the -n option is the only argument, this usage\n"
"information is printed to standard output.\n";


void usage() {
	printf("\n%s\n", usage_text);
	exit(0);
}


void echo(int newline, char *args[], int start, int end) {
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
		if OPT("-n") nflag = 0;
		else startopt = 1;
	}

	if ((argc < 3) && !nflag) usage();

	echo(nflag, argv, startopt, argc);

	return 0;
}
