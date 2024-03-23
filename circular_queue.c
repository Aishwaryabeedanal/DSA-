#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
#define FILENAME "circular_queue_data.txt"

struct CircularQueue {
    int front, rear;
};

void initialize(struct CircularQueue *queue) {
    FILE *file;
    file = fopen(FILENAME, "w");
    fclose(file);
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct CircularQueue *queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1);
}

int isEmpty(struct CircularQueue *queue) {
    return queue->front == -1;
}

void enqueue(struct CircularQueue *queue, int value) {
    FILE *file;
    file = fopen(FILENAME, "a");
    if (isFull(queue)) {
        printf("Queue is full\n");
        fclose(file);
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    fprintf(file, "%d\n", value);
    fclose(file);
}

int dequeue(struct CircularQueue *queue) {
    FILE *file;
    file = fopen(FILENAME, "r");
    int removedItem;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        fclose(file);
        return -1;
    }
    removedItem = queue->front;
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    fclose(file);
    return removedItem;
}

void display(struct CircularQueue *queue) {
    FILE *file;
    file = fopen(FILENAME, "r");
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        fclose(file);
        return;
    }
    printf("Queue elements: ");
    i = queue->front;
    do {
        printf("%d ", i);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
    fclose(file);
}

int main() {
    struct CircularQueue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Removed item: %d\n", dequeue(&queue));
    printf("Removed item: %d\n", dequeue(&queue));

    display(&queue);

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    display(&queue);

    return 0;
}
