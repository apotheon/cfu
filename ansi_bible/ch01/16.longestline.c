#include <stdio.h>
#include <string.h>

#define MAXLENGTH 1000

/*
 * 01-16: Print the full length of the longest line entered, and the text of
 * the line (truncated to 1000 characters if necessary).
 */

/*
 * Standard "cheating" disclaimers with regard to exercise assumptions apply.
 */

int get_line(char line[], int maxlength);
int copyline(char from[], char to[]);

int main() {
    int current_length = 0;
    int longest_length = 0;

    char line[MAXLENGTH];
    memset(line, 0, MAXLENGTH);

    char longest[MAXLENGTH];
    memset(longest, 0, MAXLENGTH);

    while ((current_length = get_line(line, MAXLENGTH)) > 0) {
        if (current_length > longest_length) {
            longest_length = current_length;
            copyline(line, longest);
        }
    }

    printf("%d: ", longest_length);
    if (longest_length > 0) printf("%s", longest);

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

int copyline(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;

    return i;
}
