#include<stdio.h>


int bitAnd(int n , int m){
	int result =~(~n|~m);
	return result;


}

int main(){
    int num1 , num2;
    
    printf("Enter Two Number : ");
    scanf("%d %d",&num1 , &num2);
     
    int result = bitAnd(num1 , num2);

    printf("bit & of two number is : %d\n",result);
   
    return 0;    




}
