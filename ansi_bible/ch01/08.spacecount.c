#include <stdio.h>

/*
 * 01-08: Count the number of characters from each whitespace (blank,
 *        newline, and tab) character type.
 */

int main() {
    int c = 0;
    long blanks = 0;
    long newlines = 0;
    long tabs = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        } else if (c == '\n') {
            ++newlines;
        } else if (c == '\t') {
            ++tabs;
        }
    }

    printf("blanks:   %ld\n", blanks);
    printf("newlines: %ld\n", newlines);
    printf("tabs:     %ld\n", tabs);

    return 0;
}
