#include<bits/stdc++.h>

using namespace std;

const int mx=1000;

vector<pair<int, int>> adj[mx];

int main() {
  int n,e;
  cin >> n >> e;

  for(int i=1; i<=e; i++) {
    int u,v,w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for(int i=1; i<=n; i++) {
    cout << "Adjacent list of  " << i << ": ";
    for(auto u : adj[i]) {
      cout << "Node: "  << u.first << " And cost : " << u.second << " ";
    }
    cout << endl;
  }
  return 0;
}
