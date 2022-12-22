#include <stdio.h>
char stack[20];
int top = -1;
char postfix[20];

int priority(char pr)
{
    int high;
    switch (pr)
    {
    case '^':
        high = 3;
        break;

    case '*':
        high = 2;
        break;

    case '/':
        high = 2;
        break;

    case '+':
        high = 1;
        break;

    case '-':
        high = 1;
        break;

    default:
        break;
    }
    return high;
}

void push(char ch)
{
    if (top == 19)
    {
        printf("Stack is Full \n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}
char pop()
{
    char ch;
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        ch = stack[top];
        top--;
    }
    return ch;
}

int main()
{
    char str[20];
    int j = 0;
    printf("\nEnter the Expression :");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'||str[i] == '^')
        {
            if (top == -1)
            {
                push(str[i]);
            }

            else if (priority(str[i]) <= priority(stack[top]))
            {
                while (priority(str[i]) <= priority(stack[top]) && top != -1)
                {
                    postfix[j] = pop();
                    j++;
                }
                push(str[i]);
            }
            else
            {
                push(str[i]);
            }
        }
        else
        {
            postfix[j] = str[i];
            j++;
        }
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
    printf("%s", postfix);

    return 0;
}