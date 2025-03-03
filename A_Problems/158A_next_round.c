#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int lineal_search(int arr[], int element, int arr_size) {
    for (int i = 0; i < arr_size; i++)
    {
        if(arr[i] == element)
            return element;
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    int first_ocurrence = lineal_search(arr, k, n);
    if (first_ocurrence == -1)
    {
        printf("");
    } 

    return 0;
}
