#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define myNegativeInfinite -2147483647
#define myPositiveInfinite 2147483647
#define MAXT 500000  // Tamaño máximo de las listas

int Parent(int i) {
    return i >> 1;
}

int Left(int i) {
    return i << 1;
}

int Right(int i) {
    return (i << 1) + 1;
}

void MinHeapify(int Q[], int i, int heapSize) {
    int l, r, least, temp;
    l = Left(i);
    r = Right(i);

    if ((l <= heapSize) && (Q[l] < Q[i]))
        least = l;
    else
        least = i;

    if ((r <= heapSize) && (Q[r] < Q[least]))
        least = r;

    if (least != i) {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, heapSize);
    }
}

void MaxHeapify(int Q[], int i, int heapSize) {
    int l, r, greatest, temp;
    l = Left(i);
    r = Right(i);

    if ((l <= heapSize) && (Q[l] > Q[i]))
        greatest = l;
    else
        greatest = i;

    if ((r <= heapSize) && (Q[r] > Q[greatest]))
        greatest = r;

    if (greatest != i) {
        temp = Q[i];
        Q[i] = Q[greatest];
        Q[greatest] = temp;
        MaxHeapify(Q, greatest, heapSize);
    }
}

int ExtractMax(int Q[], int *heapSize) {
    if (*heapSize < 1)
        return myNegativeInfinite;

    int max = Q[1];
    Q[1] = Q[*heapSize];
    (*heapSize)--;
    MaxHeapify(Q, 1, *heapSize);
    return max;
}

int ExtractMin(int Q[], int *heapSize) {
    if (*heapSize < 1)
        return myPositiveInfinite;

    int min = Q[1];
    Q[1] = Q[*heapSize];
    (*heapSize)--;
    MinHeapify(Q, 1, *heapSize);
    return min;
}

void InsertMaxHeap(int Q[], int key, int *heapSize) {
    (*heapSize)++;
    Q[*heapSize] = key;
    int i = *heapSize;
    while (i > 1 && Q[Parent(i)] < Q[i]) {
        int temp = Q[i];
        Q[i] = Q[Parent(i)];
        Q[Parent(i)] = temp;
        i = Parent(i);
    }
}

void InsertMinHeap(int Q[], int key, int *heapSize) {
    (*heapSize)++;
    Q[*heapSize] = key;
    int i = *heapSize;
    while (i > 1 && Q[Parent(i)] > Q[i]) {
        int temp = Q[i];
        Q[i] = Q[Parent(i)];
        Q[Parent(i)] = temp;
        i = Parent(i);
    }
}

int main() {
    int cases, n, *ema, *otto;
    int emaSize, ottoSize, turns, emaMax, ottoMin, result;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%d", &n);

        ema = (int *)malloc((n + 1) * sizeof(int));
        otto = (int *)malloc((n + 1) * sizeof(int));

        emaSize = ottoSize = 0;
        for (int i = 0; i < n; i++) {
            int value;
            scanf("%d", &value);

            InsertMaxHeap(ema, value, &emaSize);
        }
        for (int i = 0; i < n; i++) {
            int value;
            scanf("%d", &value);
            InsertMinHeap(otto, value, &ottoSize);
        }

        turns = 0;
        while (emaSize > 0 && ottoSize > 0) {
            emaMax = ExtractMax(ema, &emaSize);
            ottoMin = ExtractMin(otto, &ottoSize);

            result = emaMax + ottoMin;
            if (result % 2 == 0) {
                result /= 2;
                InsertMaxHeap(ema, result, &emaSize);
            } else {
                InsertMinHeap(otto, result, &ottoSize);
            }

            turns++;
        }

        if (emaSize == 0)
            printf("%d Otto\n", turns);
        else
            printf("%d Emma\n", turns);

        free(ema);
        free(otto);
    }

    return 0;
}