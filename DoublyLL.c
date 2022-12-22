#include <stdio.h>
#include <stdlib.h>
void Insert();
void Delete();
void Display();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int loc;
struct node *head = NULL, *newnode, *temp, *temp1;

int main()
{
    int n, exit = 1;
    while (exit)
    {
        printf("\n------------------------------------------------------------------");
        printf("\n1: Insert 2: Delete  3: Display 4: Exit\nEnter Your Option:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit = 0;
            break;
        default:
            printf("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}
void InBeginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void InEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
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
        newnode->prev = temp;
    }
}

void InAtPosition()
{
    int count = 0;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        printf("\nEnter Position: ");
        scanf("%d", &loc);
        temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        if (loc == count + 1)
        {
            InEnd();
        }
        else if (loc > count)
        {
            printf("\nPosition %d is Invalid ", loc);
        }

        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter Data:");
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            newnode->prev = NULL;

            temp = head;
            for (int i = 1; i < loc - 1; i++)
            {
                temp = temp->next;
            }

            newnode->next = temp->next;
            newnode->prev = temp;
            newnode->next->prev = newnode;
            temp->next = newnode;
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
        printf("\n-----INSERT AT BEGINNING-----\n");
        InBeginning();
        break;
    case 2:
        printf("\n-----INSERT AT END-----\n");
        InEnd();
        break;
    case 3:
        printf("\n-----INSERT AT POSITION-----\n");
        InAtPosition();
        break;

    default:
        printf("Enter a valid Choice!\n");
        break;
    }
}

void DelBeginning()
{
    int del = head->data;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        if (head->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
        printf("Successfully Deleted [%d] !\n", del);
    }
}

void DelEnd()
{
    int del;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        del = temp->data;
        if (temp == head)
        {
            head = NULL;
        }
        else
        {
            temp->prev->next = NULL;
        }
        free(temp);
        printf("Successfully Deleted [%d] !\n", del);
    }
}

void DelAtPosition()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        int pos, del;
        struct node *nextnode;
        printf("Enter the position to be deleted :");
        scanf("%d", &pos);
        temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            DelBeginning();
        }
        else
        {
            del = temp->data;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            printf("Successfully Deleted [%d] !\n", del);
        }
    }
}

void Delete()
{
    int n;
    printf("\n----Delete Data From----\n1: Beginning  2: End  3: Specific Position: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        DelBeginning();
        break;
    case 2:
        DelEnd();
        break;
    case 3:
        DelAtPosition();
        break;
    default:
        printf("Enter a valid Choice!\n");
        break;
    }
}
void Display()
{
    temp = head;
    printf("\n-----DISPLAY-----\n");
    if (head == NULL)
    {
        printf("Linked List is Empty!\n");
    }
    else
    {
        printf("\n---Values in Linked List:---\n");
        while (temp != NULL)
        {
            printf("[%d] %c ", temp->data, 29);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}