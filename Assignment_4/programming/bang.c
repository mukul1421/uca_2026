#include <stdio.h>

int bang(int x) {
	return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}

int main() {

	int num;

	printf("Enter the number: ");
	scanf("%d", &num);

	int result = bang(num);

	printf("%d\n", result);

	return 0;

}
