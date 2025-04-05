#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct node {
    int key;
    struct node *next;
};

struct node *enqueue(struct node *tail, int element, int *total_sum) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;

    if (tail == NULL) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    *total_sum += element;  // Actualizar la suma acumulativa
    return tail;
}

int dequeue(struct node **tail, int *total_sum) {
    struct node *firstNode;
    int element;

    if (*tail == (*tail)->next) {
        element = (*tail)->key;
        free(*tail);
        *tail = NULL;
    } else {
        firstNode = (*tail)->next;
        element = firstNode->key;
        (*tail)->next = firstNode->next;
        free(firstNode);
    }

    *total_sum -= element;  // Actualizar la suma acumulativa
    return element;
}

int queueEmpty(struct node *tail) {
    return tail == NULL;
}

int main() {
    struct node *tail = NULL;
    int num_cases, Q, operation, value, total_sum = 0;

    scanf("%d", &num_cases);  // Leer número de casos

    for (int c = 0; c < num_cases; c++) {
        scanf("%d", &Q);  // Número de operaciones en este caso

        total_sum = 0;  // Reiniciar suma acumulativa
        tail = NULL;    // Reiniciar la cola

        for (int i = 0; i < Q; i++) {
            scanf("%d", &operation);

            if (operation == 1) {
                scanf("%d", &value);
                tail = enqueue(tail, value, &total_sum);
            } else if (operation == 2) {
                if (!queueEmpty(tail)) {
                    dequeue(&tail, &total_sum);
                }
            } else if (operation == 3) {
                if (!queueEmpty(tail)) {
                    printf("%d\n", total_sum);  // Imprimir suma acumulativa
                } else {
                    printf("Empty!\n");
                }
            }
        }
    }

    return 0;
}
