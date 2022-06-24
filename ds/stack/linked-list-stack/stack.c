#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
    char data;
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

void push(char x)
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

char pop()
{
    struct Node *p;
    char x='t';
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


int isBalance(char *exp) {
    int i;
    for(i=0; exp[i]!='\0'; i++) {
        if(exp[i]=='(') {
            push(exp[i]);
        }
        else if(exp[i]==')') {
            if(top==NULL) return 0;
            pop();
        }
    }
    if(top==NULL) return 1;
    return 0;
}

int isBalanceTwo(char *exp) {
    int i,a1,a2;
    char x;
    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if(top==NULL) return 0;
            x=pop();
            a1=x;
            a2=exp[i];
            printf("%d\n%d\n", a2-1, a2-2);
            if((a1!=(a2-1)) || (a1!=(a2-2))) return 0;
        }
    }
    if(top==NULL) return 1;
    else return 0;
}
/* 
int pre(char x) {
    if(x=='+' || x=='-') {
        return 1;
    } else if(x=='*' || x='/') {
        return 2;
    } else return 0;
}

int isOperand(char x) {
    if(x=='+' || x=='-' || x=='*' || x='/') {
        return 0;
    } else {
        return 1;
    }
} */

char * infixToPostfix(char *infix) {
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc(sizeof(char)*(len+1));
    int i=0,j=0;
    while(infix[i]!='\0') {
        if(isOperand(infix[i])) {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(pre(infix[i])>pre(top->data)) {
                push(infix[i++]);
            } else {
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL) {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int main()
{
    char *infix="a+b*c";
    char *postfix;
    return 0;
}
