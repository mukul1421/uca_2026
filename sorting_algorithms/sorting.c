#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void generateRandom(int arr[], int n){
    for(int i=0;i<n;i++)
        arr[i]=rand()%100000;
}

void generateAscending(int arr[], int n){
    for(int i=0;i<n;i++)
        arr[i]=i+1;
}

void generateDescending(int arr[], int n){
    for(int i=0;i<n;i++)
        arr[i]=n-i;
}

void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool swapped=false;

        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }

        if(!swapped)
            break;
    }
}

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }

        if(minIndex!=i){
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}

int partition(int arr[], int low, int high){

    // Random Pivot
    int randomIndex=low+rand()%(high-low+1);

    int temp=arr[randomIndex];
    arr[randomIndex]=arr[high];
    arr[high]=temp;

    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;

            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void merge(int arr[], int left, int mid, int right){

    int n1=mid-left+1;
    int n2=right-mid;

    int *L=(int*)malloc(n1*sizeof(int));
    int *R=(int*)malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++)
        L[i]=arr[left+i];

    for(int i=0;i<n2;i++)
        R[i]=arr[mid+1+i];

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){

        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }

    while(i<n1)
        arr[k++]=L[i++];

    while(j<n2)
        arr[k++]=R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right){

    if(left<right){

        int mid=left+(right-left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }
}

void heapify(int arr[], int n, int i){

    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=i){

        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;

        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){

    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for(int i=n-1;i>0;i--){

        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;

        heapify(arr,i,0);
    }
}

int main(){

    srand(time(NULL));

    int n=8000;
    int step=4000;

    clock_t start,end;

    for(int i=0;i<8;i++){

        printf("\nArray Size : %d\n",n);

        int arr[n];

        //---------------- Random ----------------

        generateRandom(arr,n);

        start=clock();

        // bubbleSort(arr,n);
       // selectionSort(arr,n);
       // insertionSort(arr,n);
        //quickSort(arr,0,n-1);
      //  mergeSort(arr,0,n-1);
        heapSort(arr,n);

        end=clock();

        printf("Random     : %.3f ms\n",
               (double)(end-start)*1000/CLOCKS_PER_SEC);

        //---------------- Ascending ----------------

        generateAscending(arr,n);

        start=clock();

        //bubbleSort(arr,n);
        //selectionSort(arr,n);
        //insertionSort(arr,n);
       // quickSort(arr,0,n-1);
        mergeSort(arr,0,n-1);
        //heapSort(arr,n);

        end=clock();

        printf("Ascending  : %.3f ms\n",
               (double)(end-start)*1000/CLOCKS_PER_SEC);

        //---------------- Descending ----------------

        generateDescending(arr,n);

        start=clock();

        //bubbleSort(arr,n);
        //selectionSort(arr,n);
        insertionSort(arr,n);
        // quickSort(arr,0,n-1);
        //mergeSort(arr,0,n-1);
        //heapSort(arr,n);

        end=clock();

        printf("Descending : %.3f ms\n",
               (double)(end-start)*1000/CLOCKS_PER_SEC);

        n+=step;
    }

    return 0;
}
