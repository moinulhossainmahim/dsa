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
int r, col, cnt;
vector<char> d;
bool isFind;

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

void dfs(int x, int y) {
  vis[x][y] = 1;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int x1 = x + dx[i];
    int y1 = y + dy[i];
    if (x1 >= 1 && x1 <= r && y1 >= 1 && y1 <= col && vis[x1][y1] == 0 &&
            (adj[x1][y1] == '.') ||
        (adj[x1][y1] == 'B')) {
      if (i == 0)
        d.push_back('U');
      else if (i == 1)
        d.push_back('D');
      else if (i == 2)
        d.push_back('R');
      else if (i == 3)
        d.push_back('L');
      if (adj[x1][y1] == 'B') {
        isFind = 1;
        return;
      }
      dfs(x1, y1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> r >> col;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= col; j++) {
      cin >> adj[i][j];
      if (adj[i][j] == 'A') {
        x = i;
        y = j;
      }
    }
  }
  dfs(x, y);
  if (isFind) {
    cout << "YES" << endl;
    cout << cnt << endl;
    reverse(d.begin(), d.end());
    for (auto u : d)
      cout << u;
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
