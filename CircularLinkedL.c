/* Create a Circular linked list with nodes having information about a student and perform
1] Insert a new node at specified position.
2] Delete of a node with the roll number of student specified.
3] Reversal of that linked list.   */

#include <stdio.h>
#include <stdlib.h>

void Insert();
void Delete();
void Display();
void Reverse();

struct node
{
    int roll_no;
    char name[20];
    struct node *next;
};

int loc;
struct node *head = NULL, *newnode = NULL, *temp = NULL;

int main()
{
    int n;
    int exit = 1;
    while (exit == 1)
    {
        printf("\n------------------------------------------------------------------");
        printf("\n1: Insert at specific position  2: Delete by Roll No.    3: Reverse Linked List   4: Display     5: Exit\nEnter Your Option:");
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
            Reverse();
            break;
        case 4:
            Display();
            break;
        case 5:
            exit = 0;
            break;
        default:
            printf("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}

void InEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Roll No.: ");
    scanf("%d", &newnode->roll_no);
    printf("Enter Name: ");
    scanf("%s", &newnode->name);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void Insert()
{
    int count = 0;
    if (head == NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Roll No.: ");
        scanf("%d", &newnode->roll_no);
        printf("Enter Name: ");
        scanf("%s", &newnode->name);
        newnode->next = NULL;
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
            printf("Enter Roll No.: ");
            scanf("%d", &newnode->roll_no);
            printf("Enter Name: ");
            scanf("%s", &newnode->name);
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

void Delete()
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

void Reverse()
{
    struct node *prev, *cur, *next, *last;

    if (head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }

    last = head;

    prev = head;
    cur = head->next;
    head = head->next;

    while (head != last)
    {
        head = head->next;
        cur->next = prev;

        prev = cur;
        cur = head;
    }

    cur->next = prev;
    head = prev;
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
        printf("Roll No.: %d\n", temp->roll_no);
        printf("Name: %s\n\n", temp->name);
        temp = temp->next;
    }
    printf("NULL");
}
