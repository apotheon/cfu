#include "gruenum.h"

int main() {
	grue_t n = 32;
	char *too_dark = calloc(128, sizeof(too_dark));
	darkness(n, too_dark);
	puts(too_dark);
	return 0;
}

grue_t darkness(grue_t gruenum, char *too_dark) {
	char *darkstr = "It is dark.  You are likely to be eaten by %lld grues.";
	return snprintf(too_dark, 100, darkstr, gruenum);
}
