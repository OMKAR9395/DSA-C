#include<stdio.h>
#include<conio.h>

#define MAX  5

int Queue[MAX];
int  Rear = 0;
int  Front = 0;

int Is_Queue_Full()
{
            if(Rear == MAX)
            {
                        return 1;
            }
            return  0;
}

int Is_Queue_Empty()
{
                if(Front ==  Rear )
                {
                            return 1;
                }
                return 0;
}

void Enqueue(int No)
{
            if(Is_Queue_Full())
            {
                        printf("\n Queue Already Full, Can't Enqueue Any Element!!!");
            }
            else
            {
                        Queue[Rear] = No;
                        Rear++;

                        printf("\n %d Enqueued Successfully.", No);
            }
            return;
}

void Dequeue()
{
                if(Is_Queue_Empty())
                {
                            printf("\n Queue Already Empty, Can't Dequeue Any Element!!!");
                }
                else
                {
                            printf("\n\n Element Deleted is = %d",Queue[Front]);
                            Queue[Front] = 0;
                            Front++;
                }
                return;
}

void Display_Queue()
{
            if(Is_Queue_Empty())
            {
                        printf("\n Queue Already Empty, Can't Display Any Element!!!");
            }
            else
            {
                        int i = 0;

                        printf("\n\n Elements In Queue are => \n\t\t\t");

                        for(i = 0 ; i < Rear; i++)
                        {
                                    printf("\t |%4d|", Queue[i]);
                        }
            }
            return;
}

int Count_Queue_Elements()
{
            return  Rear - Front;
}

int main()
{
            Enqueue(21);
            Enqueue(51);

            printf("\n\n Element Count in Queue = %d", Count_Queue_Elements());

            getch();

            Display_Queue();

            Dequeue();
            Dequeue();
            Dequeue();

            getch();

            Display_Queue();

            getch();

            Enqueue(111);
            Enqueue(251);
            Enqueue(210);
            Enqueue(510);
            Enqueue(201);
            Enqueue(501);

            printf("\n\n Element Count in Queue = %d", Count_Queue_Elements());

            getch();

            Display_Queue();

            return 0;
}
