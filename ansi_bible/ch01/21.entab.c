#include <stdio.h>

#define TAB 4

/*
 * 01-21: Replace blanks with tabs for a preset tab stop column width, and pad
 * out only as necessary with additional blanks.
 */

/*
 * Standard "cheating" disclaimers with regard to exercise assumptions apply.
 */

int next_tabstop(int columns, int tabsize);

int main() {
    int c = 0;
    int column = 0;
    int blanks = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        } else {
            int distance = 0;

            if (blanks == 1) {
                putchar(' ');
                --blanks;
                ++column;
            } else if ((distance = next_tabstop(column, TAB)) < blanks) {
                column = column + distance;
                blanks = blanks - distance;
                putchar('\t');

                while (TAB < blanks) {
                    column = column + TAB;
                    blanks = blanks - TAB;
                    putchar('\t');
                }
            }

            column = column + blanks;
            for (; blanks > 0; --blanks) putchar(' ');

            putchar(c);
            ++column;
        }
    }

    return 0;
}

int next_tabstop(int columns, int tabsize) {
    while (tabsize < columns) columns = columns - tabsize;
    return tabsize - columns;
}
