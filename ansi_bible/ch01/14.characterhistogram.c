#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHARS 1000000

/*
 * 01-14: Print a histogram of repetitions of each character from STDIN.
 */

int main() {
    int c = 0;
    int charnum = 0;
    int exists = 0;

    int *characters = calloc(MAXCHARS, sizeof(characters));
    int *charcounts = calloc(MAXCHARS, sizeof(charcounts));

    while (((c = getchar()) != EOF) && (charnum < MAXCHARS)) {
        for (int i = 0; i < charnum; ++i) {
            if (c == *(characters + i)) {
                ++(*(charcounts + i));
                exists = 1;
            }
        }

        if (exists == 0) {
            *(characters + charnum) = c;
            *(charcounts + charnum) = 1;

            ++charnum;
        } else {
            exists = 0;
        }
    }

    printf("characters: %d\n", charnum - 1);

    for (int i = 0; i < charnum - 1; ++i) {
        if (*(characters + i) != 0) {
            if (*(characters + i) == ' ') {
                printf("\\s");
            } else if (*(characters + i) == '\n') {
                printf("\\n");
            } else if (*(characters + i) == '\t') {
                printf("\\t");
            } else {
                putchar(' ');
                putchar(*(characters + i));
            }

            printf(": ");

            for (int n = 0; n < *(charcounts + i); ++n) putchar('-');

            putchar('\n');
        }
    }

    return 0;
}
