#include<stdio.h>

int main ()
{

 int num;
 scanf("%d",&num);

 int a=2;
 int b=8;
 int sum=0;

 while(a<=num){
   sum+=a;
   int c=4*b+a;
   a=b;
   b=c;

}

 printf("%d",sum);

 return 0;
}
