#include <stdio.h>

#define TAB 8

/*
 * 01-20: Replace tabs with spaces for a preset tab stop column width.
 */

/*
 * Standard "cheating" disclaimers with regard to exercise assumptions apply.
 */

int next_tabstop(int columns, int tabsize);

int main() {
    int c = 0;

    for (int i = 1; (c = getchar()) != EOF; ++i) {
        if (c == '\t') {
            int s = 0;
            for (putchar(' '); s < next_tabstop(i, TAB); ++s) putchar(' ');

            i = i + s;
        } else {
            putchar(c);
        }
    }

    return 0;
}

int next_tabstop(int columns, int tabsize) {
    while (tabsize < columns) columns = columns - tabsize;
    return tabsize - columns;
}
