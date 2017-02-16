#include <stdio.h>

/*
 * 01-13: Print histograms of word lengths from input.
 */

/*
 * I thought about using an array for this, because that's what K&R seemed to
 * want from the exercise, but I like this approach more.
 */

/*
 * Use a function for the histogram output, even though writing functions other
 * than main() have not yet been introduced at this point in K&R, because it
 * makes for a better organized program this way.
 */

void print_histogram(int characters) {
    if (characters != 0) {
        putchar(' ');
        for (int i=0; i < characters; i++) putchar('-');
        putchar('\n');
    }
}

int main() {
    int c = 0;
    long characters = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            print_histogram(characters);
            characters = 0;
        } else {
            ++characters;
            putchar(c);
        }
    }

    print_histogram(characters);

    return 0;
}
