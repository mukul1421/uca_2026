#include <stdio.h>

int merge(int arr[], int start, int mid, int end) {

    int count = 0;

    int j = mid + 1;
    for (int i = start; i <= mid; i++) {
        while (j <= end && arr[i] > 2LL * arr[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    int temp[end - start + 1];
    int i = start;
    j = mid + 1;
    int z = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[z++] = arr[i++];
        } else {
            temp[z++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[z++] = arr[i++];
    }

    while (j <= end) {
        temp[z++] = arr[j++];
    }

    for (i = start; i <= end; i++) {
        arr[i] = temp[i - start];
    }

    return count;
}

int mergeSort(int arr[], int start, int end) {

    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;

    int left = mergeSort(arr, start, mid);
    int right = mergeSort(arr, mid + 1, end);
    int count = merge(arr, start, mid, end);

    return left + right + count;
}

int reversePairs(int arr[], int n) {
    return mergeSort(arr, 0, n - 1);
}

int main() {

    int arr[] = {2, 4, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", reversePairs(arr, n));

    return 0;
}
