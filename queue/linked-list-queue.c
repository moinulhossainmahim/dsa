#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;
node *front=NULL;
node *rear=NULL;

void enqueue(int x) {
    node *t;
    t=(node *)malloc(sizeof(node));
    if(t==NULL)printf("Queue is Full");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL) {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue() {
    int x=-1;
    node *p;
    if(front==NULL)printf("Queue is Empty");
    else
    {
        p=front;
        x=front->data;
        front=front->next;
        free(p);
    }
    return x;
}

void display() {
    node *p=front;
    if(p==NULL)printf("Nothing to display");
    else
    {
        while(p!=NULL) {
            printf("%d ", p->data);
            p=p->next;
        }
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("%d\n", dequeue());
    enqueue(60);
    display();
    return 0;
}
