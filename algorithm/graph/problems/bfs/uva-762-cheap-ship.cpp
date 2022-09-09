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

const int mx = 1000;
map<string, vector<string>> adj;
map<string, int> dist;
map<string, string> par;

void bfs(string s) {
  dist.clear();
  queue<string> q;
  q.push(s);
  dist[s] = 1;

  while (!q.empty()) {
    string u = q.front();
    q.pop();

    for (auto v : adj[u]) {
      if (dist[v] == 0) {
        dist[v] = dist[u] + 1;
        par[v] = u;
        q.push(v);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  bool yes = 0;
  while (cin >> n) {
    adj.clear();
    par.clear();
    if (yes)
      cout << endl;
    yes = 1;
    for (int i = 1; i <= n; i++) {
      string s1, s2;
      cin >> s1 >> s2;
      adj[s1].push_back(s2);
      adj[s2].push_back(s1);
    }
    string s, t;
    cin >> s >> t;
    bfs(s);
    if (dist[t] == 0) {
      cout << "No route" << endl;
      continue;
    }
    string temp = t;
    vector<pair<string, string>> ans;
    while (!par[temp].empty()) {
      ans.push_back({par[temp], temp});
      temp = par[temp];
    }
    reverse(ans.begin(), ans.end());
    for (auto u : ans) {
      cout << u.first << " " << u.second << endl;
    }
  }
}
