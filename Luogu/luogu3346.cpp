/*
 * @Author: Kaizyn
 * @Date: 2021-08-08 15:08:08
 * @LastEditTime: 2021-08-08 15:34:36
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

struct generalSAM {
  static const int A = 10;
  static const int M = N*20*2;
  static const char C = '0';
  int sz, len[M], link[M], nex[M][A];
  generalSAM() { init(); }
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    link[0] = -1; sz = 1;
  }
  int extend(int last, int c) {
    if (nex[last][c]) {
      int p = last, cur = nex[p][c];
      if (len[p]+1 == len[cur]) return cur;
      int q = sz++;
      len[q] = len[p]+1;
      memcpy(nex[q], nex[cur], sizeof nex[q]);
      for ( ; ~p && nex[p][c] == cur; p = link[p]) nex[p][c] = q;
      link[q] = link[cur];
      link[cur] = q;
      return q;
    }
    int cur = sz++, p = last;
    len[cur] = len[p]+1;
    for ( ; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    len[clone] = len[p]+1;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[clone] = link[q];
    link[q] = link[cur] = clone;
    return cur;
  }
  void insert(const string &s) {
    int last = 0; for (char ch : s) last = extend(last, ch-C);
  }
  void insert(const char *s) {
    for (int i = 0, last = 0; s[i]; ++i) last = extend(last, s[i]-C);
  }
  ll solve() {
    ll cnt = 0;
    for (int i = 1; i < sz; ++i) cnt += len[i]-len[link[i]];
    return cnt;
  }
};

int n, C;
int a[N], deg[N];
vector<int> e[N];
generalSAM gsam;

void dfs(int u, int fa = 0, int last = 0) {
  int nex = gsam.extend(last, a[u]);
  for (int v : e[u]) if (v != fa) dfs(v, u, nex);
}

inline void solve() {
  cin >> n >> C;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    ++deg[u];
    ++deg[v];
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) if (deg[i] == 1) {
    dfs(i);
  }
  cout << gsam.solve() << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}