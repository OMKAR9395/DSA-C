#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void insertAtFirst(struct Node** head, int value);
void insertAtLast(struct Node** head, int value);
void insertAtPosition(struct Node** head, int value, int position);
void deleteAtFirst(struct Node** head);
void deleteAtLast(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
void displayList(struct Node* head);
void searchElement(struct Node* head, int key);

int main() 
{
    struct Node* head = NULL;

    insertAtFirst(&head, 20);
    insertAtFirst(&head, 10);
    insertAtLast(&head, 40);
    insertAtPosition(&head, 30, 3);

    printf("\nList after insertions:\n");
    displayList(head);

    searchElement(head, 30);
    searchElement(head, 50);

    deleteAtFirst(&head);
    deleteAtLast(&head);
    deleteAtPosition(&head, 2);

    printf("\nList after deletions:\n");
    displayList(head);

    return 0;
}

void insertAtFirst(struct Node** head, int value) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtLast(struct Node** head, int value) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

void insertAtPosition(struct Node** head, int value, int position) 
{
    if (position < 1) 
    {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) 
    {
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at position %d.\n", value, position);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Position %d is out of bounds.\n", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
}

void deleteAtFirst(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty. Cannot delete from beginning.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void deleteAtLast(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty. Cannot delete from end.\n");
        return;
    }

    if ((*head)->next == NULL) 
    {
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

void deleteAtPosition(struct Node** head, int position) 
{
    if (*head == NULL || position < 1) 
    {
        printf("Invalid position or list is empty.\n");
        return;
    }

    if (position == 1) 
    {
        struct Node* temp = *head;
        *head = (*head)->next;
        printf("Deleted %d from position %d.\n", temp->data, position);
        free(temp);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp->next == NULL) 
    {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted %d from position %d.\n", toDelete->data, position);
    free(toDelete);
}

void displayList(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void searchElement(struct Node* head, int key) 
{
    int position = 1;
    while (head != NULL) 
    {
        if (head->data == key) 
        {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}
