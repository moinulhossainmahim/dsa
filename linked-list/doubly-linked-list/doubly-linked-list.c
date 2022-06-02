#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    struct Node *t,*last;
    int i;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void displayNodes(struct Node *p)
{
    while(p!=NULL) {
        printf("%d ", p->data);
        p=p->next;
    }
}

int Length(struct Node *p)
{
    int len=0;
    while(p!=NULL) {
        len++;
        p=p->next;
    }
    return len;
}

void insert(struct Node *p, int index, int x)
{
    int i;
    struct Node *t;
    if(index < 0 || index > Length(p))return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        if(first==NULL)
        {
            t->next=NULL;
            t->prev=NULL;
            first=t;
        }
        else
        {
            t->next=first;
            t->prev=NULL;
            first->prev=t;
            first=t;
        }
    }
    else
    {
        for(i=0; i<index-1&&p; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next) p->next->prev=t;
        p->next=t;
    }
}

int deleteNode(struct Node *p, int index)
{
    int i,x=-1;
    if(index<1 || index>Length(p))
        return -1;
    if(index==1)
    {
        first=first->next;
        if(first) first->prev=NULL;
        x=p->data;
        free(p);
    }
    else
    {
        for(i=0; i<index-1; i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

void reverseDLL(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
        {
            first=p;
        }
    }
}

int main() {
    int A[] = {2, 3, 4, 7, 6};
    create(A, 5);
    reverseDLL(first);
    displayNodes(first);
    return 0;
}
