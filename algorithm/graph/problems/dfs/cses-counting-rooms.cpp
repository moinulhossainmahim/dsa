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

const int mx = 1e3 + 123;
char adj[mx][mx];
bool vis[mx][mx];
int n, m;

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

void dfs(int x, int y) {
  vis[x][y] = 1;

  for (int i = 0; i < 4; i++) {
    int x1 = x + dx[i];
    int y1 = y + dy[i];

    if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && vis[x1][y1] == 0 &&
        adj[x1][y1] == '.') {
      dfs(x1, y1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> adj[i][j];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (adj[i][j] == '.' && vis[i][j] == 0) {
        dfs(i, j);
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
