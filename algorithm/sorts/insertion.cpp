#include<iostream>

using namespace std;

void insertion(int nums[], int n) {
	for(int i=1; i<n; i++) {
		int j=i-1;
		int x=nums[i];
		while(j>-1 && nums[j]>x) {
			nums[j+1] = nums[j];
			j--;
		}
		nums[j+1] = x;
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	insertion(arr, n);
	
	for(auto u : arr) cout << u << " ";
	cout << '\n';
}


// 8 6 9 2 5 4 3
