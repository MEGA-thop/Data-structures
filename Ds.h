#ifndef DS_H
#define DS_H

#include <stdio.h>

#define MAX 5

/* ===================== STACK ===================== */

typedef struct {
    int data[MAX];
    int top;
} Stack;

void s_init(Stack *s) {
    s->top = -1;
}

int s_isfull(Stack *s) {
    return s->top == MAX - 1;
}

int s_isempty(Stack *s) {
    return s->top == -1;
}

int s_push(Stack *s, int x) {
    if (s_isfull(s)) return 0;
    s->data[++s->top] = x;
    return 1;
}

int s_pop(Stack *s) {
    if (s_isempty(s)) return 0;
    s->top--;
    return 1;
}

int s_peek(Stack *s) {
    if (s_isempty(s)) return 0;
    return s->data[s->top];
}

/* ===================== LINEAR QUEUE ===================== */

typedef struct {
    int data[MAX];
    int f, r;
} Queue;

void q_init(Queue *q) {
    q->f = -1;
    q->r = -1;
}

int q_isfull(Queue *q) {
    return q->r == MAX - 1;
}

int q_isempty(Queue *q) {
    return q->f == -1;
}

int q_enqueue(Queue *q, int x) {
    if (q_isfull(q)) return 0;

    if (q_isempty(q))
        q->f = 0;

    q->data[++q->r] = x;
    return 1;
}

int q_dequeue(Queue *q) {
    if (q_isempty(q)) return 0;

    if (q->f == q->r) {
        q->f = q->r = -1;
    } else {
        q->f++;
    }
    return 1;
}

/* ===================== CIRCULAR QUEUE ===================== */

typedef struct {
    int data[MAX];
    int f, r;
} CQueue;

void cq_init(CQueue *cq) {
    cq->f = -1;
    cq->r = -1;
}

int cq_isfull(CQueue *cq) {
    return ( (cq->r + 1) % MAX == cq->f );
}

int cq_isempty(CQueue *cq) {
    return cq->f == -1;
}

int cq_enqueue(CQueue *cq, int x) {
    if (cq_isfull(cq)) return 0;

    if (cq_isempty(cq)) {
        cq->f = 0;
        cq->r = 0;
    } else {
        cq->r = (cq->r + 1) % MAX;
    }

    cq->data[cq->r] = x;
    return 1;
}

int cq_dequeue(CQueue *cq) {
    if (cq_isempty(cq)) return 0;

    if (cq->f == cq->r) {
        cq->f = cq->r = -1;
    } else {
        cq->f = (cq->f + 1) % MAX;
    }
    return 1;
}

#endif
