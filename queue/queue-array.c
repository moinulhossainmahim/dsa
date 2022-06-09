#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

typedef struct Queue queue;

void create(queue *q) {
    printf("Enter the size of the queue: ");
    scanf("%d", &q->size);
    q->Q=(int *)malloc(sizeof(int) * q->size);
    q->front=q->rear=-1;
}

void enqueue(queue *q, int x) {
    if(q->rear==q->size-1)printf("Queue if full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(queue *q) {
    int x=-1;
    if(q->front==q->rear)printf("Queue if empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void display(queue q) {
    int i=q.front+1;
    for(; i<=q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main() {
    queue q;
    create(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d\n",dequeue(&q));
    display(q);
    return 0;
}

