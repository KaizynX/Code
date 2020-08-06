/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 15:07:49
 * @LastEditTime: 2020-07-23 16:34:03
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, m;
long long b[N];
long long res;
int rk[N];
vector<int> e[N];

struct DSU {
  int fa[N], num[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i, num[i] = 1; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) {
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    if (b[fx] < b[fy]) num[fx] += num[fy], fa[fy] = fx;
    else num[fy] += num[fx], fa[fx] = fy;
    return true;
  }
} dsu;

inline void solve() {
  res = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    rk[i] = i;
    res += b[i];
  }
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  sort(rk+1, rk+n+1, [](int x, int y) { return b[x] > b[y]; });
  dsu.init(n);
  for (int l = 1; l <= n; ++l) {
    int i = rk[l], fi = dsu[i];
    for (const int &j : e[i]) {
      int fj = dsu[j];
      if (b[j] >= b[i] && fi != fj) {
        res -= b[fi];
        dsu.merge(fi, fj);
      }
    }
  }
  cout << res << endl;
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(e[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}