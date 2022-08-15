#include <stdio.h>
#include <stdlib.h>
#define MAX 6
int Q[MAX];
int front = 0;
int rear = 0;

void push() {
  if (rear == MAX)
    printf("Queue is full\n");
  else {
    int data;
    printf("Enter data of new queue's element: ");
    scanf("%d", &data);
    Q[rear++] = data;
    printf("Data inserted\n");
  }
}

void pop() {
  if (front == rear) {
    printf("Queue is empty\n");
  } else {
    printf("Popped element is: %d\n", Q[front++]);
  }
}

void display() {
  int i = front;
  while (i < rear) {
    printf("%d ", Q[i++]);
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
