#include <stdio.h>
#include <stdlib.h>
#define MAX 6
int Stack[MAX];
int top = 0;

void push() {
  if (top == MAX)
    printf("Stack overflow\n");
  else {
    int data;
    printf("Enter stack new data: ");
    scanf("%d", &data);
    Stack[top++] = data;
    printf("New data has been pushed.\n");
  }
}

void pop() {
  if (top == 0)
    printf("Stack empty\n");
  else {
    printf("Popped element is: %d\n", Stack[--top]);
  }
}

void display() {
  if (top == 0) {
    printf("No element to show\n");
  } else {
    printf("Elements is the stack is: \n");
    for (int i = top - 1; i >= 0; i--) {
      printf("%d ", Stack[i]);
    }
  }
}

int menu() {
  int option;
  printf("1.Push()\n");
  printf("2.Pop()\n");
  printf("3.Display()\n");
  printf("4.exit()\n");
  printf("Enter operation: ");
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
