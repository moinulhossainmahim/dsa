#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

#ifndef Stack_h
#define Stack_h


struct Stack
{
    int size;
    int top;
    struct TreeNode **s;
};

void createStack(struct Stack *st, int n)
{
    st->size=n;
    st->top=-1;
    st->s=(struct TreeNode **)malloc(st->size * sizeof(struct TreeNode *));
}

void push(struct Stack *st, struct TreeNode *x)
{
    if(st->top==st->size-1)
        printf("Stack Overflow");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

struct TreeNode* pop(struct Stack *st)
{
    struct TreeNode *x=NULL;
    if(st->top==-1)
        printf("Stack underflow");
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

int isEmptyStack(struct Stack st)
{
    if(st.top==-1)return 1;
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top==st.size-1;
}

#endif
