/*
 * @Author: Kaizyn
 * @Date: 2021-08-27 14:21:25
 * @LastEditTime: 2021-08-27 16:15:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;
#define log(x) (31-__builtin_clz(x))

struct SAonTree {
  static const int LOGN = 33-__builtin_clz(N);
  int n, d[N], cnt[N], sa[N], rk[N<<1], _rk[N<<1], _oldrk[N<<1], tp[N<<1];
  template <typename T>
  void tsort(int *sa, T *rk, int *tp, int m) {
    memset(cnt, 0, sizeof(int)*(m+1));
    for (int i = 1; i <= n; ++i) ++cnt[rk[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
    for (int i = n; i; --i) sa[cnt[rk[tp[i]]]--] = tp[i];
  }
  template <typename T>
  void build(int *f, const T *a, const int n) {
    this->n = n;
    int p = n, i;
    iota(tp+1, tp+n+1, 1);
    tsort(sa, a, tp, p);
    for (i = 1, p = 0; i <= n; ++i) {
      _rk[sa[i]] = a[sa[i-1]] == a[sa[i]] ? p : ++p;
      rk[sa[i]] = i;
    }
    for (int w = 1; w < n; w <<= 1) {
      for (i = 1; i <= n; ++i) _oldrk[i] = rk[f[i]];
      tsort(tp, _oldrk, sa, n);
      tsort(sa, _rk, tp, p);
      swap(_rk, tp);
      for (i = 1, p = 0; i <= n; ++i) {
        _rk[sa[i]] = tp[sa[i-1]] == tp[sa[i]]
            && tp[f[sa[i-1]]] == tp[f[sa[i]]] ? p : ++p;
        rk[sa[i]] = i;
      }
      for (int i = n; i; --i) f[i] = f[f[i]];
    }
  }
};

struct SegmentTree {
  struct TreeNode {
    int l, r, v;
  } tr[N<<1];
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r; tr[i].v = 0;
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void update(int x, int v, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].v += v, void();
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) update(x, v, i<<1);
    else update(x, v, i<<1|1);
    tr[i].v = tr[i<<1].v+tr[i<<1|1].v;
  }
  int query(int k, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].l;
    if (tr[i<<1].v >= k) return query(k, i<<1);
    else return query(k-tr[i<<1].v, i<<1|1);
  }
};

template <typename T>
struct PersistantSegmentTree {
  static const int NN = N*(log(N)+5);
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
  int _query(const int &u, const int &v, const int &l, const int &r, const int &k) {
    if (l >= r) return l;
    int num = sum[ls[v]]-sum[ls[u]], mid = (l+r)>>1;
    if (num >= k) return _query(ls[u], ls[v], l, mid, k);
    else return _query(rs[u], rs[v], mid+1, r, k-num);
  }
};

int n, q, dfn;
int f[N], a[N], rk[N], sa[N], ans[N], L[N], R[N], mp[N];
int q3x[N], q3k[N];
vector<int> e[N];
vector<pii> q2[N];
PersistantSegmentTree<int> pst;
SAonTree satree;
SegmentTree tree;

void dfs(int u) {
  ++dfn;
  mp[dfn] = u;
  L[u] = dfn;
  tree.update(rk[u], 1);
  for (auto qq : q2[u]) ans[qq.second] = sa[tree.query(qq.first)];
  for (int v : e[u]) dfs(v);
  R[u] = dfn;
  tree.update(rk[u], -1);
}

template <typename T>
void discrete(T a[], int n) {
  vector<int> d(a, a+n);
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(d.begin(), d.end(), a[i])-d.begin()+1;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> q;
  for (int i = 2; i <= n; ++i) {
    cin >> f[i];
    e[f[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) cin >> a[i];
  discrete(a+1, n);
  satree.build(f, a, n);
  for (int i = 1; i <= n; ++i) {
    rk[i] = n-satree.rk[i]+1;
    sa[rk[i]] = i;
  }
  #ifdef DEBUG
  orzarr(rk+1, n);
  orzarr(sa+1, n);
  orzarr(satree.rk+1, n);
  orzarr(satree.sa+1, n);
  #endif
  for (int i = 1, opt, x, k; i <= q; ++i) {
    cin >> opt >> x;
    if (opt == 1) {
      ans[i] = rk[x];
    } else if (opt == 2) {
      cin >> k;
      q2[x].emplace_back(k, i);
    } else if (opt == 3) {
      q3x[i] = x;
      cin >> q3k[i];
    }
  }
  tree.build(1, n);
  dfs(1);
  pst.build(n);
  for (int i = 1; i <= n; ++i) pst.update(i, i-1, rk[mp[i]]);
  for (int i = 1; i <= q; ++i) {
    if (q3x[i]) ans[i] = pst.query(L[q3x[i]], R[q3x[i]], sa[q3k[i]]);
    cout << ans[i] << '\n';
  }
  return 0;
}