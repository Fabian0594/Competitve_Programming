#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node {
    int key;
    struct node *next;
};

struct node *insertElementInCircularLinkedList(struct node *tail, int element) {
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
    return tail;
}

struct node *deleteNode(struct node *tail, struct node *prev) {
    struct node *toDelete = prev->next;

    if (toDelete == tail) {
        if (tail == tail->next) {
            free(tail);
            return NULL;
        }
        tail = prev;
    }

    prev->next = toDelete->next;
    free(toDelete);
    return tail;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int playGame(struct node *tail) {
    struct node *current = tail->next;
    struct node *prev = tail;

    // Buscar el nodo con valor 2 para comenzar desde ahí
    while (current->key != 2) {
        prev = current;
        current = current->next;
    }

    // Comenzar el juego desde el nodo con valor 2
    while (tail != tail->next) {
        if (gcd(current->key, prev->key) > 1) {
            // Eliminar el nodo actual y reiniciar desde el nodo eliminado
            tail = deleteNode(tail, prev);
            current = prev->next;
        } else {
            // Continuar rotando
            prev = current;
            current = current->next;
        }
    }

    int winner = tail->key;
    free(tail);
    return winner;
}

void solve() {
    int t;
    if (scanf("%d", &t) != 1 || t < 1 || t > 100) {
        fprintf(stderr, "Error: Número de casos de prueba inválido.\n");
        return;
    }

    for (int i = 0; i < t; i++) {
        int n;
        if (scanf("%d", &n) != 1 || n < 3 || n > 10000) {
            fprintf(stderr, "Error: Número de estudiantes inválido.\n");
            return;
        }

        struct node *tail = NULL;
        for (int j = 1; j <= n; j++) {
            tail = insertElementInCircularLinkedList(tail, j);
        }

        int winner = playGame(tail);
        printf("Winner: %d\n", winner);
    }
}

int main() {
    solve();
    return 0;
}