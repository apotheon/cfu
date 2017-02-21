#include <stdio.h>

/*
 * 01-15: Use a function to convert Fahrenheit to Celsius.
 */

float f_to_c(float fahrenheit_temp);

int main() {
    float f = 0.0;
    float c = 0.0;
    float limit = 300;
    float increment = 20;

    while (f <= limit) {
        c = f_to_c(f);
        printf("%3.0f %6.1f\n", f, c);

        f = f + increment;
    }

    return 0;
}

float f_to_c(float f) {
    return (5.0 / 9.0) * (f - 32.0);
}
