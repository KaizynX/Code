/*
 * @Author: Kaizyn
 * @Date: 2021-11-22 15:06:34
 * @LastEditTime: 2021-11-22 16:36:42
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
const ll INF = 1e18;
const int N = 3e5+7;

template <typename T, typename U = greater<T>>
struct SegmentTree {
  U cmp = U();
  struct TreeNode {
    int l, r;
    T v;
  } tr[N<<2];
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
  void build(int n) { build(1, n); }
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r; tr[i].v = 0;
    if (l == r) return;
    int mid = (l+r)/2;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void update(int x, T v, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].v = v, void();
    int mid = (tr[i].l+tr[i].r)/2;
    if (x <= mid) update(x, v, i<<1);
    else update(x, v, i<<1|1);
    tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v);
  }
  int query(T v) {
    if (!cmp(tr[1].v, v)) return 1000000;
    return query(v, 1);
  }
  int query(T v, int i) { // the first U(tr, v)
    if (tr[i].l == tr[i].r) return tr[i].l;
    if (cmp(tr[i<<1].v, v)) return query(v, i<<1);
    else return query(v, i<<1|1);
  }
};

int n, m;
int a[N];
map<ll, vector<int>> mp;
ll sum[N];
SegmentTree<ll, less<ll>> tr1;
SegmentTree<ll, greater<ll>> tr0;

inline void solve() {
  mp.clear();
  cin >> n;
  m = (n+1)/2;
  tr0.build(m);
  tr1.build(m);
  mp[0].emplace_back(1);
  for (int i = 2; i <= n+1; ++i) {
    cin >> a[i];
    sum[i] = sum[i-1];
    if (i&1) {
      sum[i] += a[i];
      tr1.update(i/2, sum[i]);
    } else {
      sum[i] -= a[i];
      tr0.update(i/2, sum[i]);
    }
    mp[sum[i]].emplace_back(i);
  }
  #ifdef DEBUG
  orzarr(sum+2, n);
  #endif
  ll ans = 0, bias = 0;
  for (int i = 2; i <= n+1; ++i) {
    int p0 = 2*tr0.query(bias);
    int p1 = 2*tr1.query(bias)+1;
    int p = min(min(p0, p1)-1, n+1);
    auto &vec = mp[sum[i-1]];
    ans += upper_bound(vec.begin(), vec.end(), p)-lower_bound(vec.begin(), vec.end(), i);
    #ifdef DEBUG
    orzeach(vec);
    orz(p0);
    orz(p1);
    orz(ans);
    #endif
    if (i&1) {
      bias += a[i];
      tr1.update(i/2, INF);
    } else {
      bias -= a[i];
      tr0.update(i/2, -INF);
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}