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

int main() {
    int A[] = {3, 5, 7, 10, 15, 6, 9, 10};
    create(A, 8);
    printf("Sum is: %d", rSum(first));
    return 0;
}

