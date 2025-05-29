#include<stdio.h>
#include<conio.h>

struct Node
{
    int Data;
    struct Node* Next;
};
void Insert_Data(struct Node**,int );
void Display_Data(struct Node*);
int main()
{
    struct Node* Head= NULL;

    Insert_Data(&Head,10);
    Insert_Data(&Head,30);
    Insert_Data(&Head,40);

    getch();
    Display_Data(Head);
    Display_Data(Head);
    Display_Data(Head);
    return 0;
    getch();
}
void Insert_Data(struct Node **Add,int Num)
{
    struct Node* New = (struct Node*) malloc (sizeof(struct Node));

    New -> Data = Num;
    New -> Next = NULL;
    if(*Add == NULL)
    {
        *Add = New;
        printf("\n Element Added Successfully");

    }
    else
    {
        New ->Next = *Add;
        *Add = New;
        printf("\n Element Added Successfully");
    }
    return;
}
void Display_Data(struct Node* Element)
{
    while(Element != NULL)
    {
        printf(" | %d |",Element->Data);
        Element = Element->Next;
    }
}
