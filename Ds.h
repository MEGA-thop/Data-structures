#ifndef STACK_H
#define STACK_H

//stacks

#define MAX 20
#include <stdio.h>
typedef struct {
    int d[MAX];
    int t;
} Stack;


void initStack(Stack *s)
{
    s->t = -1;
}


int isFull(Stack *s)
{
    return (s->t == MAX - 1);
}


int isEmpty(Stack *s)
{
    return (s->t == -1);
}


int push(Stack *s, int n)
{
    if(isFull(s))
        return 0;
    s->d[++(s->t)] = n;
    return 1;
}


int pop(Stack *s)
{
    if(isEmpty(s))
        return 0;
  s->d[s->t--];
    return 1;
}


int peek(Stack *s)
{
    if(isEmpty(s))
        return 0;
    return s->d[s->t];
}


int display(Stack *s)
{
    if(isEmpty(s))
        return 0;

    for(int i = s->t; i >= 0; i--)
        printf("%d ", s->d[i]);

    printf("\n");
    return 1;
}

//queues

typedef struct  {
    int data[MAX];
    int f,r;
}queue;
void initQueue(queue *que) {
    que->f = -1;
    que->r = -1;
}
int isfull(queue *que) {
    return que->r == MAX - 1;
}
int isempty(queue *que) {
    return que->f == -1;
}
int enqueue(queue *que,int x) {
    if (isfull(que))
        return 0;
    if (isempty(que))
        que->f++;
    que->data[++(que->r)] = x;
    return 1;
}
int dequeue(queue *que) {
    if (isempty(que))
        return 0;
    if (que->r == que->f){
        que->f = -1;
        que->r =- 1;
    }
    else
        que->f++;
    return 1;
}
int qpeekf(queue *que) {
    if (isempty(que))
        return 0;
    return que->data[que->f];

}
int qpeekr(queue *que) {
    if (isempty(que))
        return 0;
    return que->data[que->r];
}

int displayq(queue *que) {
    if (isempty(que)) {
        printf("Queue is empty");
        return 0;
    }
    int i = que->f;
    while (i <= que->r) {
        printf("%d ",que->data[i]);
        i++;
    }
    printf("\n");
    return 1;
}

#endif
