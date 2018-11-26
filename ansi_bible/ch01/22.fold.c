#include <stdio.h>

#define MAXWIDTH 80
#define TAB 4

int print_line(int column);
int expandtab(int column);

char line[MAXWIDTH];
memset(line, 0, MAXWIDTH);

int main() {
    int c = 0;
    int column = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            column = print_line(column);
        } else if (c == '\t') {
            column = expandtab(column);
        } else if (column >= MAXWIDTH) {
        }
    }

    return 0;
}

int print_line(int column) {
    for (int i = 0; i < column; ++i) putchar(line[i]);
    if (column > 0) putchar('\n');

    return 0;
}

int expandtab(int column) {
}
