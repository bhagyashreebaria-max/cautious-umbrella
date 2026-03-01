#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
void insertBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void reverseList() {
    struct Node *prev = NULL, *current = head, *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
}
int main() {
    int N, value;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        insertBeginning(value);
    }
    display();
    reverseList();
    printf("\n");
    display();

    return 0;
}