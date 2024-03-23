#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 100

// Define the file name
#define FILENAME "queue_data.txt"

// Define the queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue) {
    queue->front = -1; // Set front to -1 to indicate an empty queue
    queue->rear = -1;  // Set rear to -1 to indicate an empty queue
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

// Function to add an element to the rear of the queue (enqueue)
void enqueue(struct Queue *queue, int value) {
    FILE *file;
    file = fopen(FILENAME, "a+");
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0; // If queue is initially empty, set front to 0
    }
    queue->rear++;
    queue->items[queue->rear] = value;
    fprintf(file, "%d\n", value);
    fclose(file);
}

// Function to remove and return the element from the front of the queue (dequeue)
int dequeue(struct Queue *queue) {
    FILE *file;
    file = fopen(FILENAME, "r");
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int dequeuedItem = queue->items[queue->front];
    queue->front++;
    fclose(file);
    return dequeuedItem;
}

// Function to display the elements of the queue
void display(struct Queue *queue) {
    FILE *file;
    file = fopen(FILENAME, "r");
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
    fclose(file);
}

int main() {
    struct Queue queue;
    initialize(&queue);

    // Enqueue elements into the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Display elements of the queue
    display(&queue);

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    // Display elements of the queue after dequeue
    display(&queue);

    return 0;
}

