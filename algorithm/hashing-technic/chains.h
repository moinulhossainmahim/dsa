#include<stdio.h>
#include<stdlib.h>

#ifndef Chain_h
#define Chain_h

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void sortedInsert(struct Node **H, int x)
{
    struct Node *t,*q=NULL,*p=*H;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(*H==NULL)
    {
        *H=t;
    }
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==*H)
        {
            t->next=*H;
            *H=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

struct Node* rSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return rSearch(p->next, key);
}

#endif