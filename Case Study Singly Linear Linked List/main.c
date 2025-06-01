#include"header.h"



int main()
{
    struct Node* head = NULL;
    int choice =1, value=0, position=0;

    while (choice != 0)
        {
        system("cls");
        printf("\n===================================== Omkar Mohite ====================================\n");
        printf("\n------------------------------------- Select A Choice-----------------------------------\n");
        printf("\t\t1. Insert at Beginning\n");
        printf("\t\t2. Insert at End\n");
        printf("\t\t3. Insert at Position\n");
        printf("\t\t4. Delete at Beginning\n");
        printf("\t\t5. Delete at End\n");
        printf("\t\t6. Delete at Position\n");
        printf("\t\t7. Search Element\n");
        printf("\t\t8. Display List\n");
        printf("\t\t9. Exit\n");
        printf("\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
                choice = 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
         printf("\nPress any key to continue...");
        getch();
    }

    return 0;
}
