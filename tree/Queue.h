#include<stdio.h>
#include<stdlib.h>

#ifndef Queue_h
#define Queue_h

struct TreeNode {
  struct TreeNode *lChild;
  int data;
  struct TreeNode *rChild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct TreeNode **Q;
};

typedef struct Queue queue;

void create(queue *q, int size) {
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct TreeNode **)malloc(q->size * sizeof(struct TreeNode  *));
}

int isFull(queue q) {
    return (q.rear+1)%q.size==q.front?1:0;
}

int isEmpty(queue q) {
    return q.rear==q.front?1:0;
}

void enqueue(queue *q, struct TreeNode *x) {
    if((q->rear+1)%q->size==q->front)printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct TreeNode * dequeue(queue *q) {
    struct TreeNode *x=NULL;
    if(q->rear==q->front)printf("Queue is Empty");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

#endif
