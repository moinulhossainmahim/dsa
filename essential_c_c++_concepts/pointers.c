#include<stdio.h>
#include<stdlib.h>

int main() {
  int *p;
  int s;
  printf("Enter the size of array: ");
  scanf("%d", &s);
  p = (int *)malloc(sizeof(int) * s);
  int i;
  for(i=0; i<s; i++) {
    scanf("%d", (p+i));
  }
  for(i=0; i<s; i++) {
    printf("%d", p[i]);
  }
  /* int arr[10];
  int i;
  for(i=0; i<10; i++) {
    scanf("%d", &arr[i]);
  }
  for(i=0; i<10; i++) {
    printf("%d ", arr[i]);
  } */
  return 0;
}
