#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b= temp;
}

int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int i=low-1;
    for(int j=low; j<=high-1; j++) {
        if(arr[j]<pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low<high) {
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}


int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));
    clock_t start, end;
    double cpu_time_used;
    for(int i=0; i<n; i++) {
        arr[i]=rand() % 1000;
    }

    printf("Array before sorting: \n");
    for(int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
    }

    start=clock();
    quickSort(arr, 0, n-1);
    end=clock();

    printf("Array after sorting: \n");
    for(int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
    }
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Time taken to sort %d elemets is %f seconds.\n", n, cpu_time_used);
}