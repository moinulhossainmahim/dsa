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

const int mx = 1e5 + 123;
vi adj[mx];
bool vis[mx];

void dfs(int u) {
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (vis[v] == 0) {
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vi ans;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      ans.push_back(i);
      dfs(i);
      cnt++;
    }
  }
  cout << cnt - 1 << endl;
  if (cnt > 1) {
    for (int i = 0; i < cnt - 1; i++) {
      cout << ans[i] << " " << ans[i + 1] << endl;
    }
  }
}
