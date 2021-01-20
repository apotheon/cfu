#include <stdio.h>

int main(void) {
	float lower = 0;
	float upper = 300;
	float step = 20;

	float celsius = lower;
	float fahr = lower;

	puts(" °C   °F");
	puts("---  -----");

	while (celsius <= upper) {
		fahr = (celsius * 1.8) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}
