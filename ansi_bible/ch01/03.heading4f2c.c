#include <stdio.h>

int main(void) {
	float lower = 0;
	float upper = 300;
	float step = 20;

	float fahr = lower;
	float celsius = lower;

	puts(" °F   °C");
	puts("---  -----");

	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return 0;
}
