#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*Head=NULL;

void create(int A[], int n) {
    int i;
    struct Node *t,*last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1; i<n; i++) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct Node *h) {
    do{
        printf("%d ", h->data);
        h=h->next;
    }while(h!=Head);
}

void recursiveDisplay(struct Node *h) {
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        printf("%d ", h->data);
        recursiveDisplay(h->next);
    }
    flag=0;
}

int Length(struct Node *h) {
    int len=0;
    do {
        len++;
        h=h->next;
    } while(h!=Head);
    return len;
}

struct Node * findLastNode(struct Node *p) {
    struct Node *temp;
    temp=Head;
    while(temp->next!=Head) {
        temp=temp->next;
    }
    return temp;
}

void insertNode(struct Node *h, int x, int index){
    struct Node *t;
    int i;

    if(index < 0 || index > Length(h))
        return;

    if(index==0) {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;

        if(Head==NULL) {
            Head=t;
            Head->next=Head;
        } else {
            while(h->next!=Head)h=h->next;
            h->next=t;
            t->next=Head;
            Head=t;
        }
    } else {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        for(i=0; i<index-1; i++)h=h->next;
        t->next=h->next;
        h->next=t;
    }
}

int deleteNode(struct Node *p, int index) {
    struct Node *q=NULL;
    int i,x;
    if(index < 0 || index > Length(p)) {
        return -1;
    }
    if(index==1)
    {
        while(p->next!=Head)p=p->next;
        x=Head->data;
        if(p==Head) {
            free(Head);
            Head=NULL;
        }
        else {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else
    {
        for(i=0; i<index-2; i++)
        {
            p=p->next;
        }
        q=p->next;
        x=q->data;
        p->next=q->next;
        free(q);
    }
    return x;
}

int main() {
    int A[] = {2, 3, 4, 6, 7};
    create(A, 5);
    display(Head);
    struct Node *node = findLastNode(Head);
    printf("\n%d\n", node->data);
    return 0;
}
