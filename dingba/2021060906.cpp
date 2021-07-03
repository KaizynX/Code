/*
 * @Author: Kaizyn
 * @Date: 2021-06-09 13:32:44
 * @LastEditTime: 2021-06-09 13:49:26
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
const int N = 2e5+7;

template <typename T>
struct PersistantSegmentTree {
  static const int NN = N*(log2(N)+5);
  int rt[N], ls[NN], rs[NN], tot, n;
  T sum[NN];
  void build(const int &n) {
    this->n = n;
    tot = 0;
    rt[0] = _build(1, n);
  }
  void update(const int &cur, const int &pre, const int &k, const T &v) {
    rt[cur] = _update(rt[pre], 1, n, k, v);
  }
  T query(const int &l, const int &r, const int &ql, const int &qr) {
    return _query(rt[l-1], rt[r], 1, n, ql, qr);
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
  int _update(const int &pre, const int &l, const int &r, const int &k, const T &v) {
    int cur = ++tot;
    ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+v;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    if (k <= mid) ls[cur] = _update(ls[pre], l, mid, k, v);
    else rs[cur] = _update(rs[pre], mid+1, r, k, v);
    return cur;
  }
  // [u, v] 段 [ql, qr] 区间和
  T _query(const int &u, const int &v, const int &l, const int &r, const int &ql, const int &qr) {
    if (l >= ql && r <= qr) return sum[v]-sum[u];
    int mid = (l+r)>>1;
    if (qr <= mid) return _query(ls[u], ls[v], l, mid, ql, qr);
    if (ql >  mid) return _query(rs[u], rs[v], mid+1, r, ql, qr);
    return _query(ls[u], ls[v], l, mid, ql, qr)+_query(rs[u], rs[v], mid+1, r, ql, qr);
  }
};
int n, q;
int last[N];
PersistantSegmentTree<ll> pst;

inline void solve() {
  cin >> n;
  pst.build(n);
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    if (last[a]) pst.update(i, i-1, last[a], i-last[a]);
    else pst.update(i, i-1, 1, 0);
    last[a] = i;
  }
  cin >> q;
  ll l, r, ans = 0;
  for (int i = 1; i <= q; ++i) {
    cin >> l >> r;
    l = (l^ans)%n+1;
    r = (r^ans)%n+1;
    if (l > r) swap(l, r);
    ans = pst.query(l, r, l, r);
    cout << ans << '\n';
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