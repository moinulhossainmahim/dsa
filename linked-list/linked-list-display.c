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

int main() {
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 15, 6, 9, 32};
    create(A, 8);
    temp=linearSearch(first, 6);
    temp=linearSearch(first, 32);
    if(temp)
        printf("Key is found %d\n", temp->data);
    else
        printf("Key is not found\n");
    Display(first);
    return 0;
}




