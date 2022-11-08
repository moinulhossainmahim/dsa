#include<iostream>

using namespace std;

void binarySearch(int nums[], int n, int target) {
    int ans = -1;
    int l=0, r=n-1, mid;

    while(l<=r) {
        mid = l + (r-l) / 2;
        if(nums[mid] == target) {
            ans = mid;
            break;
        } else if(nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if(ans != -1) {
        cout << "found target at position " << ans + 1 << endl;
    } else {
        cout << "not found\n";
    }
}

int main() {
    int n, target;
    cin >> n >> target;
    int nums[n];

    for(int i=0; i<n; i++) cin >> nums[i];

    binarySearch(nums, n, target);
}

// n = 8, target = 5
// 2, 4, 5, 6, 9, 14, 18, 50
