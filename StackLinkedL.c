// Implement stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL, *temp;

void push(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    if (top == NULL)
    {
        newnode->next = NULL;
    }
    else
    {
        newnode->next = top;
    }
    top = newnode;
    printf("\n%d is Inserted\n", newnode->data);
}

int pop()
{
    if (top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        struct node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display()
{
    printf("\n++++++++DISPLAY++++++++\n");
    if (top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf(" STACK: \n\n");
        struct node *temp = top;
        while (temp->next != NULL)
        {
            printf("       |%d|\n         %c\n", temp->data,25);
            temp = temp->next;
        }
        printf("       |%d|\n         %c\n       NULL\n", temp->data,25);
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n+++++++++++++++++++++++\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("\n%d is Popped\n", pop());
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
