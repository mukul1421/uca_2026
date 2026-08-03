#include <stdio.h>

int conditional(int x, int y, int z) {

	int mask = ~(!x) + 1;

	return (y & ~mask) | (z & mask);

}

int main() {

	int x, y, z;

	printf("Enter 3 numbers to check: ");
	scanf("%d %d %d", &x, &y, &z);

	int result = conditional(x, y, z);

	printf("Result is: %d\n", result);

	return 0;

}

