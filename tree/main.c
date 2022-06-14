#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

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

int main() {
  createTree();
  preorder(root);
  printf("\n");
  postorder(root);
  return 0;
}

