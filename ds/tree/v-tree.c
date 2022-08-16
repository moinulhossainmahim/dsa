#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Tree {
  struct Tree *lchild;
  struct Tree *rchild;
  int data;
};

typedef struct Tree Node;

Node *getnode() {
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  printf("Enter new node's data: ");
  scanf("%d", &temp->data);
  temp->lchild = NULL;
  temp->rchild = NULL;
  return temp;
}

void createBinaryTree(Node *root) {
  char option;
  if (root != NULL) {
    printf("\nNode %d has left child?[Y/N] ", root->data);
    scanf(" %c", &option);
    if (option == 'Y' || option == 'y') {
      root->lchild = getnode();
      createBinaryTree(root->lchild);
    } else {
      root->lchild = NULL;
      createBinaryTree(root->lchild);
    }

    printf("\n Node %d has right child?[Y/N] ", root->data);
    scanf(" %c", &option);

    if (option == 'Y' || option == 'y') {
      root->rchild = getnode();
      createBinaryTree(root->rchild);
    } else {
      root->rchild = NULL;
      createBinaryTree(root->rchild);
    }
  }
}

void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
  }
}

void preorder(Node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}

void postorder(Node *root) {
  if (root != NULL) {
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
  }
}

void print_leaf_node(Node *root) {
  if (root != NULL) {
    if (root->lchild == NULL && root->rchild == NULL) {
      printf("%d ", root->data);
    }
    print_leaf_node(root->lchild);
    print_leaf_node(root->rchild);
  }
}

int menu() {
  int option;
  printf("1.Create Binary Tree()\n");
  printf("2.Inorder()\n");
  printf("3.preorder()\n");
  printf("4.postorder()\n");
  printf("5.Print Leaf Node()\n");
  printf("6.exit()\n");
  printf("Enter operation number: ");
  scanf("%d", &option);
  return option;
}

int main() {
  int option;
  Node *root = NULL;

  while (1) {
    printf("\n");
    option = menu();
    switch (option) {
    case 1:
      if (root != NULL)
        printf("Tree is already created\n");
      else {
        root = getnode();
        createBinaryTree(root);
      }
      break;
    case 2:
      inorder(root);
      break;
    case 3:
      preorder(root);
      break;
    case 4:
      postorder(root);
      break;
    case 5:
      print_leaf_node(root);
      break;
    case 6:
      exit(0);
    }
  }
}
