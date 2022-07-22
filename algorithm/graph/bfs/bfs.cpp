#include<bits/stdc++.h>

using namespace std;

const int mx=1000;
bool vis[100];
int dis[100];
int parent[100];

vector<int> adj[mx];

void bfs(int u) {
  queue<int> q;
  dis[u]=0;
  vis[u]=1;
  q.push(u);
  while(!q.empty()) {
    int n;
    n=q.front();
    cout << n << " ";
    q.pop();
    for(auto v : adj[n]) {
      if(vis[v]==0) {
        parent[v]=n;
        vis[v]=1;
        dis[v] = dis[n]+1;
        q.push(v);
      }
    }
  }
  cout << endl;
  cout << parent[10] << endl;
}

int main() {
  memset(parent, -1, sizeof(parent));
  int n,e;
  cin >> n >> e;
  for(int i=1; i<=e; i++) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bfs(1);
  return 0;
}
