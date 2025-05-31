#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtFirst(struct Node** head, int value);
void insertAtLast(struct Node** head, int value);
void deleteAtFirst(struct Node** head);
void deleteAtLast(struct Node** head);
void displayList(struct Node* head);
void searchElement(struct Node* head, int key);

int main() {
    struct Node* head = NULL;

    // Insert elements
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 10);
    insertAtLast(&head, 30);
    insertAtLast(&head, 40);

    printf("\nList after insertions:\n");
    displayList(head);

    // Search for elements
    searchElement(head, 30);   // Found
    searchElement(head, 25);   // Not found

    deleteAtFirst(&head);
    deleteAtLast(&head);

    printf("\nList after deletions:\n");
    displayList(head);

    return 0;
}

void insertAtFirst(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtLast(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
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

void deleteAtFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }

    if ((*head)->next == NULL) {
        printf("Deleted %d from the end.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted %d from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void searchElement(struct Node* head, int key) {
    int position = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}
