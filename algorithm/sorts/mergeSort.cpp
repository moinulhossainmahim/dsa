#include<iostream>

using namespace std;

void merge(int a[], int l, int mid, int h) {
	int i=l, j=mid+1, k=l;
	int temp[h+1];

	while(i<=mid && j<=h) {
		if(a[i] < a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}

	for(; i<=mid; i++) temp[k++] = a[i];
	for(; j<=h; j++) temp[k++] = a[j];

	for(int i=l; i<=h; i++) a[i]=temp[i];
}

void mergeSort(int a[], int n) {
	int i;
	for(i=2; i<=n; i=i*2) {
		for(int j=0; j+i-1<=n; j=j+i) {
			int l,mid,h;
			l = j;
			h = j+i-1;
			mid = (l+h)/2;
			merge(a, l, mid, h);
		}
	}
	if(i / 2 < n) merge(a, 0, i/2-1, n-1);
}

int main() {
	int nums[] = {2, 4, 1, 5, 3, 8, 7, 0};
	mergeSort(nums, 8);
	for(auto u : nums) cout << u << " ";
	cout << endl;
}
