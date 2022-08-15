#include <stdio.h>
#include <stdlib.h>
#define MAX 6
int Q[MAX];
int front = 0;
int rear = 0;
int count = 0;

void push() {
  if (count == MAX) {
    printf("Queue is full\n");
  } else {
    int data;
    printf("Enter queue's new data: ");
    scanf("%d", &data);
    Q[rear] = data;
    count++;
    rear = (rear + 1) % MAX;
    printf("Element enqueued to queue\n");
  }
}

void pop() {
  if (count == 0)
    printf("Queue is empty\n");
  else {
    int x = Q[front];
    count--;
    front = (front + 1) % MAX;
    printf("%d is dequeued from queue\n", x);
  }
}

void display() {
  if (count == 0)
    printf("Queue is empty\n");
  else {
    int j = count;
    for (int i = front; j != 0; j--) {
      printf("%d ", Q[i]);
      i = (i + 1) % MAX;
    }
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
