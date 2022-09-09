/*
  IN THE NAME OF ALLAH
  Author: Moinul Hossain
  Northern University Bangladesh
*/

#include <bits/stdc++.h>
#include <climits>
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

const int mx = 3e4 + 123;
vii adj[mx];
int dist[mx];

void bfs(int s) {
  mem(dist, -1);
  dist[s] = 0;
  queue<pii> q;
  q.push({0, s});

  while (!q.empty()) {
    int u = q.front().S;
    int currD = q.front().F;
    q.pop();

    for (auto e : adj[u]) {
      int v = e.F;
      int w = e.S;
      if (dist[v] == -1) {
        dist[v] = currD + w;
        q.push({dist[v], v});
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
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
      adj[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].PB({v, w});
      adj[v].PB({u, w});
    }
    bfs(0);

    int maxDist = INT_MIN, node;
    for (int i = 0; i < n; i++) {
      if (dist[i] > maxDist) {
        maxDist = dist[i];
        node = i;
      }
    }
    bfs(node);
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dist[i]);
    }
    cout << "Case " << tc << ": " << ans << endl;
  }
}
