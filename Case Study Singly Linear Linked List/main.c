#include"header.h"

struct Node {
    int data;
    struct Node* next;
};

// Function declarations
void insertAtFirst(struct Node** head, int value);
void insertAtLast(struct Node** head, int value);
void insertAtPosition(struct Node** head, int value, int position);
void deleteAtFirst(struct Node** head);
void deleteAtLast(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
void displayList(struct Node* head);
void searchElement(struct Node* head, int key);

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n----- Menu -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtFirst(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtLast(&head, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                deleteAtFirst(&head);
                break;
            case 5:
                deleteAtLast(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchElement(head, value);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
