#include<stdio.h>
#include "chains.h"

int hashCode(int key) {
  return key%10;
}

void insert(struct Node *H[], int key) {
  int index=hashCode(key);
  sortedInsert(&H[index], key);
}

int main() {
  struct Node *Ht[10];
  for(int i=0; i<10; i++) {
    Ht[i]=NULL;
  }
  insert(Ht, 12);
  insert(Ht, 22);
  insert(Ht, 42);
  return 0;
}
