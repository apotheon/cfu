#include <stdio.h>

/*
 * 01-12: Print one word per line from input.
 */

int main() {
    int c = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t') putchar(c);
        else printf("\n");
    }

    return 0;
}
