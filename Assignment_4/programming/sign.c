#include<stdio.h>

int sign (int n ){

        int ms = n  >> 31;

	int x =  !!n;

	return (x | ms);
       
              
}
int main(){

	int num ;
	printf("Enter the num:");
	scanf("%d", &num);

	int result = sign(num);

	printf("sign is :%d\n", result);

	return 0;

}
