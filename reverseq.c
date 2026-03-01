#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

// Enqueue function
void enqueue(int value) {
    queue[++rear] = value;
}

// Function to reverse queue
void reverseQueue(int size) {
    int temp[MAX];

    // Copy in reverse order
    for(int i = 0; i < size; i++) {
        temp[i] = queue[size - 1 - i];
    }

    // Copy back to original queue
    for(int i = 0; i < size; i++) {
        queue[i] = temp[i];
    }
}

int main() {
    int capacity;

    scanf("%d", &capacity);

    for(int i = 0; i < capacity; i++) {
        int value;
        scanf("%d", &value);
        enqueue(value);
    }

    // Print Original Queue
    printf("Original queue: ");
    for(int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if(i != rear)
            printf(" ");
    }

    // Reverse only existing elements
    reverseQueue(capacity);

    // Print Reversed Queue
    printf("\nReversed queue: ");
    for(int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if(i != rear)
            printf(" ");
    }

    return 0;
}