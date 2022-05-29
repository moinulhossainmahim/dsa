#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void rDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        rDisplay(p->next);
        printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    int length=0;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;
}

int rCount(struct Node *p)
{
    if(p==NULL)
    {
        return 0;
    }
    return 1+rCount(p->next);
}

int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int rSum(struct Node *p)
{
    if(p==0)
    {
        return 0;
    }
    return rSum(p->next)+p->data;
}

int max(struct Node *p)
{
    int max=-32767;
    while(p!=NULL)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}

int rMax(struct Node *p)
{
    int x=0;

    if(p==NULL)
        return -327676;
    x=rMax(p->next);
    if(x>p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

struct Node* linearSearch(struct Node *p, int key)
{
    struct Node *q;

    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

struct Node* rSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return rSearch(p->next, key);
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index>count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0; i<index-1&&p; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void sortedInsert(struct Node *p, int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}

int deleteNode(struct Node *p, int index)
{
    struct Node *q=NULL;
    int x=-1, i;
    if(index < 1 || index > count(p))
    {
        return -1;
    }
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0; i<index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x=-32767;
    while(p!=NULL)
    {
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

int main() {
    int A[] = {3, 5, 7, 9};
    create(A, 4);
    int result = isSorted(first);
    if(result) printf("Sorted");
    else printf("Not sorted");
    //Display(first);
    return 0;
}
