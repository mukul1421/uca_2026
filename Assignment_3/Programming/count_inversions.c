#include<stdio.h>



int merge(int arr [] , int start , int mid , int end){
	
	int count = 0 ;
	int i = start;
	int j = mid+1; 
        int z = 0;
        int temp [end-start+1];
	while(i <= mid && j<=end ){
	
	        if(arr[i]<=arr[j]){
		temp[z] = arr[i];
		i++;
	}
	else{
		count += mid - i + 1; 
	 	temp[z] = arr[j];
	        j++;
	}
	z++;
}

	while ( i <= mid ){

	temp[z] = arr[i];
	i++;
	z++;
	
	}

        while ( j <= end){

		temp[z] = arr[j] ; 
		j++;
		z++;
	}

 	for(int  i = start ; i <=end ; i++){
		
		arr[i] = temp[i-start];
	
	
	}

return count ;

}

int mergeSort(int arr[] , int start , int end ){

	if(start >=end ) return 0 ;

	int mid = start + (end-start)/2 ;
	
	int l = mergeSort(arr , start , mid );
	int r = mergeSort(arr , mid+1 , end );
        int count = merge(arr , start , mid ,end );	
	
        return l+r+count;

}




int main(){

	int arr [6] = {1,3,4,6,5,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0 ; i < n ; i++ ){
		printf("%d ",arr[i]);
	}
	printf("\n\n");

        int count = mergeSort(arr , 0 , n-1);
	printf("%d",count);

	printf("\n\n");

	for (int i = 0 ; i < n ; i++ ){
                printf("%d ",arr[i]);
	}


}
