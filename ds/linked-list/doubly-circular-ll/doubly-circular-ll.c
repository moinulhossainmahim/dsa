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

void insertStart() {
  node *newNode;
  newNode=createNode();
  if(start==NULL) {
    start=newNode;
    newNode->prev=newNode->next=NULL;
  } else {
    newNode->prev=start->prev;
    newNode->next=start;
    start->prev->next=newNode;
    start->prev=newNode;
    start=newNode;
  }
}

void insertEnd() {
  node *newNode;
  newNode=createNode();
  if(start==NULL) {
    start=newNode;
    newNode->prev=newNode->next=NULL;
  }
  else {
    newNode->prev=start->prev;
    newNode->next=start;
    start->prev->next=newNode;
    start->prev=newNode;
  }
}

void insertMid(int index) {
  node *temp,*newNode;
  int i;
  temp=start;
  if(index>1 && index<countNode()) {
    newNode=createNode();
    for(i=1; i<index-1; i++) {
      temp=temp->next;
    }
    newNode->prev=temp;
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
  } else {
    printf("Position %d is not a valid position\n", index);
  }
}

void deleteStart() {
  node *temp;
  if(start==NULL)printf("There is no node to delete\n");
  else {
    if(countNode()==1) {
      free(start);
      start=NULL;
    } else {
      temp=start;
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      start=start->next;
      free(temp);
    }
  }
}

void deleteEnd() {
  node *temp;
  if(start==NULL)printf("There is no node to delete\n");
  else {
    if(countNode()==1) {
      free(start);
      start=NULL;
    } else {
      temp=start->prev;
      temp->prev->next=start;
      start->prev=temp->prev;
      free(temp);
    }
    printf("Node has been deleted\n");
  }
}

void deleteMid(int index) {
  node *temp;
  int i;
  temp=start;
  if(index>1 && index<countNode()) {
    for(i=1; i<index; i++) {
      temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    printf("Node in position %d has been deleted\n", index);
  } else {
    printf("Position %d is not a valid position\n", index);
  }
}

int main() {
  createList(5);
  rightToLeftDisplay();
  printf("Length of the list: %d\n", countNode());
  return 0;
}
