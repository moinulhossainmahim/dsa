#include<bits/stdc++.h>

using namespace std;

const int mx=1000;

vector<int> adj[mx];

int main() {
  int n,m;
  cin >> n >> m;
  for(int i=1; i<=m; i++) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1; i<=n; i++) {
    for(auto u : adj[i]) cout << u << " ";
    cout << endl;
  }
  return 0;
}
