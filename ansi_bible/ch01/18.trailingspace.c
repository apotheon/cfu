#include <stdio.h>
#include <string.h>

#define MAXLENGTH 10000

/*
 * 01-18: Print each line without trailing blanks or tabs.
 */

/*
 * Standard "cheating" disclaimers with regard to exercise assumptions apply.
 */

int clean_line(char line[], int maxlength);

int main() {
    char line[MAXLENGTH];
    memset(line, 0, MAXLENGTH);

    while (clean_line(line, MAXLENGTH) > 0) printf("%s", line);

    return 0;
}

int clean_line(char line[], int maxlength) {
    int i = 0;
    int c = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < maxlength - 1) line[i] = c;
        ++i;
    }

    if (c == '\n') {
        for (--i; (line[i] == ' ') || (line[i] == '\t'); --i) line[i] = 0;
        ++i;

        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}
