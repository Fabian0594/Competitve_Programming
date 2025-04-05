#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define myNegativeInfinite -2147483647
#define myPositiveInfinite 2147483647
#define MAXT 1000

int Parent(int i) {
    return i >> 1;
    /* return i / 2; */
}

int Left(int i) {
    return i << 1;
    /* return 2 * i; */
}

int Right(int i) {
    return (i << 1) + 1;
    /* return 2 * i + 1; */
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

int MinPQ_Minimum(int Q[]) {
    return Q[1];
}

int MinPQ_Extract(int Q[], int *heapSize) {
    int min = myNegativeInfinite;

    if (*heapSize < 1)
        printf("Heap underflow.\n");
    else {
        min = Q[1];
        Q[1] = Q[*heapSize];
        (*heapSize)--;
        MinHeapify(Q, 1, *heapSize);
    }

    return min;
}

void MinPQ_DecreaseKey(int Q[], int i, int key) {
    int temp;

    if (key > Q[i])
        printf("New key is higher than current key.\n");
    else {
        Q[i] = key;
        while ((i > 1) && (Q[Parent(i)] > Q[i])) {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }
}

void MinPQ_Insert(int Q[], int key, int *heapSize) {
    (*heapSize)++;
    Q[*heapSize] = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main() {
    int operation, element, Q[MAXT + 2], heapSize = 0;

    while (scanf(" %d", &operation) != EOF) {
        if (operation == 1) { /* Insert into Priority Queue */
            scanf(" %d", &element);
            MinPQ_Insert(Q, element, &heapSize);
        } else if (operation == 2) { /* Extract min element of the Priority Queue */
            element = MinPQ_Extract(Q, &heapSize);
            if (element == myNegativeInfinite)
                printf("The Min Priority Queue is empty.\n");
            else
                printf("%d\n", element);
        } else {
            printf("Bad use.\n1. Insert into PQ\n2. Extract of the PQ.\n");
        }
    }

    return 0;
}