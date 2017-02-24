#include <stdio.h>

#define TAB 8

int next_tabstop(int columns, int tabsize);

int main() {
    int c = 0;

    for (int i = 1; (c = getchar()) != EOF; ++i) {
        if (c == '\t') {
            int s = 0;

            for (; s < next_tabstop(i, TAB); ++s) putchar(' ');
            putchar(' ');

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
