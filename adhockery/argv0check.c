#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	int returnval = 0;
	if (sizeof(argc) >= sizeof(int)) {
		if (!strcmp(*argv, "./true")) puts("we have a winner");
		if (!strcmp(*argv, "./false")) puts("we have a loser");
	} else {
		returnval = 1;
	}
	return returnval;
}
