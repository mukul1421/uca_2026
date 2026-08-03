#include <stdio.h>

int fitbit(int n , int b){

	int shifts = 32 + (~b+1);
	int temp = 0 ; 

	temp = (n << shifts)>>shifts;

	return !(temp^n);

}

int main(){
	int num , bit ;

	printf("Enter the num:");
	scanf("%d",&num);

	printf("Enter the bit:");
	scanf("%d",&bit);
        
	int result = fitbit(num , bit);

	printf("%d\n",result);

	return 0;

}
