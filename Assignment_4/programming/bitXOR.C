#include <stdio.h>

int bitXor(int num1, int num2) {
	int result = ~(num1 & num2) & ~(~num1 & ~num2);

	return result;
}

int main() {
	int num1, num2;

	printf("Enter 2 numbers: ");
	scanf("%d %d", &num1, &num2);

	int result = bitXor(num1, num2);

	printf("bit ^ of 2 no.s using ~ and & is: %d\n", result);

	return 0;
}
