#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top=NULL;

void display()
{
    struct Node *p=top;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)printf("Stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *p;
    int x=-1;
    if(top==NULL) printf("Stack is Empty");
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    printf("\npopped value: %d\n", pop());
    display();
    return 0;
}
