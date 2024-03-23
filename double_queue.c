#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Deque {
    int items[MAX_SIZE];
    int front, rear;
};

void initialize(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isFull(struct Deque *deque) {
    return (deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1);
}

int isEmpty(struct Deque *deque) {
    return deque->front == -1;
}

void insertFront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }
    deque->items[deque->front] = value;
}

void insertRear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->items[deque->rear] = value;
}

int deleteFront(struct Deque *deque) {
    int removedItem;
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    removedItem = deque->items[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
    return removedItem;
}

int deleteRear(struct Deque *deque) {
    int removedItem;
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    removedItem = deque->items[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear--;
    }
    return removedItem;
}

void display(struct Deque *deque) {
    int i;
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    i = deque->front;
    do {
        printf("%d ", deque->items[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (deque->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    struct Deque deque;
    initialize(&deque);

    insertFront(&deque, 10);
    insertFront(&deque, 20);
    insertRear(&deque, 30);

    display(&deque);

    printf("Removed front item: %d\n", deleteFront(&deque));
    printf("Removed rear item: %d\n", deleteRear(&deque));

    display(&deque);

    insertFront(&deque, 40);
    insertRear(&deque, 50);

    display(&deque);

    return 0;
}
