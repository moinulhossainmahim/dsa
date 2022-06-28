#include<stdio.h>

void insertionSort(int A[], int n) {
  int i,x,j;
  for(i=1; i<n; i++) {
    j=i-1;
    x=A[i];
    while(j>-1 && A[j]>x) {
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=x;
  }
}

int main() {
  int A[]={3,10,4,5,7,6,8,12,20,15}, n=10;
  insertionSort(A, n);
  for(int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}
