#include <stdio.h>

int getByte(int num, int n) {
	int shiftedNum = num >> (n << 3);
	return shiftedNum & 0xFF;
}

int main() {

	int num, byte;
	
	printf("Enter the number and byte: ");
	scanf("%x %d", &num, &byte);

	int reqByte = getByte(num, byte);

	printf("0x%X\n", reqByte);

	return 0;
}
