#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define myNegativeInfinite -2147483647
#define myPositiveInfinite 2147483647
#define MAXT 2000000

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

int MinPQ_Minimum(int Q[], int heapSize) {
    if (heapSize < 1)
        return myNegativeInfinite;
    return Q[1];
}

int MinPQ_Extract(int Q[], int *heapSize) {
    int min = myNegativeInfinite;

    if (*heapSize < 1)
        return min;
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
    int Q, operation, element, heap[MAXT + 2], heapSize = 0;

    // Leer el número de consultas
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        scanf("%d", &operation);

        if (operation == 1) { // Insertar en la cola de prioridad
            scanf("%d", &element);
            MinPQ_Insert(heap, element, &heapSize);
        } else if (operation == 2) { // Extraer el mínimo
            MinPQ_Extract(heap, &heapSize);
        } else if (operation == 3) { // Imprimir el mínimo
            int min = MinPQ_Minimum(heap, heapSize);
            if (min == myNegativeInfinite)
                printf("Empty!\n");
            else
                printf("%d\n", min);
        }
    }

    return 0;
}