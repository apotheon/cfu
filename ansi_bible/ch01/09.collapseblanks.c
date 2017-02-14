#include <stdio.h>

/*
 * 01-09: Print input with any number of adjacent blank characters collapsed
 *        into only one blank character.
 */

int main() {
    int c = 0;
    int previous = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        } else if (previous != ' ') {
            putchar(c);
        }

        previous = c;
    }

    return 0;
}
