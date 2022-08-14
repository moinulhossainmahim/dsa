#include<stdio.h>

void swap(int *p1, int *p2) {
  int temp=*p1;
  *p1=*p2;
  *p2=temp;
}

void selectionSort(int A[], int n) {
  int i,j,k;
  for(i=0; i<n-1; i++) {
    for(j=k=i; j<n; j++) {
      if(A[j]<A[k])k=j;
    }
    swap(&A[i], &A[k]);
  }
}

int main() {
  int A[] = {1, 10, 6, 5, 3, 12, 2};
  int n=7;
  selectionSort(A, n);
  for(int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
  return 0;
}

