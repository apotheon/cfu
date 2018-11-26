#include <stdio.h>

int main() {
	int count = 1;
	float x = 0.1;

	while (count <= 500) {
		x += 0.1;
		++count;
	}

	if ((0.1 + 0.2) == 0.3) {
		puts("Everything is peachy!");
	} else {
		puts("\nIf you expect decimal arithmetic behavior from your IEEE 754");
		puts("floating point numbers, you will eventually be disappointed.\n");
		printf("             0.1 + 0.2 != %20.19f\n", 0.1 + 0.2);
		printf("                         %d != %d\n\n", (int)(x * 10), count);
		puts("\nThis is an example of why default floats in a language using");
		puts("decimal numerals by default should be decimal floats instead");
		puts("of binary floats.  IEEE 754 should only be used as the float");
		puts("type for binary numbers or when explicitly declared in code.\n");
	}

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
	 * When compiled and executed with IEEE 754 as your default floating *
	 * point type, the program's output should look something like this: *
	 *                                                                   *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 *                                                                   *
	 *   If you expect decimal arithmetic behavior from your IEEE 754    *
	 *   floating point numbers, you will eventually be disappointed.    *
	 *                                                                   *
	 *                0.1 + 0.2 != 0.3000000000000000444                 *
	 *                            500 != 501                             *
	 *                                                                   *
	 *   This is an example of why default floats in a language using    *
	 *   decimal numerals by default should be decimal floats instead    *
	 *   of binary floats.  IEEE 754 should only be used as the float    *
	 *   type for binary numbers or when explicitly declared in code.    *
	\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	return 0;
}
