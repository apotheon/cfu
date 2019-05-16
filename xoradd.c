#include <stdio.h>
#include <stdlib.h>

long long xoradd(long long x, long long y) {
	while (y != 0) {
		long long carry = x & y;

		x = x ^ y;
		y = carry << 1;
	}

	return x;
}

int main(int argc, char **argv) {
	if (argc == 3) {
		long long x, y;
		const char **errstr;

		x = strtonum(*(argv + 1), -1024, 1024, errstr);
		y = strtonum(*(argv + 2), -1024, 1024, errstr);

		printf("%lld, %lld\n", x, y);
		printf("%lld\n", xoradd(x, y));
	}

	return 0;
}
