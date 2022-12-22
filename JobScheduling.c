#include <stdio.h>
struct queue
{
    int Jobno;
    int artm;
} q[5];
int rear = -1;
int front = -1;
void Insert(int jb, int tm)
{
    if (rear == 4)
    {
        printf("Queue is FULL");
    }
    else if (front == -1)
    {
        front = rear = 0;
        q[rear].Jobno = jb;
        q[rear].artm = tm;
    }
    else
    {
        rear++;
        q[rear].Jobno = jb;
        q[rear].artm = tm;
    }
}

void Deletion()
{
    int min, index;
    if (front == -1)
    {
        printf("Queue is Empty ");
    }
    else
    {
        int temp;
        min = q[front].artm;
        for (int i = front; i <= rear; i++)
        {
            if (min > q[i].artm)
            {
                min = q[i].artm;
                index = i;
            }
        }
        temp = q[index].Jobno;

        for (int i = index + 1; i <= rear; i++)
        {
            q[i - 1] = q[i];
        }
        rear--;
        printf("\nJob |%d| Deleted", temp);
    }
}

void Display()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {

        for (int i = front; i <= rear; i++)
        {
            printf("\nJob |%d|  Arrival |%d|", q[i].Jobno, q[i].artm);
        }
    }
}

int main()
{
    int n, jb, at, e = 1;
    do
    {

        printf("\n1: Insert   2: Delete   3:Display   4: Exit\nEnter Your Choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nEnter Job Number: ");
            scanf("%d", &jb);
            printf("\nEnter Arrival Time: ");
            scanf("%d", &at);
            Insert(jb, at);
            break;
        case 2:
            Deletion();
            break;
        case 3:
            Display();
            break;
        case 4:
            e = 0;
            break;
        default:
            printf("\nEnter Valid Choice!");
            break;
        }
    } while (e == 1);
    return 0;
}
