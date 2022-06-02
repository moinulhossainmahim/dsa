#include<stdio.h>
#include<stdlib.h>

struct slinkedlist {
    int data;
    struct slinkedlist *next;
};

typedef struct slinkedlist Node;
Node *start=NULL;

Node* getNode() {
    Node *newNode;
    newNode=(Node *)malloc(sizeof(Node));
    printf("Enter node's data\n");
    scanf("%d", &newNode->data);
    newNode->next=NULL;
    return newNode;
}

void createNodes(int n) {
    int i;
    Node *newNode,*temp;
    for(i=0; i<n; i++) {
        newNode=getNode();
        if(start==NULL) {
            start=newNode;
        } else {
            temp=start;
            while(temp->next!=NULL) temp=temp->next;
            temp->next=newNode;
        }
    }
}

void Display() {
    Node *temp=start;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

void insertBegin() {
    Node *newNode, *temp;
    newNode=getNode();
    if(start==NULL){
        start=newNode;
    } else {
        temp=start;
        start=newNode;
        start->next=temp;
    }
}

void insertEnd() {
    Node *newNode, *temp=start;
    newNode=getNode();
    if(start==NULL) start=newNode;
    else {
        while(temp->next!=NULL)temp=temp->next;
        temp->next=newNode;
    }
}

void insertMid(int index) {
    Node *temp=start, *newNode;
    newNode=getNode();
    int i;
    if(start==NULL) start=newNode;
    else {
        for(i=0; i<index-1; i++) {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

int main() {
    createNodes(3);
    Display();
    insertMid(3);
    Display();
    return 0;
}
