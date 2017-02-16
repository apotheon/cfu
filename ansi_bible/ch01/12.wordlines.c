#include <stdio.h>

int main() {
    int c = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t') putchar(c);
        else printf("\n");
    }

    return 0;
}
