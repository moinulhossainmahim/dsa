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

const int mx = 1e4;
vi adj[mx];
int dist[mx];

void bfs(int s) {
  dist[s] = 0;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    adj[i].clear();
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dist, -1, sizeof(dist));
  bfs(1);
  int q;
  cin >> q;
  int ans = 100000, node = 100000;
  for (int i = 1; i <= q; i++) {
    int u;
    cin >> u;
    if (dist[u] < ans) {
      ans = dist[u];
      node = u;
    } else if (dist[u] == ans) {
      ans = dist[u];
      node = min(u, node);
    }
  }
  cout << node << endl;
}
