#include<stdio.h>

int logicalshift(int n , int s){

	return (n >> s)&~(((1 << 31)>>s)<<1);
}

int main (){
	int num , shift;
	printf("Enter the num and shifts:");
	scanf("%x %d",&num ,&shift);

	int result = logicalshift(num,shift);

	printf("Shifter number is:%x",result);


}
