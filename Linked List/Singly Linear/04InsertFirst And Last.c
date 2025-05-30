#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtFirst(struct Node** head, int value);
void insertAtLast(struct Node** head, int value);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;

    // Inserting elements
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 10);
    insertAtLast(&head, 30);
    insertAtLast(&head, 40);

    printf("Final Linked List:\n");
    displayList(head);

    return 0;
}

void insertAtFirst(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtLast(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Inserted %d at the end.\n", value);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
