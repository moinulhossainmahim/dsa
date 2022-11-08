#include<iostream>

using namespace std;

void selectionSort(int nums[], int n) {
	for(int i=0; i<n-1; i++) {
		int small=i;
		for(int j=i+1; j<n; j++) {
			if(nums[j] < nums[small]) small=j;
		}
		if(small != i) {
			swap(nums[small], nums[i]);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int nums[n];
	for(int i=0; i<n; i++) cin >> nums[i];
	selectionSort(nums, n);
	
	for(auto u : nums) cout << u << " ";
	cout << '\n';
}

// 5 4 9 2 8 3 1 7
