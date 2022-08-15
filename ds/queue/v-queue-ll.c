#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;
node *front = NULL;
node *rear = NULL;

void push() {
  node *t;
  t = (node *)malloc(sizeof(node));
  if (t == NULL) {
    printf("Queue is full\n");
  } else {
    printf("Enter data of new queue's element: ");
    scanf("%d", &t->data);
    t->next = NULL;
    if (front == NULL) {
      front = rear = t;
    } else {
      rear->next = t;
      rear = t;
    }
    printf("Element pushed\n");
  }
}

void pop() {
  if (front == NULL)
    printf("Queue is empty\n");
  else {
    node *t = front;
    front = front->next;
    printf("Element popped and popped element is: %d\n", t->data);
    free(t);
  }
}

void display() {
  node *t = front;

  if (t == NULL) {
    printf("Queue is empty\n");
    return;
  }

  while (t != NULL) {
    printf("%d ", t->data);
    t = t->next;
  }
}

int menu() {
  int option;
  printf("1.Push()\n");
  printf("2.Pop()\n");
  printf("3.Display()\n");
  printf("4.exit()\n");
  printf("Enter operation number: ");
  scanf("%d", &option);
  return option;
}

int main() {
  int option;

  while (1) {
    printf("\n");
    option = menu();
    switch (option) {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      exit(0);
      break;
    }
  }
}
