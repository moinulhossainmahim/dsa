#include<stdio.h>

void swap(int *p1, int *p2) {
  int temp=*p1;
  *p1=*p2;
  *p2=temp;
}

void BubbleSort(int A[], int n) {
  int i,j,flag;
  for(i=0; i<n-1; i++) {
    flag=0;
    for(j=0; j<n-1-i; j++) {
      if(A[j]>A[j+1]) {
        swap(&A[j], &A[j+1]);
        flag=1;
      }
    }
    if(flag==0)break;
  }
}

int main() {
  int A[]={3,7,9,10,6,5,12,4,11,2}, n=10;
  BubbleSort(A, n);
  for(int i=0; i<n; i++) {
    printf("%d ", A[i]);
  }
  printf("\n");
  return 0;
}

// How it works
// 3, 7, 9, 10, 6, 5, 12, 4, 11, 2 - initially
// 3, 7, 9, 6, 5, 10, 4, 11, 2, 12
// 3, 7, 6, 5, 9, 4, 10, 2, 11, 12
// 3, 6, 5, 7, 4, 9, 2, 10, 11, 12
// 3, 5, 6, 4, 7, 2, 9, 10, 11, 12
// 3, 5, 4, 6, 2, 7, 9, 10, 11, 12
// 3, 4, 5, 2, 6, 7, 9, 10, 11, 12
// 3, 4, 2, 5, 6, 7, 9, 10, 11, 12
// 3, 2, 4, 5, 6, 7, 8, 10, 11, 12
// 2, 3, 4, 5, 6, 7, 8, 10, 11, 12

