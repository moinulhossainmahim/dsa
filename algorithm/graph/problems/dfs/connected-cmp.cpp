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
bool vis[mx];
vi adj[mx];

void dfs(int u) {
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (!vis[v])
      dfs(v);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      cnt++;
    }
  }
  cout << cnt << endl;
}
