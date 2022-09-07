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

const int mx = 212;
vi adj[mx];
int color[mx];

bool isBipartite(int s) {
  memset(color, -1, sizeof(color));
  color[s] = 1;
  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (color[v] == -1) {
        if (color[u] == 1)
          color[v] = 2;
        else
          color[v] = 1;
        q.push(v);
      } else if (color[v] == color[u])
        return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  while (cin >> tt) {
    if (tt == 0)
      break;
    for (int i = 0; i <= tt; i++)
      adj[i].clear();
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (isBipartite(0))
      cout << "BICOLORABLE." << endl;
    else
      cout << "NOT BICOLORABLE." << endl;
  }
}
