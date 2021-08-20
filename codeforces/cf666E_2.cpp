/*
 * @Author: Kaizyn
 * @Date: 2021-08-20 16:04:02
 * @LastEditTime: 2021-08-20 16:50:05
 */
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
#define log(x) (31-__builtin_clz(x))
const int N = 5e5+7;
const int LOGN = log(N)+5;
const int M = N<<1;
const int NLOG = 2e7+7;

int m, q;
string s, t;

template <typename T>
struct Tree {
  int tot, lc[NLOG], rc[NLOG];
  T tr[NLOG];
  T giao(const T &x, const T &y) { return max(x, y); }
  void push_up(int i) { tr[i] = giao(tr[lc[i]], tr[rc[i]]); }
  int new_node(T v = {0, 0}) {
    assert(++tot < NLOG);
    lc[tot] = rc[tot] = 0;
    tr[tot] = v;
    return tot;
  }
  void add(int x, int l, int r, int &i) {
    if (!i) i = new_node(pii{0, -l});
    if (l == r) return ++tr[i].first, void();
    int mid = (l+r)>>1;
    if (x <= mid) add(x, l, mid, lc[i]);
    else add(x, mid+1, r, rc[i]);
    push_up(i);
  }
  int merge(int l, int r, int x, int y) {
    if (!x || !y) return x += y;
    int cur = new_node(), mid = (l+r)>>1;
    if (l == r) {
      tr[cur] = pii{tr[x].first+tr[y].first, -l};
      return cur;
    }
    lc[cur] = merge(l, mid, lc[x], lc[y]);
    rc[cur] = merge(mid+1, r, rc[x], rc[y]);
    push_up(cur);
    return cur;
  }
  T query(int L, int R, int l, int r, int i) {
    if (!i) return pii{0, -L};
    if (L <= l && r <= R) return tr[i];
    int mid = (l+r)>>1;
    if (R <= mid) return query(L, R, l, mid, lc[i]);
    if (L >  mid) return query(L, R, mid+1, r, rc[i]);
    return giao(query(L, R, l, mid, lc[i]), query(L, R, mid+1, r, rc[i]));
  }
};

Tree<pii> tree;

struct generalSAM {
  static const int A = 26;
  static const char C = 'a';
  int sz, len[M], link[M], nex[M][A];
  int t[M], rk[M], tr[M], ed[M], ml[M], fa[M][LOGN];
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
  void insert(const string &s, int id) {
    int last = 0; for (char ch : s) {
      last = extend(last, ch-C);
      tree.add(id, 1, m, tr[last]);
    }
  }
  void build(const string &s) {
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = 1, i; _ < sz; ++_) { // assert(rk[0] == 0);
      i = rk[_];
      fa[i][0] = link[i];
      for (int j = 0; fa[i][j]; ++j) {
        fa[i][j+1] = fa[fa[i][j]][j];
      }
    }
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      tr[j] = tree.merge(1, m, tr[j], tr[i]);
    }
    int u = 0, c, l = 0;
    for (int i = 1; i <= (int)s.size(); ++i) {
      c = s[i-1]-C;
      while (u && !nex[u][c]) l = len[u = link[u]];
      if (nex[u][c]) u = nex[u][c], ++l;
      ed[i] = u;
      ml[i] = l;
    }
  }
  pii query(int l, int r, int pl, int pr) {
    if (pr-pl+1 > ml[pr]) return pii{0, -l};
    int u = ed[pr];
    for (int j = 19; j >= 0; --j) {
      if (len[fa[u][j]] >= pr-pl+1) u = fa[u][j];
    }
    return tree.query(l, r, 1, m, tr[u]);
  }
} gsam;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> s >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> t;
    gsam.insert(t, i);
  }
  gsam.build(s);
  cin >> q;
  for (int i = 1, pl, pr, l, r; i <= q; ++i) {
    cin >> l >> r >> pl >> pr;
    auto ans = gsam.query(l, r, pl, pr);
    cout << -ans.second << " " << ans.first << '\n';
  }
  return 0;
}
/*
dl
3
df
dk
ld
3
1 3 1 1
1 3 1 2
2 3 1 2
*/