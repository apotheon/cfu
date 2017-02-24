#include <stdio.h>

/*
 * Does C use the same ternary associativity as PHP?  No, it does not.
 *
 * Someone in IRC made the claim that PHP gets its incredibly weird ternary
 * associativity from C, but that is an obviously false statement.  I wrote
 * code to prove it to myself, just to make sure I wasn't imagining things.
 */

int main() {

    int v = 'V';
    int result = 0;

    result = (
        (v=='F') ? 1 :
        (v=='I') ? 2 :
        (v=='V') ? 3 :
        (v=='E') ? 4 :
        5
    );

    printf("%d\n", result);

    return 0;
}

/* PHP Example:

    result = (
        (v == 'F') ? 1 :
        (v == 'I') ? 2 :
        (v == 'V') ? 3 :
        (v == 'E') ? 4 :
        5
    );
*/

/* PHP Output: 4 */
