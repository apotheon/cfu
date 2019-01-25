#include <stdio.h>

/* demonstrate difference between pointer and nonpointer ints */
/* show values for various addr, deref, and val evaluations */

int main() {
	int nonpointer = 5;
	int *pointer = &nonpointer;

	/* prints something like "5 0x7f7ffffe4fbc" */
	printf("%d %p\n", nonpointer, &nonpointer);

	/* prints something like "0x7f7ffffe4fbc 0x7f7ffffe4fb0 5" */
	printf("%p %p %d\n", pointer, &pointer, *pointer);
	return 0;
}
