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
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()
#define debug(n) cout << (n) << endl;
#define mem(a, b) memset(a, b, sizeof(a))

const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int dx[] = {0, 0, +1, -1, -1 + 1, -1, +1};
int dy[] = {+1, -1, 0, 0, -1, +1, +1, -1};

const int mx = 212;
int r, c;
char adj[mx][mx];
int JaneDist[mx][mx], FireDist[mx][mx];
vii ss;

void bfsFire() {
  mem(FireDist, -1);
  queue<pii> q;
  for (auto u : ss) {
    int x = u.F;
    int y = u.S;
    q.push({x, y});
    FireDist[x][y] = 0;
  }

  while (!q.empty()) {
    int x = q.front().F;
    int y = q.front().S;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x1 = x + dx[i];
      int y1 = y + dy[i];
      if (x1 >= 1 && x1 <= r && y1 >= 1 && y1 <= c && FireDist[x1][y1] == -1 &&
          adj[x1][y1] != '#') {
        FireDist[x1][y1] = FireDist[x][y] + 1;
        q.push({x1, y1});
      }
    }
  }
}

void bfsJane(int x, int y) {
  mem(JaneDist, -1);
  JaneDist[x][y] = 0;
  queue<pii> q;
  q.push({x, y});

  while (!q.empty()) {
    int x = q.front().F;
    int y = q.front().S;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x1 = x + dx[i];
      int y1 = y + dy[i];

      if (x1 >= 1 && x1 <= r && y1 >= 1 && y1 <= c && JaneDist[x1][y1] == -1 &&
          adj[x1][y1] != '#' && JaneDist[x][y] + 1 < FireDist[x1][y1]) {
        JaneDist[x1][y1] = JaneDist[x][y] + 1;
        q.push({x1, y1});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; tc++) {
    r = 0, c = 0;
    cin >> r >> c;
    ss.clear();
    int x, y;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        cin >> adj[i][j];
        if (adj[i][j] == 'J') {
          x = i, y = j;
        } else if (adj[i][j] == 'F') {
          ss.PB({i, j});
        }
      }
    }
    bfsFire();
    bfsJane(x, y);

    int ans = inf;
    for (int i = 1; i <= r; i++) {
      if (JaneDist[i][1] != -1)
        ans = min(ans, JaneDist[i][1]);
    }
    for (int i = 1; i <= r; i++) {
      if (JaneDist[i][c] != -1)
        ans = min(ans, JaneDist[i][c]);
    }
    for (int i = 1; i <= c; i++) {
      if (JaneDist[1][i] != -1)
        ans = min(ans, JaneDist[1][i]);
    }
    for (int i = 1; i <= c; i++) {
      if (JaneDist[r][i] != -1)
        ans = min(ans, JaneDist[r][i]);
    }
    if (ans == inf)
      cout << "Case " << tc << ": "
           << "IMPOSSIBLE" << endl;
    else
      cout << "Case " << tc << ": " << ans + 1 << endl;
  }
}
