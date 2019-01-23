#include <stdio.h>

int main() {
	char v = 'V';
	int result = 0;

	result = (
		(v == 'F') ? 1 :
		(v == 'I') ? 2 :
		(v == 'V') ? 3 :
		(v == 'E') ? 4 :
		5
	);

	printf("right-associative chained ternaries: %d\n", result);

	/* right-associative equivalence */

	if (v == 'F') result = 1;
	else if (v == 'I') result = 2;
	else if (v == 'V') result = 3;
	else if (v == 'E') result = 4;
	else result = 5;

	printf("right-associative equivalence: %d\n", result);

	/* left-associative grouping */

	result = (
		(
			(
				(
					(v == 'F') ? 1 : (v == 'I')
				) ? 2 : (v == 'V')
			) ? 3 : (v == 'E')
		) ? 4 : 5
	);

	printf("left-associative chained ternaries: %d\n", result);

	/* left-associative equivalence */

	if (v == 'F') {
		result = 1;
	} else if (v == 'I') {
		result = -1;
	}

	if (result == -1) {
		result = 2;
	} else if ((result == 0) && (v == 'V')) {
		result = -1;
	}

	if (result == -1) {
		result = 3;
	} else if ((result == 0) && (v == 'E')) {
		result = -1;
	}

	if (result == -1) {
		result = 4;
	} else if (result == 0) {
		result = 5;
	}

	printf("left-associative equivalence: %d\n", result);
}
