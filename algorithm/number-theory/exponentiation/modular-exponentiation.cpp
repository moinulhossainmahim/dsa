#include <bits/stdc++.h>

using namespace std;

int modularExpo(int x, int n, int m) {
  if (n == 0)
    return 1;

  long long ans = modularExpo(x, n / 2, m);
  ans = (ans * ans) % m;

  return (n % 2 != 0) ? (ans * x) % m : ans;
}

int main() {
  int a, b, m;
  cin >> a >> b >> m;
  int ans = modularExpo(a, b, m);
  cout << ans << endl;
}
