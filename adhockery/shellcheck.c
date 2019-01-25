#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("%s = %s\n", "SHELL", getenv("SHELL"));
	return 0;
}
