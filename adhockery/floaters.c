#include <stdio.h>

int main() {
	int count = 1;
	float x = 0.1;

	while (count < 500) {
		x += 0.1;
		++count;
	}

	if ((0.1 + 0.2) == 0.3) {
		puts("Everything is peachy!");
	} else {
		puts("\nIf you expect decimal arithmetic behavior from your IEEE 754");
		puts("binary floating points, you will eventually be disappointed.\n");
		printf("             0.1 + 0.2 != %20.19f\n", 0.1 + 0.2);
		printf("                         %d != %d\n\n", (int)(x * 10), count);
		puts("\nThis is an example of why default floats in a language using");
		puts("decimal numerals by default should be decimal floats instead");
		puts("of binary floats.  We shouldn't use IEEE 754 binary floating");
		puts("points except with binary or when made explicit in our code.\n");
	}

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
	 *                                                                     *
	 *  When compiled with IEEE 754 binary floating points, the program's  *
	 *  output should look something like the following explanation text:  *
	 *                                                                     *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *                                                                     *
	 *    If you expect decimal arithmetic behavior from your IEEE 754     *
	 *    binary floating points, you will eventually be disappointed.     *
	 *                                                                     *
	 *                 0.1 + 0.2 != 0.3000000000000000444                  *
	 *                             499 != 500                              *
	 *                                                                     *
	 *    This is an example of why default floats in a language using     *
	 *    decimal numerals by default should be decimal floats instead     *
	 *    of binary floats.  We shouldn't use IEEE 754 binary floating     *
	 *    points except with binary or when made explicit in our code.     *
	 *                                                                     *
	\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	return 0;
}
