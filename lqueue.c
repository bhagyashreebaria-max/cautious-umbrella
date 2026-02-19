#include <stdio.h>
#include <stdlib.h>
   #define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void findElement();
void display();

int main() {
    int choice;
    while (1) {
        printf("\nLinear Queue Operations ");
        printf("\n1. Enqueue (Insert)");
        printf("\n2. Dequeue (Delete)");
        printf("\n3. Find Element (Search)");
        printf("\n4. Display Queue");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                findElement();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}void enqueue() {
    int val;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot add more elements.\n");
    } else {
        if (front == -1) front = 0;
        printf("Enter value to enqueue: ");
        scanf("%d", &val);
        rear++;
        queue[rear] = val;
        printf("Inserted %d\n", val);
    }
}void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to delete.\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}void findElement() {
    int target, i, found = 0;
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Enter element to search for: ");
    scanf("%d", &target);
    
    for (i = front; i <= rear; i++) {
        if (queue[i] == target) {
            printf("Element %d found at position %d (index %d).\n", target, (i - front + 1), i);
            found = 1;
            break;
        }
    }
if (!found) printf("Element %d not found in the queue.\n", target);
}void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Current Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
