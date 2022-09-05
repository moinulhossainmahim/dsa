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

const int mx = 2e5 + 123;
vi adj[mx];
bool vis[mx];
int cnt = 0, cnt1 = 0;
bool isNode[mx];

void dfs(int u, int clr) {
  vis[u] = 1;
  if (clr == 1)
    cnt1++;
  cnt++;

  int temp;
  if (clr == 1)
    temp = 2;
  else
    temp = 1;

  for (auto v : adj[u]) {
    if (!vis[v]) {
      dfs(v, temp);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    int m;
    cin >> m;
    for (int i = 0; i <= m; i++) {
      adj[i].clear();
      vis[i] = 0;
      isNode[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      isNode[v] = 1;
      isNode[u] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      if (isNode[i] && vis[i] == 0) {
        cnt = cnt1 = 0;
        dfs(i, 1);
        ans += max(cnt1, cnt - cnt1);
      }
    }
    cout << "Case " << tc << ": " << ans << endl;
  }
}
