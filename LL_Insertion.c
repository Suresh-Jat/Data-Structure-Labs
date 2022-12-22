#include <stdio.h>
#include <stdlib.h>
void Insert();
void Display();
struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *newnode;
struct node *temp;

int main()
{
    int n;
    while (1)
    {
        printf("\n1: Insert 2: Display 3: Exit\nEnter the value:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            Insert();
            break;
        case 2:
            Display();
            break;
        case 3:
            exit;
            break;

        default:
            printf("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}
void Beginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void End()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void AtPosition()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        int count = 0;
        int loc;
        printf("Enter Location:");
        scanf("%d", &loc);
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (loc <= count)
        {
            temp = head;
            for (int i = 1; i < loc - 1; i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            printf("Invalid Position!");
        }
    }
}
void Insert()
{
    int n;
    printf("\n----Enter Data at----\n1: Beginning  2: End  3: Specific Position: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        Beginning();
        break;
    case 2:
        End();
        break;
    case 3:
        AtPosition();
        break;

    default:
        printf("Enter a valid Choice!\n");
        break;
    }
}
void Display()
{
    temp = head;
    printf("\nValues in Linked List:\n");
    if (head == NULL)
    {
        printf("Linked List is Empty!\n");
    }

    while (temp != NULL)
    {
        printf("|%d|", temp->data);
        temp = temp->next;
    }
}