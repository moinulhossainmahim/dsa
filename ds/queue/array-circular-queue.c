#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

typedef struct Queue queue;

void create(queue *q, int size) {
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size * sizeof(int));
}

int isFull(queue q) {
    return (q.rear+1)%q.size==q.front?1:0;
}

int isEmpty(queue q) {
    return q.rear==q.front?1:0;
}

void enqueue(queue *q, int x) {
    if((q->rear+1)%q->size==q->front)printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(queue *q) {
    int x=-1;
    if(q->rear==q->front)printf("Queue is Empty");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void display(queue q) {
    int i=q.front+1;
    do
    {
        printf("%d ", q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

int main() {
    queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printf("%d\n", dequeue(&q));
    display(q);
    return 0;
}

