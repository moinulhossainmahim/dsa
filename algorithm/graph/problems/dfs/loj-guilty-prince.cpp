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

const int mx = 25;
char adj[mx][mx];
bool vis[mx][mx];
int cnt, col, r;

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

void dfs(int x, int y) {
  vis[x][y] = 1;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int x1 = x + dx[i];
    int y1 = y + dy[i];

    if (x1 >= 1 && x1 <= r && y1 >= 1 && y1 <= col && vis[x1][y1] == 0 &&
        adj[x1][y1] == '.') {
      dfs(x1, y1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    cin >> col >> r;
    int x, y;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= col; j++) {
        cin >> adj[i][j];
        if (adj[i][j] == '@') {
          x = i;
          y = j;
        }
      }
    }
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    dfs(x, y);
    cout << "Case " << tc << ": " << cnt << endl;
  }
}
