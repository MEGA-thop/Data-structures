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

#include <stdio.h>
#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear + 1) % SIZE == front;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue Full\n");
        return;
    }

    if (isEmpty())
        front = 0;

    rear = (rear + 1) % SIZE;
    q[rear] = x;

    printf("%d inserted\n", x);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Empty\n");
        return;
    }

    printf("%d removed\n", q[front]);

    if (front == rear) {
        front = rear = -1;  // queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    return 0;
}


#endif

