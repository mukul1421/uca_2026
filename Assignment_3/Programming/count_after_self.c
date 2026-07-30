#include <stdio.h>
#include <stdlib.h>

int *count;
int *idx;

void merge(int nums[], int start, int mid, int end) {

    int temp[end - start + 1];
    int tempIdx[end - start + 1];

    int i = start;
    int j = mid + 1;
    int z = 0;

    int rightCount = 0;

    while (i <= mid && j <= end) {

        if (nums[i] <= nums[j]) {

            count[idx[i]] += rightCount;

            temp[z] = nums[i];
            tempIdx[z] = idx[i];

            i++;
        }
        else {

            rightCount++;

            temp[z] = nums[j];
            tempIdx[z] = idx[j];

            j++;
        }

        z++;
    }

    while (i <= mid) {

        count[idx[i]] += rightCount;

        temp[z] = nums[i];
        tempIdx[z] = idx[i];

        i++;
        z++;
    }

    while (j <= end) {

        temp[z] = nums[j];
        tempIdx[z] = idx[j];

        j++;
        z++;
    }

    for (i = start; i <= end; i++) {
        nums[i] = temp[i - start];
        idx[i] = tempIdx[i - start];
    }
}

void mergeSort(int nums[], int start, int end) {

    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);

    merge(nums, start, mid, end);
}

int main() {

    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    count = calloc(n, sizeof(int));
    idx = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }

    mergeSort(nums, 0, n - 1);

    printf("Count of Smaller Numbers After Self:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    printf("\n");

    free(count);
    free(idx);

    return 0;
}
