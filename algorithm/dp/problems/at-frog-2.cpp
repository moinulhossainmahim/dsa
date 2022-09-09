/*
  IN THE NAME OF ALLAH
  Author: Moinul Hossain
  Northern University Bangladesh
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
#define debug(n) cout << (n) << endl;
#define mem(a, b) memset(a, b, sizeof(a));

const int mx = 1e5 + 123;
int h[mx], n, k;
int dp[mx];

int doit(int i) {
  if (i == n)
    return 0;
  if (dp[i] != -1)
    return dp[i];

  int ans = INT_MAX;
  for (int j = 1; j <= k; j++) {
    if (i + j <= n)
      ans = min(abs(h[i] - h[i + j]) + doit(i + j), ans);
  }
  return dp[i] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mem(dp, -1);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> h[i];
  cout << doit(1) << endl;
}
