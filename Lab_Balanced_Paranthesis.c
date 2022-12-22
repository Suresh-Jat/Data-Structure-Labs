#include <stdio.h>
char stack[10];
int top = -1;

int isFull()
{
    if (top == 9)
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
        printf("Stack is empty\n");
        return 1;
    }
    else
        return 0;
}
void Push(char exp)
{
    if (!isFull())
    {
        top++;
        stack[top] = exp;
    }
}

char Pop()
{
    char x;
    if (!isEmpty())
    {
        x = stack[top];
        top--;
        return x;
    }
}

int main()
{
    printf("Program by Suresh Jat");
    char exp[10];
    int flag=0;

    printf("\n\nEnter the Expression: ");
    scanf("%s", exp);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            Push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            char check;
            if (top == -1)
            {
                flag=1;
                break;
            }
            check = Pop();

            if ((exp[i] == ')' && check == '(') || (exp[i] == '}' && check == '{') || (exp[i] == ']' && check == '['))
            {
            }
            else
            {
                printf("Invalid Epression");
                break;
            }
        }
    }
    if (top != -1||flag==1)
    {
        printf("Invalid expression\n");
    }
    else
    {
        printf("Valid Expression ");
    }
    return 0;
}
