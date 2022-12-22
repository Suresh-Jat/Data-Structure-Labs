// Create doubly linked list with nodes having information about an employee and perform Insertion at front of doubly linked list and perform deletion at end of that doubly linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int Emp_Salary;
    char Emp_Name[20];
    struct node *next;
    struct node *prev;
};

struct node *newnode, *temp, *head = NULL;

void InsertAtFront()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Employee Salary : ");
    scanf("%d", &newnode->Emp_Salary);
    
    printf("Enter Employee Name : ");
    scanf("%s", &newnode->Emp_Name);
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


void DeleteFromEnd()
{
    struct node *temp1;
    if (head == NULL)
    {
        printf("No Element to Delete!!\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            temp1 = temp->prev;
            temp1->next = NULL;
            free(temp);
        }
    }
}
void Display()
{

    if (head == NULL)
    {
        printf("Nothing to Display!\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            
            printf("Employee Name: %s \n", temp->Emp_Name);
            printf("Employee Salary: %d \n", temp->Emp_Salary);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;
    int exit =0;
    printf("\n");
while(exit==0)
    {
        printf("1:Insert At Front 2:Delete From End 3:Display 4:Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
        case 1:
            printf("\n");
            printf("INSERT AT FRONT :\n");
            printf("------------------------------------------------------------------------\n");

            InsertAtFront();

            printf("------------------------------------------------------------------------\n");
            printf("\n");
            break;

        case 2:
            printf("\n");
            printf("DELETE FROM END:\n");
            printf("------------------------------------------------------------------------\n");

            DeleteFromEnd();

            printf("------------------------------------------------------------------------\n");
            printf("\n");
            break;

        case 3:
            printf("\n");
            printf("DISPLAY :\n");
            printf("------------------------------------------------------------------------\n");

            Display();

            printf("------------------------------------------------------------------------\n");
            printf("\n");
            break;

        case 4:
            exit =1;
            break;

        default:
            printf("Invalid Character\n");
            break;
        }
    }

return 0;
}