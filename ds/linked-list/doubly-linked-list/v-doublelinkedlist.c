#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
};

typedef struct Node node;

node *start=NULL;

node * createNode() {
  node *newNode;
  newNode=(node *)malloc(sizeof(node));
  printf("Enter data of new node: ");
  scanf("%d", &newNode->data);
  newNode->prev=newNode->next=NULL;
  return newNode;
}

void createLinkedList(int n) {
  node *temp,*newNode;
  int i;
  for(i=0; i<n; i++) {
    newNode=createNode();
    if(start==NULL) {
      start=newNode;
    } else {
      temp=start;
      while(temp->next) {
        temp=temp->next;
      }
      temp->next=newNode;
      newNode->prev=temp;
    }
  }
}

int countNode() {
  node *temp=start;
  int len=0;
  while(temp) {
    len++;
    temp=temp->next;
  }
  return len;
}

void insertStart() {
  node *newNode;
  newNode=createNode();
  if(!start) {
    start=newNode;
  }
  else {
    newNode->next=start;
    start->prev=newNode;
    start=newNode;
  }
}

void insertEnd() {
  node *newNode, *temp=start;
  newNode=createNode();
  while(temp->next) {
    temp=temp->next;
  }
  temp->next=newNode;
  newNode->prev=temp;
}

void insertInterMediate(int pos) {
  node *temp=start,*newNode,*prev=NULL;
  int i;
  if(pos>1 && pos<countNode()) {
    newNode=createNode();
    for(i=1; i<pos; i++) {
      prev=temp;
      temp=temp->next;
    }
    prev->next=newNode;
    newNode->prev=temp;
    temp->prev=newNode;
    newNode->next=temp;
  }
  else {
    printf("position is invalid\n");
  }
}

void deleteBegin() {
  node *temp=start;
  if(!temp) {
    printf("There is no node to delete\n");
  }
  temp->next->prev=NULL;
  start=temp->next;
  free(temp);
}

void deleteEnd() {
  node *temp=start,*prev=NULL;
  if(!temp)printf("There is no node to delete\n");
  while(temp->next) {
    prev=temp;
    temp=temp->next;
  }
  prev->next=NULL;
  free(temp);
}

void deleteInterMediate(int pos) {
  node *temp=start,*prev=NULL;
  int i;
  if(!temp)printf("There is no node in this list\n");
  else if(pos>1 && pos<countNode()) {
    for(i=1; i<pos; i++) {
      prev=temp;
      temp=temp->next;
    }
    prev->next=temp->next;
    temp->next->prev=prev;
    free(temp);
  }
  else {
    printf("Put valid position\n");
  }
}

void display() {
  node *temp=start;
  while(temp) {
    printf("%d ", temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void reverseDisplay(node *temp) {
  if(temp) {
    reverseDisplay(temp->next);
    printf("%d ", temp->data);
  }
}

int main() {
  createLinkedList(5);
  deleteInterMediate(4);
  display();
  return 0;
}
