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
        printf("\nCircular Queue Operations");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Find Element");
        printf("\n4. Display Queue");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: findElement(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}void enqueue() {
    if((rear + 1) % MAX == front) {
        printf("Queue Overflow! The circle is full.\n");
        return;
    }int val;
    printf("Enter value to enqueue: ");
    scanf("%d", &val);
    if (front == -1) { 
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX; 
    }queue[rear] = val;
    printf("Inserted %d\n", val);
}void dequeue() {
    if(front == -1) {
        printf("Queue Underflow! No elements to remove.\n");
        return;
    }printf("Dequeued: %d\n", queue[front]);
     if(front == rear) { 
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX; 
    }
}void findElement() {
    if(front == -1) {
        printf("Queue is empty!\n");
        return;
    }int target, found = 0;
    printf("Enter element to find: ");
    scanf("%d", &target);
    int i = front;
    do{
        if(queue[i] == target) {
            printf("Element %d found at array index %d.\n", target, i);
            found = 1;
            break;
        }i = (i + 1) % MAX;
    }while(i != (rear + 1) % MAX);

    if(!found) printf("Element %d not found.\n", target);
}void display() {
    if(front == -1) {
        printf("Queue is empty.\n");
        return;
    }printf("Queue elements: ");
    int i = front;
    while(1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
