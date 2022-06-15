#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct TreeNode *root=NULL;

void createTree() {
  struct TreeNode *t, *p;
  int x;
  struct Queue q;
  create(&q, 100);

  printf("Enter root value: ");
  scanf("%d", &x);
  root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->data=x;
  root->lChild=root->rChild=NULL;
  enqueue(&q, root);

  while(!isEmpty(q)) {
    p=dequeue(&q);
    printf("Enter left child of %d: ", p->data);
    scanf("%d", &x);

    if(x!=-1) {
      t=(struct TreeNode *)malloc(sizeof(struct TreeNode));
      t->data=x;
      t->lChild=t->rChild=NULL;
      p->lChild=t;
      enqueue(&q, t);
    }

    printf("Enter right child of %d: ", p->data);
    scanf("%d", &x);
    if(x!=-1) {
      t=(struct TreeNode *)malloc(sizeof(struct TreeNode));
      t->data=x;
      t->lChild=t->rChild=NULL;
      p->rChild=t;
      enqueue(&q, t);
    }
  }
}

//Recursive pre/in/post order
void preorder(struct TreeNode *p) {
  if(p) {
    printf("%d ", p->data);
    preorder(p->lChild);
    preorder(p->rChild);
  }
}

void inorder(struct TreeNode *p) {
  if(p) {
    preorder(p->lChild);
    printf("%d ", p->data);
    preorder(p->rChild);
  }
}

void postorder(struct TreeNode *p) {
  if(p) {
    postorder(p->lChild);
    postorder(p->rChild);
    printf("%d ", p->data);
  }
}

// Iterative pre/in/post order
void IpreOrder(struct TreeNode *p) {
  struct Stack st;
  createStack(&st, 100);
  while(p || !isEmptyStack(st)) {
    if(p!=NULL) {
      printf("%d ", p->data);
      push(&st, p);
      p=p->lChild;
    }
    else {
      p=pop(&st);
      p=p->rChild;
    }
  }
}

void IInorder(struct TreeNode *p) {
  struct Stack st;
  createStack(&st, 100);
  while(p || !isEmptyStack(st)) {
    if(p!=NULL) {
      push(&st, p);
      p=p->lChild;
    }
    else {
      p=pop(&st);
      printf("%d ", p->data);
      p=p->rChild;
    }
  }
}

// Level order traversing
void leverOrderTraversing(struct TreeNode *root) {
  struct Queue q;
  create(&q, 100);
  printf("%d ", root->data);
  enqueue(&q, root);
  while(!isEmpty(q)) {
    root=dequeue(&q);
    if(root->lChild!=NULL) {
      printf("%d ", root->lChild->data);
      enqueue(&q, root->lChild);
    }
    if(root->rChild!=NULL) {
      printf("%d ", root->rChild->data);
      enqueue(&q, root->rChild);
    }
  }
}

int main() {
  createTree();
  leverOrderTraversing(root);
  return 0;
}
