#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify (int arr[], int n, int i) {

    while (1)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest == i)
        {
            break;
        }

        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        i = largest;
    }

}

void buildMaxHeap (int arr[], int n) {

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

}

void deleteMax (int arr[], int heapSize) {

    int temp = arr[0];
    arr[0] = arr[heapSize - 1];
    arr[heapSize - 1] = temp;

    heapify(arr, heapSize - 1, 0);

}

void heapSort (int arr[], int n) {

    buildMaxHeap(arr, n);

    for(int heapSize = n; heapSize > 1; heapSize--) {
    
        deleteMax(arr, heapSize);

    }

}

int isSorted (int arr[], int n) {

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return 0;
        }
    }

    return 1;

}

void generateRandomArray (int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

}

void generateAscendingArray (int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

}

void generateDescendingArray (int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }

}

double measureTime (int arr[], int n) {

    clock_t start = clock();

    heapSort(arr, n);

    clock_t end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

}

void printArray (int arr[], int n) {
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }    

    printf("\n");

}

int main () {
	
    srand((unsigned int)time(NULL));

    int arr[] = {45, 12, 78, 34, 23, 89, 1, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("\nSorted Array:\n");
    printArray(arr, n);

    if (isSorted(arr, n))
    {
        printf("\nValidation: Array is correctly sorted.\n");
    }
    else
    {
	 printf("\nValidation: Sorting failed.\n");
    }


    int sizes[] = {
        10000,
        20000,
        40000,
        80000,
        160000,
        320000
    };

    int numberOfSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("HEAP SORT PERFORMANCE\n");

    printf("%-10s %-18s %-18s %-18s\n",
           "Size",
           "Random (ms)",
           "Ascending (ms)",
           "Descending (ms)");

    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < numberOfSizes; i++)
    {
        int size = sizes[i];

        int *randomArray = malloc(size * sizeof(int));
        int *ascendingArray = malloc(size * sizeof(int));
        int *descendingArray = malloc(size * sizeof(int));

        if (randomArray == NULL ||
            ascendingArray == NULL ||
            descendingArray == NULL)
        {
            printf("Memory allocation failed.\n");

            free(randomArray);
            free(ascendingArray);
            free(descendingArray);

            return 1;
        }


        generateRandomArray(randomArray, size);
        generateAscendingArray(ascendingArray, size);
        generateDescendingArray(descendingArray, size);


        double randomTime =
            measureTime(randomArray, size);

        double ascendingTime =
            measureTime(ascendingArray, size);

        double descendingTime =
            measureTime(descendingArray, size);

        printf("%-10d %-18.3f %-18.3f %-18.3f\n",
	       size,
               randomTime,
               ascendingTime,
               descendingTime);

        free(randomArray);
        free(ascendingArray);
        free(descendingArray);
    }

    return 0;

}
