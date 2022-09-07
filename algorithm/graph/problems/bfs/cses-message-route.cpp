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
int dist[mx];
int parent[mx];

void bfs(int s) {
  dist[s] = 1;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        parent[v] = u;
        q.push(v);
      }
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
  memset(dist, -1, sizeof(dist));
  bfs(1);
  vi ans;
  int u = n;
  if (dist[n] == -1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  while (u != 1) {
    ans.push_back(u);
    u = parent[u];
  }
  ans.push_back(u);
  reverse(ans.begin(), ans.end());
  cout << dist[n] << endl;
  for (auto u : ans)
    cout << u << " ";
  cout << endl;
}
