#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	if (!strcmp(*argv, "./true")) puts("we have a winner");
	if (!strcmp(*argv, "./false")) puts("we have a loser");
	return 0;
}
