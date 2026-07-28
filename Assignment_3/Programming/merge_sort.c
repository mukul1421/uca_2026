#include<stdio.h>



void merge(int arr[] , int s  , int m , int e ){

	int temp [e-s+1];
	int z = 0 ;
        int i = s ;
	int j = m+1 ;
	while( i <= m && j<=e ){
	
	if(arr[i] < arr[j]){
         temp[z] = arr[i] ;
	 i++;
	}

	else{
         temp[z] = arr[j];
	 j++;
	}

	z++;
	
	}

	while(i <= m){
	 temp[z] = arr[i] ;
         i++;
	 z++;
	}
	while(j <= e){
		temp[z] = arr[j];
		j++;
		z++;
	}

	for (int i = s ; i <=e ; i++ ){
		arr[i] = temp[i-s];
	}



}

void mergeSort(int arr[] , int s , int e ){

	if(s >= e) return ;

	int mid = s + (e-s)/2 ;

	mergeSort( arr , s , mid );
	mergeSort( arr , mid+1 , e );

	merge(arr , s , mid , e);

}

int main(){

	int arr [5] = {1,3,2,6,5};

	for (int i = 0 ; i < 5 ; i++){
		printf("%d ",arr[i]);
	}

	printf("\n\n");

	mergeSort(arr , 0 , 5-1 );

	for (int i = 0 ; i <5 ; i++){
		printf("%d ",arr[i]);
	}

	return 0 ;


}
