#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *prev;
  int data;
  struct Node *next;
};

typedef struct Node node;
node *start=NULL;

node *createNode() {
  node *newNode;
  newNode=(node *)malloc(sizeof(node));
  printf("Enter new node's data: ");
  scanf("%d", &newNode->data);
  newNode->prev=newNode->next=NULL;
  return newNode;
}

void createList(int n) {
  node *newNode;
  int i;
  for(i=0; i<n; i++) {
    newNode=createNode();
    if(start==NULL) {
      start=newNode;
      newNode->prev=newNode->next=start;
    }
    else {
      newNode->prev=start->prev;
      newNode->next=start;
      start->prev->next=newNode;
      start->prev=newNode;
    }
  }
}

void display() {
  node *temp=start;
  if(temp==NULL)printf("There is no node in the list\n");
  else {
    do {
      printf("%d ", temp->data);
      temp=temp->next;
    }
    while(temp!=start);
    printf("\n");
  }
}

void rightToLeftDisplay() {
  node *temp=start;
  do {
    temp=temp->prev;
    printf("%d ", temp->data);
  }while(temp!=start);
  printf("\n");
}

void findLastNode() {
  node *temp=start;
  while(temp->next!=start) {
    temp=temp->next;
  }
  printf("%d\n", temp->data);
}

int countNode() {
  node *temp;
  int len=0;
  temp=start;
  do {
    len++;
    temp=temp->next;
  }while(temp!=start);
  return len;
}

int main() {
  createList(5);
  display();
  rightToLeftDisplay();
  findLastNode();
  printf("Length of the list: %d\n", countNode());
  return 0;
}
