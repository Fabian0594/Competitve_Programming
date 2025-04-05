#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

struct node *deleteFirstNodeInCircularLinkedList(struct node *tail) {
    struct node *firstNode;

    if (tail == NULL) {
        printf("The circular linked list is empty.\n");
    } else {
        if (tail == tail->next) {
            free(tail);
            tail = NULL;
        } else {
            firstNode = tail->next;
            tail->next = firstNode->next;
            free(firstNode);
        }
    }
    return tail;
}

void printCircularLinkedList(struct node *tail) {
    struct node *actualNode;

    if (tail == NULL) {
        printf("NULL\n");
    } else {
        actualNode = tail->next;
        while (actualNode != tail) {
            printf("%d -> ", actualNode->key);
            actualNode = actualNode->next;
        }
        printf("%d ...\n", tail->key);
    }
}

int main() {
    struct node *tail;
    int operation, element;

    tail = NULL;
    while (scanf("%d", &operation) != EOF) {
        if (operation == 1) { /* Insert */
            scanf("%d", &element);
            tail = insertElementInCircularLinkedList(tail, element);
            printCircularLinkedList(tail);
        } else if (operation == 2) { /* Delete */
            tail = deleteFirstNodeInCircularLinkedList(tail);
            printCircularLinkedList(tail);
        } else {
            printf("Bad use.\n1. Insert\n2. Delete\n");
        }
    }
    return 0;
}