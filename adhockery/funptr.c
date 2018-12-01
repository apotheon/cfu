#include <stdio.h>

int add(int foo, int bar) {
	return (foo + bar);
}

void addprint(int foo, int bar, int (*adder)(int, int)) {
	printf("%d\n", (*adder)(foo, bar));
}

int main() {
	addprint(1, 2, &add);

	int (*addp)(int, int);
	addp = &add;
	printf("%d\n", (*addp)(4, 5));

	return 0;
}
