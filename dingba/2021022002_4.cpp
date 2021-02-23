/*
 * @Author: Kaizyn
 * @Date: 2021-02-21 10:18:30
 * @LastEditTime: 2021-02-21 14:40:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;
const int M = 4e2+7;

int n, m, q, tot;
int d[N], p[N], mp[N], L[N], R[N]; //, u[M], v[M], w[M];
ll dis[N<<1], f[M][M];

void add_mp(int x) {
  if (mp[x]) return;
  p[++tot] = x;
  mp[x] = tot;
}

inline ll calc(int x, int y) {
  if (x > y) swap(x, y);
  return min(dis[y]-dis[x], dis[x+n]-dis[y]);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    dis[i+1] = dis[i]+d[i];
  }
  for (int i = 1; i <= n; ++i) {
    dis[n+i+1] = dis[n+i]+d[i];
  }
  memset(f, 0x3f, sizeof f);
  /*
  for (int i = 1; i <= m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    add_mp(u[i]);
    add_mp(v[i]);
    f[mp[u[i]]][mp[v[i]]] = f[mp[v[i]]][mp[u[i]]] = w[i];
  }
  */
  for (int i = 1, u, v, w; i <= m; ++i) {
    cin >> u >> v >> w;
    add_mp(u);
    add_mp(v);
    f[mp[u]][mp[v]] = f[mp[v]][mp[u]] = w;
  }
  for (int i = 1; i <= tot; ++i) {
    f[i][i] = 0;
    for (int j = 1; j < i; ++j) {
      f[i][j] = f[j][i] = min(f[i][j], calc(p[i], p[j]));
    }
  }
  for (int k = 1; k <= tot; ++k) {
    for (int i = 1; i <= tot; ++i) if (i != k) {
      for (int j = 1; j <= tot; ++j) if (i != j && j != k) {
        f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
      }
    }
  }

  int last = 0;
  for (int i = 1; i <= n; ++i) {
    if (mp[i]) {
      last = i;
      break;
    }
  }
  for (int i = n; i; --i) {
    if (mp[i]) last = i;
    R[i] = last;
  }
  for (int i = n; i; --i) {
    if (mp[i]) {
      last = i;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (mp[i]) last = i;
    L[i] = last;
  }

  cin >> q;
  for (int i = 1, x, y; i <= q; ++i) {
    cin >> x >> y;
    cout << min({calc(x, y),
        calc(x, L[x])+calc(y, L[y])+f[mp[L[x]]][mp[L[y]]],
        calc(x, L[x])+calc(y, R[y])+f[mp[L[x]]][mp[R[y]]],
        calc(x, R[x])+calc(y, L[y])+f[mp[R[x]]][mp[L[y]]],
        calc(x, R[x])+calc(y, R[y])+f[mp[R[x]]][mp[R[y]]]}) << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}