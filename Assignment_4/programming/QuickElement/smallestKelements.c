#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {

    int pivotIndex = low + rand() % (high - low + 1);

    swap(&arr[pivotIndex], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSelect(int arr[], int low, int high, int k) {
    if (low >= high)
        return;

    int pivot = partition(arr, low, high);

    if (pivot == k)
        return;
    else if (pivot > k)
        quickSelect(arr, low, pivot - 1, k);
    else
        quickSelect(arr, pivot + 1, high, k);
}

int main() {
    srand(time(NULL));

    int sizes[] = {2000, 4000, 6000, 8000, 10000, 12000, 14000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Dataset Size\tExecution Time (ms)\n");
    printf("----------------------------------------\n");

    for (int s = 0; s < numSizes; s++) {

        int n = sizes[s];

        int *arr = (int *)malloc(n * sizeof(int));

        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        int k = n / 10;

        clock_t start = clock();

        quickSelect(arr, 0, n - 1, k - 1);

        clock_t end = clock();

        double executionTime =
            ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;

        printf("%d\t\t%.3f ms\n", n, executionTime);

        free(arr);
    }

    return 0;
}
