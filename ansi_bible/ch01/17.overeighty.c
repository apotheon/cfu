#include <stdio.h>
#include <string.h>

#define MAXLENGTH 10000

/*
 * 01-17: Print all input lines over eighty characters long.
 */

/*
 * Standard "cheating" disclaimers with regard to exercise assumptions apply.
 */

int get_line(char line[], int maxlength);

int main() {
    int length = 0;

    char line[MAXLENGTH];
    memset(line, 0, MAXLENGTH);

    while ((length = get_line(line, MAXLENGTH)) > 0) {
        if (length > 80) printf("%s", line);
    }

    return 0;
}

int get_line(char line[], int maxlength) {
    int i = 0;
    int c = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < maxlength - 1) line[i] = c;
        ++i;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}
