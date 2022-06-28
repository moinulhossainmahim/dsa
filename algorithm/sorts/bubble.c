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
