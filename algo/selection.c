#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n) {
    int i, j, min_idx;
    for(i=0; i<n-1; i++) {
        min_idx=i;
        for(j=i+1; j<n; j++) {
            if(arr[j]<arr[min_idx])
            min_idx=j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));

    for(int i=0; i<n; i++) {
        arr[i]= rand() % 1000;
    }

    clock_t start, end;
    double cpu_time_used;

    printf("Array before sorting: \n");
    for(int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
    }

    start=clock();
    SelectionSort(arr, n);
    end=clock();

    printf("Array after sorting: \n");
    for(int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
    }

    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken to sort %d elemrnts is %f seconds.\n", n, cpu_time_used);
}