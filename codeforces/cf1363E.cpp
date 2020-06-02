/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 23:16:01
 * @LastEditTime: 2020-05-31 23:28:40
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N], b[N], c[N], rk[N], vis[N], fa[N];
int cnt[N][2];
vector<int> e[N];

void dfs(const int &u, const int &f) {
  fa[u] = f;
  for (const int &v : e[u]) if (v != fa[u]) {
    dfs(v, u);
  }
}

void get_cnt(const int &u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (const int &v : e[u]) if (v != fa[u]) {
    get_cnt(v);
    cnt[u][0] += cnt[v][0];
    cnt[u][1] += cnt[v][1];
  }
  if (b[u] != c[u]) ++cnt[u][b[u]];
}

inline long long solve() {
  int sumb = 0, sumc = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    sumb += b[i];
    sumc += c[i];
    rk[i] = i;
  }
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  if (sumb != sumc) return -1;
  dfs(1, 0);
  sort(rk+1, rk+n+1, [](const int &x, const int &y) {
      return a[x] < a[y];
  });
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[rk[i]]) continue;
    get_cnt(rk[i]);
    #ifdef DEBUG
    cout << rk[i] << " " << cnt[rk[i]][0] << " " << cnt[rk[i]][1] << endl;
    #endif
    int t = min(cnt[rk[i]][0], cnt[rk[i]][1]);
    res += 2ll*t*a[rk[i]];
    cnt[rk[i]][0] -= t;
    cnt[rk[i]][1] -= t;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}