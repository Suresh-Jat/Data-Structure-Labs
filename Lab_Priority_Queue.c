#include <stdio.h>
int front = -1;
int rear = -1;
int queue[4];

void Priority()
{
    int temp;
    if (queue[rear-1]<queue[rear])
    {
        temp=queue[rear-1];
        queue[rear]=queue[rear-1];
        queue[rear-1]=temp;
    }

}

void Insertion(int ch)
{
    if (rear == 3)
    {
        printf("Queue is full");
    }

    if (front == -1)
    {
        front = rear = 0;
        queue[front] = ch;
    }
    else
    {
        rear++;
        queue[rear] = ch;
    }
}

int Deletion()
{
    int del;
    if (front == -1 || rear == -1 || front > rear)
    {
        printf("No one in Queue");
    }
    else
    {
        del = queue[front];
        front++;
        return del;
    }
}

void Display()
{
    if (front == -1 || rear == -1 || front > rear)
    {
        printf("Nothing to display \n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
int main()
{
    int num, ch, exit = 1;
    while (exit == 1)
    {
        printf("\n\n1:Insert   2:Delete   3:Display   0:Exit");
        printf("\nEnter the choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Element :");
            scanf("%d", &num);
            Insertion(num);
            Priority();
            break;
        case 2:
            printf("Element %d is Deleted !", Deletion());
            break;
        case 3:
            printf("[ ");
            Display();
            printf("]");
            break;
        case 0:
            exit = 0;
            break;
        default:
            break;
        }
    }

    return 0;
}