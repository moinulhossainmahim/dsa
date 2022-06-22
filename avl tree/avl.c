#include<stdio.h>
#include<stdlib.h>

struct Node {
  struct Node *lchild;
  int data;
  int height;
  struct Node *rchild;
};

typedef struct Node node;
node *root = NULL;

int nodeHeight(node *t) {
  int lh,rh;
  lh=t && t->lchild?t->lchild->height:0;
  rh=t && t->rchild?t->rchild->height:0;
  return lh>rh?lh+1:rh+1;
}

int balanceFactor(node *t) {
  int lh,rh;
  lh=t && t->lchild?t->lchild->height:0;
  rh=t && t->rchild?t->rchild->height:0;

  return lh-rh;
}

node * llRotation(node *t) {
  node *tl=t->lchild;
  node *tlr=tl->rchild;

  tl->rchild=t;
  t->lchild=tlr;
  tl->height=nodeHeight(tl);
  t->height=nodeHeight(t);

  if(root==t) {
    root=tl;
  }
  return tl;
}

node *lrRotation(node *t) {
  node *tl=t->lchild;
  node *tlr=tl->rchild;

  tl->rchild=tlr->lchild;
  t->lchild=tlr->rchild;
  tlr->rchild=t;
  tlr->lchild=tl;
  tl->height=nodeHeight(tl);
  t->height=nodeHeight(t);
  tlr->height=nodeHeight(tlr);
  if(root==t) {
    root=tlr;
  } 
  return tlr;

}

node *rrRotation(node *t) {
  return NULL;
}

node *rlRotation(node *t) {
  return NULL;
}

node * recursiveInsert(node *t, int key) {
  node *newNode;
  if(t==NULL) {
    newNode=(node *)malloc(sizeof(node));
    newNode->data=key;
    newNode->height=1;
    newNode->lchild=newNode->rchild=NULL;
    return newNode;
  }
  if(key<t->data) {
    t->lchild=recursiveInsert(t->lchild, key);
  } else if(key>t->data) {
    t->rchild=recursiveInsert(t->rchild, key);
  }
  t->height=nodeHeight(t);
  if(balanceFactor(t)==2 && balanceFactor(t->lchild)==1)
    return llRotation(t);
  else if(balanceFactor(t)==2 && balanceFactor(t->lchild)==-1)
    return lrRotation(t);
  else if(balanceFactor(t)==-2 && balanceFactor(t->lchild)==-1)
    return rrRotation(t);
  if(balanceFactor(t)==-2 && balanceFactor(t->lchild)==1)
    rlRotation(t);
  return t;
}

int main() {
  root=recursiveInsert(root, 50);
  recursiveInsert(root, 10);
  recursiveInsert(root, 20);
  return 0;
}
