#include <stdio.h>

int stack[10];
int top = -1;

void push(int rem)
{
    if (top == 9)
    {
        printf("Stack Full");
    }
    else
    {
        top++;
        stack[top] = rem;
    }
}

int pop()
{
    int r;
    r = stack[top];
    top--;
    return r;
}

int main()
{
    int num, rem, r;
    printf("Enter the Decimal Number : ");
    scanf("%d", &num);

    printf("\nBinary Equivalent of %d = ",num);
    
    while (num != 0)
    {
        rem = num % 2;
        push(rem);
        num = num / 2;
    }

    while (top != -1)
    {
        printf("%d", pop());
    }
}
