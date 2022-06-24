#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

typedef struct TreeNode node;
node *root = NULL;

// Iterative insert
void Insert(int key) {
  node *tail,*newNode,*t=root;
  if(root==NULL) {
    newNode=(node *)malloc(sizeof(node));
    newNode->data=key;
    newNode->lchild=newNode->rchild=NULL;
    root=newNode;
    return;
  }
  while(t!=NULL) {
    tail=t;
    if(t->data==key)return;
    if(key<t->data) {
      t=t->lchild;
    }
    else {
      t=t->rchild;
    }
  }
  newNode=(node *)malloc(sizeof(node));
  newNode->data=key;
  newNode->lchild=newNode->rchild=NULL;
  if(key<tail->data)tail->lchild=newNode;
  else tail->rchild=newNode;
}

//Recursive insert
node * recursiveInsert(node *t, int key) {
  node *newNode;
  if(t==NULL) {
    newNode=(node *)malloc(sizeof(node));
    newNode->data=key;
    newNode->lchild=newNode->rchild=NULL;
    return newNode;
  }
  if(key<t->data) {
    t->lchild=recursiveInsert(t->lchild, key);
  } else if(key>t->data) {
    t->rchild=recursiveInsert(t->rchild, key);
  }
  return t;
}
 
void inorder(node *p) {
  if(p) {
    inorder(p->lchild);
    printf("%d ", p->data);
    inorder(p->rchild);
  }
}

int height(node *p) {
  int x,y;
  if(p==NULL)return 0;
  x=height(p->lchild);
  y=height(p->rchild);
  return x>y?x+1:y+1;
}

node * inorderPredecessor(node *p) {
  while(p && p->rchild!=NULL) {
    p=p->rchild;
  }
  return p;
}

node * inorderSuccessor(node *p) {
  while(p && p->lchild!=NULL) {
    p=p->lchild;
  }
  return p;
}

node * delete(node *p, int key) {
  node *q;
  if(p==NULL) {
    return NULL;
  }
  if(!p->lchild && !p->rchild) {
    if(p==root)
      root=NULL;
    free(p);
    return NULL;
  }
  if(key<p->data) {
    p->lchild=delete(p->lchild, key);
  }
  else if(key>p->data) {
    p->rchild=delete(p->rchild, key);
  }
  else {
    if(height(p->lchild)>height(p->rchild)) {
      q=inorderPredecessor(p->lchild);
      p->data=q->data;
      p->lchild=delete(p->lchild, q->data);
    }
    else {
      q=inorderSuccessor(p->rchild);
      p->data=q->data;
      p->rchild=delete(p->rchild, q->data);
    }
  }
  return p;
}

// Recursive search
node * searchNode(node *t, int key) {
  if(t==NULL)return NULL;
  if(t->data==key)return t;
  else if(key<t->data) searchNode(t->lchild, key);
  else searchNode(t->rchild, key);
}

// Iterative insert
node * IsearchNode(int key) {
  node *temp=root;
  while(temp) {
    if(temp->data==key)return temp;
    if(key<temp->data)temp=temp->lchild;
    else temp=temp->rchild;
  }
  return NULL;
}

int main() {
  node *temp;
  root=recursiveInsert(root,50);
  recursiveInsert(root, 10);
  recursiveInsert(root, 40);
  recursiveInsert(root, 20);
  recursiveInsert(root, 30);
  delete(root, 50);
  inorder(root);
  printf("\n");
  temp=IsearchNode(15);
  if(temp) {
    printf("Element %d is found\n", temp->data);
  } else {
    printf("Element is not found");
  }
  return 0;
}
