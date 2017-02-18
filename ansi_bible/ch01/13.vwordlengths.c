#include <stdio.h>

/*
 * 01-13: Print a vertical histogram of word lengths from input.
 */

/*
 * Unlike the horizontal histogram version, I stuck with what the book has
 * already covered this time, and used arrays as K&R seemed to intend.  I chose
 * to explicitly limit the number of words measured and the maximum length of
 * words for display within a reasonably small console, which might result in
 * truncated results on both the number of words axis and the word length axis
 * for moderately sized files and for extremely long words (e.g. lengthier
 * German compound words or gratuitously long words such as those longer than
 * "antihyperpolysyllabicsesquipedalianistic", because this program should not
 * print out the answer to the question of life, the universe, and everything,
 * so that we do not risk waking the a Great Old One).
 */

#define MAXWORDS 70
#define MAXLENGTH 41

int main() {
    int c = 0;
    int lastword = 0;
    int wordlength = 0;
    int words[MAXWORDS];
    int longword = 0;

    for (int i = 0; i < MAXWORDS; i++) words[i] = 0;

    while ((lastword < MAXWORDS) && ((c = getchar()) != EOF)) {
        if (c != ' ' && c != '\n' && c != '\t') {
            if (wordlength < MAXLENGTH) wordlength++;
        } else {
            if (wordlength > 0) {
                words[lastword] = wordlength;
                ++lastword;
            }

            wordlength = 0;
        }
    }

    for (int i = 0; i < lastword; i++) {
        if (longword < words[i]) longword = words[i];
    }

    for (int l = longword; l > 0; l--) {
        for (int i = 0; i < lastword; i++) {
            if (words[i] >= l) putchar('|');
            else putchar(' ');
        }

        putchar('\n');
    }

    return 0;
}
