#include <stdio.h>

int main() {
    int c = 0;
    int previous = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        } else if (previous != ' ') {
            putchar(c);
        }

        previous = c;
    }

    return 0;
}
