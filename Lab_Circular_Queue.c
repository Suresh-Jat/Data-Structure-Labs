#include <stdio.h>
int front = -1;
int rear = -1;
int queue[3];

void Insertion(int ch)
{
    if ((front == 0 && rear == 2) || front == rear + 1)
    {
        printf("Queue is full");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
        queue[front] = ch;
    }
    else
    {
        if (rear == 2)
        {
            rear = 0;
            queue[rear] = ch;
        }
        else
        {
            rear++;
            queue[rear] = ch;
        }
    }
}

int Deletion()
{
    int del;
    if (front == -1 || rear == -1)
    {
        del = queue[front];
        printf("Queue is Empty\n");
    }
    else if (front == rear)
    {
        del = queue[front];
        front = rear = -1;
    }
    else if (front == 2)
    {
        del = queue[front];
        front = 0;
    }

    else
    {
        del = queue[front];
        front++;
    }
    return del;
}

void Display()
{
    if (front == -1 || rear == -1)
    {
        printf("Nothing in Queue");
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        else
        {
            for (int i = front; i <= 2; i++)
            {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
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