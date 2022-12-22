#include <stdio.h>
#include <ctype.h>
#include <math.h>
int stack[10];
int top = -1;
void push(char ch)
{
    if (top == 9)
    {
        printf("Stack is full\n");
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
        printf("Stack is empty\n");
    }
    else
    {
        ch = stack[top];
        top--;
        return ch;
    }
}
int main()
{
    char exp[10];
    int a, b;
    char add, sub, mul, div,power;
    char op;
    printf("\nEnter the Expression:");
    scanf("%s", exp);

    // Traversing the expression
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(exp[i] - 48);
        }
        else
        {
            b = pop();
            a = pop();
            op = exp[i];
            switch (op)
            {
            case '/':
                div = (a / b);
                push(div);

                break;
            case '*':
                mul = (a * b);
                push(mul);

                break;
            case '-':
                sub = (a - b);
                push(sub);

                break;
            case '+':
                add = (a + b);
                push(add);

                break;
            case '^':
                power = pow(a , b);
                push(power);

                break;

            default:
                break;
            }
        }
    }
    printf("Answer = %d", pop());

    return 0;
}
