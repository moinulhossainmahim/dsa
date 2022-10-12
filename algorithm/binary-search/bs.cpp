#include <iostream>

using namespace std;

int main() {
  int n, target;
  cin >> n >> target;
  int numbers[n];
  for (int i = 0; i < n; i++)
    cin >> numbers[i];
  int l = 0, r = n - 1, mid;

  int ans = -1;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (numbers[mid] == target) {
      ans = mid;
      break;
    } else if (numbers[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  if (ans == -1)
    cout << "NOT FOUND\n";
  else
    cout << "Found at postition " << ans << endl;
}
