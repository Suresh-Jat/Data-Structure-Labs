#include <stdio.h>
int q[5], front = -1, rear = -1;

void insertFront()
{
    int data;
    printf("Enter the Number -> ");
    scanf("%d", &data);

    if (rear == 4)
    {
        printf("Can't Insert at Front as Queue is Full\n");
    }
    else if (front == -1)
    {
        front = rear = 0;
        q[front] = data;
    }
    else
    {
        for (int i = rear; i >= front; i--)
        {
            q[i + 1] = q[i];
        }
        q[0] = data;
        rear++;
    }
}

void insertRear()
{
    int data;
    printf("Enter the Number -> ");
    scanf("%d", &data);
    if (rear == 4)
    {
        printf("Can't Insert at Rear/End as Queue is Full\n");
    }
    else if (rear == -1)
    {
        front = rear = 0;
        q[front] = data;
    }
    else
    {
        rear++;
        q[rear] = data;
    }
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Can't Delete Element from Front as Queue is Empty!\n");
        return;
    }
    printf("\nFront Element |%d| is Deleted\n", q[front]);
    if (front == rear && front != -1)
    {
        front = rear = -1;
    }
    else
    {

        for (int i = front + 1; i <= rear; i++)
        {
            q[i - 1] = q[i];
        }
        rear--;
    }
}

void deleteRear()
{
    if (front == -1 || rear == -1)
    {
        printf("Can't Delete Element from End as Queue is Empty\n");
        return;
    }
    printf("\nRear Element |%d| is Deleted\n", q[rear]);

    if (front == rear && front != -1)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

void Display()
{
    if (rear == -1 || front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    if (rear == front)
    {
        printf("**********************\n");
        printf("|%d| <-Front and Rear\n", q[front]);
    }
    else
    {
        printf("**************\n");
        printf("|%d| <-Front\n", q[front]);
        for (int i = front + 1; i < rear; i++)
        {
            printf("|%d|\n", q[i]);
        }
        printf("|%d| <-Rear\n", q[rear]);
    }
}

int main()
{
    int ch;
    int leave = 1;
    printf("Program By Suresh Jat\n");
    while (leave == 1)
    {
        printf("\n1: Insert at Front   2: Insert at Rear   3: Delete from Front   4: Delete from Rear   5: Display   6: Exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertFront();
            break;
        case 2:
            insertRear();
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            Display();
            break;
        case 6:
            leave = 0;
            break;
        default:
            printf("Enter a Valid Choice!\n");
            break;
        }
    }
    return 0;
}
