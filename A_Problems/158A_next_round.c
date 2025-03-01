#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    
    return 0;
}
