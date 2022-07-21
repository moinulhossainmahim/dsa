#include<bits/stdc++.h>

using namespace std;

const int mx=1000;

vector<int> adj[mx];

int main() {
  int n,e;
  cin >> n >> e;

  for(int i=1; i<=e; i++) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i=1; i<=n; i++) {
    cout << "Adjacent list of node " << i << ": ";
    for(auto u : adj[i]) {
      cout << u << " ";
    }
    cout << endl;
  }
  return 0;
}
