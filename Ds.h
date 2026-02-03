#ifndef SAMPLE_DATA_STRUCTURES_H
#define SAMPLE_DATA_STRUCTURES_H
//stacks
#define MAX 20
#include <stdio.h>
/* Check if full */
int isFull(int top)
{
    if(top == MAX - 1)
        return 1;
    return 0;
}
/* Check if empty */
int isEmpty(int top)
{
    if(top == -1)
        return 1;
    return 0;
}
/* Push */
int push(int x[], int *top, int n)
{
    if(isFull(*top))
    {
        printf("Stack Overflow\n");
        return 0;
    }
    (*top)++;
    x[*top] = n;
    return 1;
}
/* Pop */
int pop(int x[], int *top)
{
    if(isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return 0;
    }

    printf("Popped: %d\n", x[*top]);
    (*top)--;
    return 1;
}
/* Peek */
int peek(int x[], int top)
{
    if(isEmpty(top))
    {
        printf("Stack empty\n");
        return 0;
    }
    printf("Top: %d\n", x[top]);
    return 1;
}
/* Display */
int display(int x[], int top)
{
    if(isEmpty(top))
    {
        printf("Stack empty\n");
        return 0;
    }

    for(int i = top; i >= 0; i--)
        printf("%d ", x[i]);

    printf("\n");
    return 1;
}

#endif
