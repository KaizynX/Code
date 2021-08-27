/*
 * @Author: Kaizyn
 * @Date: 2021-08-27 16:26:33
 * @LastEditTime: 2021-08-27 16:47:34
 */
#include <bits/stdc++.h>

#define DEBUG

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
  // 第k大
  int _query(const int &u, const int &v, const int &l, const int &r, const int &k) {
    if (l >= r) return l;
    int num = sum[rs[v]]-sum[rs[u]], mid = (l+r)>>1;
    if (k <= num) return _query(rs[u], rs[v], mid+1, r, k);
    else return _query(ls[u], ls[v], l, mid, k-num);
  }
};

int n, q, dfn;
int f[N], a[N], L[N], R[N];
vector<int> e[N];
PersistantSegmentTree<int> tree2, tree3;
SAonTree satree;
int *sa = satree.sa, *rk = satree.rk;

void dfs(int u, int fa = 0) {
  L[u] = ++dfn;
  tree3.update(dfn, dfn-1, rk[u]);
  tree2.update(u, fa, rk[u]);
  for (int v : e[u]) dfs(v, u);
  R[u] = dfn;
}

template <typename T>
void discrete(T a[], int n) {
  vector<T> d(a, a+n);
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(d.begin(), d.end(), a[i])-d.begin()+1;
  }
}

signed main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", f+i);
    e[f[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  discrete(a+1, n);
  satree.build(f, a, n);
  #ifdef DEBUG
  orzarr(rk+1, n);
  orzarr(sa+1, n);
  #endif
  tree2.build(n);
  tree3.build(n);
  dfs(1);
  for (int i = 1, opt, x, k, ans; i <= q; ++i) {
    scanf("%d%d", &opt, &x);
    if (opt == 1) {
      ans = n-rk[x]+1;
    } else if (opt == 2) {
      scanf("%d", &k);
      ans = sa[tree2.query(1, x, k)];
    } else if (opt == 3) {
      scanf("%d", &k);
      ans = sa[tree3.query(L[x], R[x], k)];
    }
    printf("%d\n", ans);
  }
  return 0;
}