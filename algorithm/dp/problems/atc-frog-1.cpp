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

const ll infLL = 90000000000000;

const int mx = 1e5 + 123;
int h[mx];
int n;
int dp[mx];

int solve(int i) {
  if (i == n)
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int ret1 = INT_MAX, ret2 = INT_MAX;

  if (i + 1 <= n)
    ret1 = abs(h[i] - h[i + 1]) + solve(i + 1);
  if (i + 2 <= n)
    ret2 = abs(h[i] - h[i + 2]) + solve(i + 2);
  dp[i] = min(ret1, ret2);
  return dp[i];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++)
    cin >> h[i];
  cout << solve(1) << endl;
}
