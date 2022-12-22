#include <stdio.h>
int stack[5];
int top = -1;

int isFull()
{
    if (top == 4)
    {
        printf("Stack Full");
        return 1;
    }
    else
        return 0;
}

int isEmpty()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return 1;
    }
    else
        return 0;
}
void Push()
{
    top++;
    printf("Element:");
    scanf("%d", &stack[top]);
}

void Pop()
{
    top--;
}

void Display()
{
    printf("|%d|<-TOP\n", stack[top]);
    for (int i = --top; i != -1; i--)
    {
        printf("|%d|\n", stack[i]);
    }
}

int main()
{
    printf("Program by Suresh Jat");
    int ch;
    char till;
    do
    {

        printf("\n1:Push  2:Pop   3:Display   4:isFull    5:isEmpty");
        printf("\nEnter the choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (!isFull())
                Push();
            break;
        case 2:
            if (!isEmpty())
                Pop();

            break;
        case 3:
            Display();
            break;
        case 4:
            isFull();
            break;

        case 5:
            isEmpty();
            break;

        default:
            break;
        }
        printf("\nTo Continue Press Y & to Discontinue Press N :");
        scanf("%s", &till);
    } while (till == 'Y' || till == 'y');
    return 0;
}
