/*
  IN THE NAME OF ALLAH
  Author: Moinul Hossain
  Northern University Bangladesh
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2e8;
const ll infLL = 1e18;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };

const int mx=1e4+123;
vector<vi> adj[mx];
ll dist[12][mx];

void dijkstra(int n, int s, int d) {
  for(int i=0; i<=d; i++) {
    for(int j=0; j<n; j++) dist[i][j]=infLL;
  }
  priority_queue<vl, vector<vl>, greater<vl>> pq;
  dist[0][s]=0;
  pq.push({0, 0, s});

  while(!pq.empty()) {
    ll currD = pq.top()[0];
    int cnt = pq.top()[1];
    int u = pq.top()[2];
    pq.pop();

    if(dist[cnt][u] < currD) continue;

    for(auto e : adj[u]) {
      int v=e[0];
      int w=e[1];
      int type=e[2];

      if(cnt+type<=d && currD+w<dist[type+cnt][v]) {
        dist[type+cnt][v]=currD+w;
        pq.push({dist[type+cnt][v], cnt+type, v});
      }
    }
  }
}

int main() {
  optimize();
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  for(int tc=1; tc<=t; tc++) {
    int n,m,k,d;
    cin >> n >> m >> k >> d;
    for(int i=0; i<n; i++) adj[i].clear();
    for(int i=1; i<=m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].PB({v, w, 0});
    }
    for(int i=1; i<=k; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].PB({v, w, 1});
    }
    dijkstra(n, 0, d);
    ll ans=infLL;
    for(int i=0; i<=d; i++) {
      ans=min(ans, dist[i][n-1]);
    }
    if(ans==infLL) cout << "Case " << tc << ": Impossible\n";
    else cout << "Case " << tc << ": " << ans << endl; 
  }
}
