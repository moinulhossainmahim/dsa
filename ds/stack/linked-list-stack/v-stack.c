#include <stdio.h>
#include <stdlib.h>

struct stack {
  int data;
  struct stack *next;
};

typedef struct stack Node;
Node *top = NULL;

void push() {
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL) {
    printf("Stack overflow\n");
    return;
  }
  printf("Enter data of new stack element: ");
  scanf("%d", &temp->data);
  temp->next = top;
  top = temp;
  printf("Added new element\n");
}

void display() {
  Node *t = top;
  while (t != NULL) {
    printf("%d ", t->data);
    t = t->next;
  }
}

void pop() {
  Node *temp = top;
  if (temp == NULL) {
    printf("Stack underflow\n");
  } else {
    top = top->next;
    free(temp);
    printf("Element popped\n");
  }
}

int count() {
  Node *t = top;
  int count = 0;
  while (t != NULL) {
    count++;
    t = t->next;
  }
  return count;
}

int menu() {
  int option;
  printf("1.Push()\n");
  printf("2.Pop()\n");
  printf("3.Display()\n");
  printf("4.Count()\n");
  printf("5.exit()\n");
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
      printf("Number of elements in the stack is: %d\n", count());
      break;
    case 5:
      exit(0);
      break;
    }
  }
}
