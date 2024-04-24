#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub + 1]; // Temporary array to store merged result

    // Merge elements into temporary array in sorted order
    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray to temporary array
    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray to temporary array
    while (j <= ub) {
        b[k] = a[j];
        j++;
        k++;
    }

    // Copy sorted elements from temporary array back to original array
    for (int x = lb; x <= ub; x++) {
        a[x] = b[x];
    }
}

// Function to perform merge sort
void mergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
