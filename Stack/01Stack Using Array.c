#include<stdio.h>
#include<conio.h>
#define MAX 5

int Stack[MAX];
int Top = 0;

int main()
{
            int ret = 0;

            Push(21);
            Push(55);
            Push(12);

            getche();
            Display_Stack();

            getche();
            printf("\n\n Number of Elements in Stack are = %d.\n",Count_Stack_Elements());

            Pop();
            Pop();
            Pop();
            Pop();
            getche();

            ret = Search_Stack_Element(56);

            if(ret < 0)
            {
                printf("\n Number Not Found...");
            }
            else
            {
                printf("\n Given Number Found at Location %d.",ret);
            }

            printf("\n\n Number of Elements in Stack are = %d.\n",Count_Stack_Elements());
            Display_Stack();

            Push(152);
            Push(49);
            Push(58);
            Push(20);

            Display_Stack();

            ret = Search_Stack_Element(56);

            if(ret < 0)
            {
                printf("\n No Not Found...");
            }
            else
            {
                printf("\n Given Number Found at Location %d.",ret);
            }
            printf("\n\n Number of Elements in Stack are = %d.\n",Count_Stack_Elements());

            getch();
            return 0;
}
int Is_Stack_Full()
{
            if(Top == MAX)
            {
                return 1;
            }
            return 0;
}

int Is_Stack_Empty()
{
            if(Top == 0)
            {
                return 1;
            }
            return 0;
}

void Push(int No)
{
            if(Is_Stack_Full())
            {
                printf("\n Stack is already Full... Can't Insert New Element...");
            }
            else
            {
                Stack[Top] = No;
                Top++;
            }
            return;
}

void Pop()
{
            if(Is_Stack_Empty())
            {
                printf("\n Stack is Already Empty So We Can't Delete any element...");
            }
            else
            {
                printf("\n Deleted Element From Stack is = %d.", Stack[Top-1]);
                Stack[Top-1] = 0;
                Top--;
            }
            return;
}
void Display_Stack()
{
            if(Is_Stack_Empty())
            {
                printf("\n Stack is Already Empty So We Can't Display any element...");
            }
            else
            {
                int i = 0;

                printf("\n Current Elements in STACK are => \n ");

                for(i = Top - 1; i >= 0; i--)
                {
                    printf("\t\t |%4d| \n",Stack[i]);
                }
            }
}
int Count_Stack_Elements()
{
            return Top;
}
int Search_Stack_Element(int No)
{
            if(Is_Stack_Empty())
            {
                printf("\n Stack is Already Empty So We Can't Search any element...");
            }
            else
            {
                int Cnt = 0;

                while(Cnt < Top)
                {
                    if(Stack[Cnt] == No)
                    {
                        return Cnt+1;
                    }
                    Cnt++;
                }
            }
            return -1;
}
