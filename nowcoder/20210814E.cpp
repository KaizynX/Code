/*
 * @Author: Kaizyn
 * @Date: 2021-08-14 12:17:57
 * @LastEditTime: 2021-08-14 13:13:31
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
#define log(x) (31-__builtin_clz(x))
const int N = 1e5+7;
const int LOGN = log(N)+5;

template <typename T>
struct PersistantSegmentTree {
  static const int NN = N*LOGN;
  int rt[N], sum[NN], ls[NN], rs[NN], tot, n;
  void build(const int &n) {
    this->n = n;
    tot = 0;
    rt[0] = _build(1, n);
  }
  void update(const int &cur, const int &pre, const T &k) {
    rt[cur] = _update(rt[pre], 1, n, k);
  }
  T query(const int &l, const int &r, const int &k) {
    return _query(rt[l-1], rt[r], 1, n, k);
  }
private:
  int _build(const int &l, const int &r) {
    int cur = ++tot;
    sum[cur] = 0;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    ls[cur] = _build(l, mid);
    rs[cur] = _build(mid+1, r);
    return cur;
  }
  int _update(const int &pre, const int &l, const int &r, const int &k) {
    int cur = ++tot;
    ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+1;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    if (k <= mid) ls[cur] = _update(ls[pre], l, mid, k);
    else rs[cur] = _update(rs[pre], mid+1, r, k);
    return cur;
  }
  /*
  int _query(const int &u, const int &v, const int &l, const int &r, const int &k) {
    if (l >= r) return l;
    int num = sum[ls[v]]-sum[ls[u]], mid = (l+r)>>1;
    if (num >= k) return _query(ls[u], ls[v], l, mid, k);
    else return _query(rs[u], rs[v], mid+1, r, k-num);
  }
  */
  int _query(const int &u, const int &v, const int &l, const int &r, const int &k) {
    if (l >= k) return sum[v]-sum[u];
    if (r < k) return 0;
    int mid = (l+r)>>1;
    return _query(rs[u], rs[v], mid+1, r, k)+_query(ls[u], ls[v], l, mid, k);
  }
};

int n, q, _dfn;
int t[N], dfn[N], sz[N], mp[N], d[N];
int f[N][LOGN];
vector<int> e[N], dis;
PersistantSegmentTree<int> tree;

int lb(int x) {
  return lower_bound(dis.begin(), dis.end(), x)-dis.begin()+1;
}

void discrete() {
  dis = vector<int>(t+1, t+n+1);
  dis.emplace_back(1); dis.emplace_back(1e9);
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  for (int i = 1; i <= n; ++i) {
    t[i] = lb(t[i]);
  }
}

void dfs(int u, int fa = 0) {
  dfn[u] = ++_dfn;
  mp[_dfn] = u;
  sz[u] = 1;
  d[u] = d[fa]+1;
  f[u][0] = fa;
  for (int i = 1; (1<<i) <= d[u]; ++i) {
    f[u][i] = f[f[u][i-1]][i-1];
  }
  for (int v : e[u]) if (v != fa) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

void build() {
  tree.build(dis.size());
  for (int i = 1; i <= n; ++i) {
    tree.update(i, i-1, t[mp[i]]);
  }
}

int query(int x, int l, int r) {
  l = lb(l);
  r = upper_bound(dis.begin(), dis.end(), r)-dis.begin(); // <=
  if (t[x] < l || t[x] > r) return 0;
  for (int i = log(d[x]); i >= 0; --i) {
    if (t[f[x][i]] <= r) x = f[x][i];
  }
  #ifdef DEBUG
  printf("query(%d,%d,%d)\n", x, l, r);
  #endif
  return tree.query(dfn[x], dfn[x]+sz[x]-1, l);
}

inline void solve() {
  cin >> n;
  // clear e
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) cin >> t[i];
  discrete();
  t[0] = 1e9+7;
  dfs(1);
  build();
  #ifdef DEBUG
  for (int i : dis) cout << i << ' ';
  cout << ":dis\n";
  #endif
  cin >> q;
  for (int _ = q, l, r, x; _; --_) {
    cin >> x >> l >> r;
    cout << query(x, l, r) << '\n';
  }
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
/*
4
1 2
1 3
1 4
10 5 1 8
100
*/
/*
10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 9 8 7 6 5 4 3 2 1
100
*/