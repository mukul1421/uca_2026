#include <stdio.h>

int isPower2(int x) {
	return !(x & (x + ~0)) & !!x & !(x >> 31);
}

int main() {

	int num;

	printf("Enter number: ");
	scanf("%d", &num);

	int result = isPower2(num);

	printf("Result: %d\n", result);

	return 0;

}
