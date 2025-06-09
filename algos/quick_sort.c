#include <stdio.h>

void print(char *name, int arr[], int size) {
    printf("%s array: [", name);
    if(size == 0) {
        printf(" ]\n");
        return;
    }
    printf(" %d, ", arr[0]);
    for(int i = 1; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n", arr[size-1]);
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low -1;
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        printf("Pivot: %d\n", pi);
        int n = 9;
        print("steps", arr, n);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


int main() {
    int arr[] = { 1, 2, 3, 4, 5, 12, 24, 34, 42, 54, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    print("Not sorted", arr, n);
    quickSort(arr, 0, n-1);
    print("Sorted", arr, n);

    return 0;
}
