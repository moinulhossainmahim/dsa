#include <bits/stdc++.h>

using namespace std;

vector<int> primeFactor(int n) {
  vector<int> p;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      p.push_back(i);
      n /= i;
    }
  }
  if (n > 1)
    p.push_back(n);
  return p;
}

int main() {
  int n;
  cin >> n;
  vector<int> ans = primeFactor(n);

  for (auto u : ans)
    cout << u << " ";
  cout << endl;
}
