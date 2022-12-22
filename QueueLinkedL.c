// Implementation of Queue using linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front, *rear, *ptr;

void insert();
void delete();
void display();
void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n++++++++++++++++++++++++");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    }
}
void insert()
{
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;
    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
        front->next = NULL;
        rear->next = NULL;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
    }
    printf("%d is Inserted\n", item);
}

void delete()
{
    if (front == NULL)
    {
        printf("\nQueue Underflow!\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        printf("%d is Deleted\n", ptr->data);
        free(ptr);
    }
}
void display()
{
    printf("\n++++++++DISPLAY++++++++\n");
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("QUEUE: \n");
        printf("       FRONT\n         %c\n",24);

        while (ptr != NULL)
        {
            printf("       |%d|\n         %c\n", ptr->data,24);
            ptr = ptr->next;
        }
        printf("       REAR");
    }
}
