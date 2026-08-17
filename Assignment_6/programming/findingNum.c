#include <stdio.h>

int findNum(int arr[], int n) {

	int result = 0;

	for(int i=0; i<32; i++) {
	
		int count = 0;
		for(int j=0; j<n; j++) {
			
			int num = arr[j];
			num >>= i;		
			count += num & 1;
		}

		result |= (count%3) << i;

	}

	return result;

}

int main() {

	int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	int result = findNum(arr, n);

	printf("The number is: %d\n", result);

	return 0;

}
