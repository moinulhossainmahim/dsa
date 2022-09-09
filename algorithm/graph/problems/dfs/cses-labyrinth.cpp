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
int dist[mx][mx];
int r, col;
vector<pair<int, int>> d;

vector<pair<int, int>> moves = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

void bfs(int x, int y) {
  dist[x][y] = 0;
  queue<pair<int, int>> q;
  q.push({x, y});

  while (!q.empty()) {
    int xs = q.front().first;
    int ys = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x1 = xs + dx[i];
      int y1 = ys + dy[i];
      if (x1 >= 1 && x1 <= r && y1 >= 1 && y1 <= col && dist[x1][y1] == -1 &&
          adj[x1][y1] != '#') {
        dist[x1][y1] = dist[xs][ys] + 1;
        q.push({x1, y1});
        if (adj[x1][y1] == 'B') {
          return;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  int tx, ty;
  cin >> r >> col;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= col; j++) {
      cin >> adj[i][j];
      if (adj[i][j] == 'A') {
        x = i;
        y = j;
      } else if (adj[i][j] == 'B') {
        tx = i;
        ty = j;
      }
    }
  }
  memset(dist, -1, sizeof(dist));
  bfs(x, y);
  if (dist[tx][ty] == -1)
    return cout << "NO\n", 0;

  cout << "YES\n" << dist[tx][ty] << endl;
  for (auto h : d)
    cout << h;
  cout << endl;
}
