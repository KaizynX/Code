/*
 * @Author: Kaizyn
 * @Date: 2021-08-20 13:22:36
 * @LastEditTime: 2021-08-20 15:23:32
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
const int NLOG = M*LOGN;

int n, m, q;
int endpos[N], fa[M][LOGN];
string s, t;
vector<array<int, 3>> qry[M];
pii ans[N];

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
  void add(int x, int v, int l, int r, int &i) {
    if (!i) i = new_node(pii{0, -l});
    if (l == r) return tr[i].first += v, void();
    int mid = (l+r)>>1;
    if (x <= mid) add(x, v, l, mid, lc[i]);
    else add(x, v, mid+1, r, rc[i]);
    push_up(i);
  }
  void merge(int l, int r, int &x, int &y) { // merge y to x
    if (!x || !y) return x += y, void();
    if (l == r) return tr[x].first += tr[y].first, void();
    int mid = (l+r)>>1;
    merge(l, mid, lc[x], lc[y]);
    merge(mid+1, r, rc[x], rc[y]);
    push_up(x); // del(y);
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
  int t[M], rk[M], tr[M];
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
      tree.add(id, 1, 1, m, tr[last]);
    }
  }
  void build() {
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
  }
  void get_fa() {
    for (int _ = 1, i; _ < sz; ++_) { // assert(rk[0] == 0);
      i = rk[_];
      fa[i][0] = link[i];
      for (int j = 0; fa[i][j]; ++j) {
        fa[i][j+1] = fa[fa[i][j]][j];
      }
    }
  }
  void get_endpos(const string &s) {
    int u = 0, c;
    for (int i = 1; i <= (int)s.size(); ++i) {
      c = s[i-1]-C;
      while (u && !nex[u][c]) u = link[u];
      if (nex[u][c]) u = nex[u][c];
      endpos[i] = u;
    }
  }
  void solve() {
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      for (auto qqq : qry[i]) {
        ans[qqq[2]] = tree.query(qqq[0], qqq[1], 1, m, tr[i]);
      }
      tree.merge(1, m, tr[j], tr[i]);
    }
  }
} gsam;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> s >> m;
  n = s.size();
  for (int i = 1; i <= m; ++i) {
    cin >> t;
    gsam.insert(t, i);
  }
  gsam.build();
  gsam.get_fa();
  gsam.get_endpos(s);
  cin >> q;
  for (int i = 1, pl, pr, l, r; i <= q; ++i) {
    cin >> l >> r >> pl >> pr;
    int u = endpos[pr];
    for (int j = 19; j >= 0; --j) {
      if (gsam.len[fa[u][j]] >= pr-pl+1) {
        u = fa[u][j];
      }
    }
    #ifdef DEBUG
    cout << i << ':' << endpos[pr] << "->" << u << '\n';
    #endif
    if (gsam.len[u] < pr-pl+1) ans[i] = pii{0, -l};
    else qry[u].emplace_back(array<int, 3>{l, r, i});
  }
  gsam.solve();
  #ifdef DEBUG
  cout << gsam.nex[gsam.nex[0]['e'-'a']]['e'-'a'] << '\n';
  puts("****");
  for (int u = endpos[10]; u; u = gsam.link[u]) {
    cout << u << ' ' << gsam.len[u] << '\n';
  }
  #endif
  for (int i = 1; i <= q; ++i) {
    cout << -ans[i].second << " " << ans[i].first << '\n';
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