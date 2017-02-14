#include <stdio.h>

/*
 * 01-10: Copy back all input, but replace backspaces, tabs, and backslashes
 *        with their corresponding escape characters.
 */

int main () {
    int c = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\b')        printf("\\b");
        else if (c == '\t')   printf("\\t");
        else if (c == '\\')   printf("\\\\");
        else                  putchar(c);
    }

    return 0;
}
