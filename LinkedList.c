#include <stdio.h>
#include <stdlib.h>
void Insert();
void Delete();
void Display();

struct node
{
    int data;
    struct node *next;
};

int loc;
struct node *head=NULL,*newnode=NULL, *temp=NULL;

int main()
{
    int n;
    while (1)
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
            exit(0);
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

void InEnd()
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

void InAtPosition()
{
     newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

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
            temp = head;
            for (int i = 1; i < loc - 1; i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void Insert()
{
    int n;
    printf("\n----Enter Data at----\n1: Beginning  2: End  3: Specific Position: ");
    scanf("%d", &n);
    printf("\n-----INSERT-----\n");
    switch (n)
    {
    case 1:
        InBeginning();
        break;
    case 2:
        InEnd();
        break;
    case 3:
        InAtPosition();
        break;

    default:
        printf("Enter a valid Choice!\n");
        break;
    }
}

void DelBeginning()
{
    int deleted;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        deleted=temp->data;
        head = head->next;
        free(temp);
        printf("Successfully Deleted %d !\n",deleted);
    }
}

void DelEnd()
{
    int deleted;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        struct node *prevnode;
        temp = head;
        while (temp->next != NULL)
        {
            prevnode = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
        }
        else
        {
            prevnode->next = NULL;
        }
        deleted=temp->data;
        free(temp);
        printf("Successfully Deleted %d !\n",deleted);
    }
}

void DelfromPosition()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        int pos;
        struct node *nextnode;
        printf("Enter the position to be deleted :");
        scanf("%d", &pos);
        temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
        printf("Successfully Deleted\n");
    }
}

void Delete()
{
    int n;
    printf("\n----Delete data from----\n1: Beginning  2: End  3: Specific Position: ");
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
        DelfromPosition();
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
    printf("\nValues in Linked List:\n");
    if (head == NULL)
    {
        printf("Linked List is Empty!\n");
    }

    while (temp != NULL)
    {
        printf("|%d|->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}