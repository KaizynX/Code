/*
 * @Author: Kaizyn
 * @Date: 2021-08-19 13:43:42
 * @LastEditTime: 2021-08-19 16:53:14
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
#ifdef DEBUG
const int N = 10+3;
const int BLOCK = 10+7;
using BT = bitset<6>;
#else
const int N = 4e5+3;
const int BLOCK = 1e3+7;
const int S = 1000;
using BT = bitset<200000>;
#endif

struct Node {
  int l, r, id;
  bool operator <(const Node &b) {
    return r > b.r;
  }
};

int n, q; // S;
char s[N];
int res[N];
vector<Node> a[BLOCK];
BT buf[BLOCK], *pre = buf+1, suf;

struct HLD {
  int fa[N], d[N], num[N], son[N], tp[N];
  vector<int> *e;
  void build(vector<int> *e, const int &rt = 1) {
    this->e = e;
    d[0] = 0;
    fa[rt] = 0;
    dfs1(rt);
    dfs2(rt);
  }
  void dfs1(const int &u = 1) {
    d[u] = d[fa[u]]+1;
    num[u] = 1;
    son[u] = 0;
    for (const int &v : e[u]) if (v != fa[u]) {
      fa[v] = u;
      dfs1(v);
      num[u] += num[v];
      if (num[v] > num[son[u]]) son[u] = v;
    }
  }
  void dfs2(const int &u = 1) {
    tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
    if (son[u]) dfs2(son[u]);
    for (const int &v : e[u]) if (v != son[u] && v != fa[u])
      dfs2(v);
  }
  int lca(int x, int y) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      x = fa[tp[x]];
    }
    return d[x] < d[y] ? x : y;
  }
} LCA;

struct SAM {
  static const int A = 26;
  static const int M = N;
  static const char C = 'a';
  int sz, last, len[M], link[M], nex[M][A];
  vector<int> e[M], add[M];
  int pre[M], suf[M];
  // SAM() { init(); }
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    for (int i = 0; i < sz; ++i) {
      e[i].clear();
      add[i].clear();
    }
    link[0] = -1; sz = 1; last = 0;
  }
  int extend(int c) {
    int cur = sz++, p = last;
    len[cur] = len[last]+1;
    for (; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    link[clone] = link[q];
    len[clone] = len[p]+1;
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[q] = link[cur] = clone;
    return cur;
  }
  void build(const char *s, int n, int rev) {
    init();
    for (int i = 0; i < n; ++i) {
      last = extend(s[i]-C);
      pre[i] = last;
    }
    for (int i = n, j = last; i; --i) {
      while (j && len[link[j]] >= i) j = link[j];
      suf[i-1] = j;
    }
    for (int i = 1; i < sz; ++i) e[link[i]].emplace_back(i);
    LCA.build(e, 0);
    for (int i = 0; i < n; ++i) {
      add[LCA.lca(suf[n-1], pre[i])].emplace_back(rev ? n-i-1 : i);
    }
    #ifdef DEBUG
    cout << "pre:"; for (int i = 0; i < n; ++i) cout << pre[i] << " \n"[i==n-1];
    cout << "suf:"; for (int i = 0; i < n; ++i) cout << suf[i] << " \n"[i==n-1];
    cout << "lca:"; for (int i = 0; i < n; ++i) cout << LCA.lca(last, pre[i]) << " \n"[i==n-1];
    #endif
  }
} sam_pre, sam_suf;

inline void solve() {
  scanf("%d%d%s", &n, &q, s);
  // S = sqrt(n)+.5; // 分块大小
  // S = 1000; // 分块大小
  for (int i = 0; i <= (n-1)/S; ++i) a[i].clear();
  sam_suf.build(s, n, 0);
  reverse(s, s+n);
  sam_pre.build(s, n, 1);
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    --l; --r;
    a[l/S].emplace_back(Node{l, r, i});
  }
  pre[S].reset();
  pre[(n-1)%S+1].reset();
  for (int i = (n-1)/S; i >= 0; --i) {
    sort(a[i].begin(), a[i].end());
    for (int j = min(n-1, i*S+S-1); j >= i*S; --j) {
      pre[j%S] = pre[j%S+1];
      for (int k : sam_pre.add[sam_pre.suf[j]]) {
        pre[j%S].set(k);
      }
      #ifdef DEBUG
      cout << "pre[" << j << "]=" << pre[j%S] << '\n';
      #endif
    }
    pre[S] = pre[0];

    suf.reset();
    int u = n-1;
    for (auto &p : a[i]) {
      while (u >= p.r) {
        for (int k : sam_suf.add[sam_suf.suf[u]]) suf.set(k);
        #ifdef DEBUG
        cout << "suf[" << u << "]=" << suf << '\n';
        #endif
        --u;
      }
      if (p.l+p.r+2 > n) {
        res[p.id] = 0;
        continue;
      } else if (p.l+p.r+2 == n) {
        res[p.id] = 1;
        continue;
      } else {
        res[p.id] = (pre[p.l%S]&(suf>>(p.l+p.r+1))).count();
      }
    }
  }
  for (int i = 1; i <= q; ++i) printf("%d\n", res[i]);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}