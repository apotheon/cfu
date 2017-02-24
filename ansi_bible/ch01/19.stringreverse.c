#include <stdio.h>
#include <string.h>

#define MAXLENGTH 10000

/*
 * 01-19: Print each line reversed.
 */

/*
 * Standard "cheating" disclaimers with regard to exercise assumptions apply.
 */

int get_line(char line[], int maxlength);
void reverse(char line[]);
int get_length(char line[]);

int main() {
    int length = 0;

    char line[MAXLENGTH];
    memset(line, 0, MAXLENGTH);

    while ((length = get_line(line, MAXLENGTH)) > 0) {
        reverse(line);
        printf("%s", line);
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

void reverse(char line[]) {
    int length = get_length(line);
    int reverse_limit = length - 1;
    int i = 0;

    char reversed[length + 1];
    memset(reversed, 0, length + 1);

    if (line[length - 1] == '\n') {
        --reverse_limit;
    }

    for (; i <= reverse_limit; ++i) reversed[i] = line[reverse_limit - i];
    for (i = 0; i <= reverse_limit; ++i) line[i] = reversed[i]; 
}

int get_length(char line[]) {
    int i = 0;
    for (; line[i] != 0; ++i);
    return i;
}
