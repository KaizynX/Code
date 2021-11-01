/*
 * @Author: Kaizyn
 * @Date: 2021-11-01 13:11:17
 * @LastEditTime: 2021-11-01 14:13:57
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
const int N = 1e6+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, m;
int a[N], b[N], c[N<<1], k[N];
BinaryIndexedTree<int> tree;

void discrete() {
  memcpy(c+1, a+1, sizeof(int)*n);
  memcpy(c+n+1, b+1, sizeof(int)*m);
  sort(c+1, c+n+m+1);
  int sz = unique(c+1, c+n+m+1)-c;
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(c+1, c+sz, a[i])-c;
  for (int i = 1; i <= m; ++i) b[i] = lower_bound(c+1, c+sz, b[i])-c;
}

void DP(int l, int r, int k_l, int k_r) {
  int mid = (l + r) / 2;
  // 求状态f[mid]的最优决策点
  int cntl = 0, cntr = 0, cnt;
  for (int i = k_l+1; i <= k_r; ++i) cntr += a[i] < b[mid];
  cnt = cntr;
  k[mid] = k_l;
  for (int i = k_l+1; i <= k_r; ++i) {
    cntr -= a[i] < b[mid];
    cntl += a[i] > b[mid];
    if (cntl+cntr < cnt) {
      cnt = cntl+cntr;
      k[mid] = i;
    }
  }
  // 根据决策单调性得出左右两部分的决策区间，递归处理
  if (l < mid) DP(l, mid - 1, k_l, k[mid]);
  if (r > mid) DP(mid + 1, r, k[mid], k_r);
}

inline void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int i = 1; i <= m; ++i) scanf("%d", b+i);
  discrete();
  sort(b+1, b+m+1);
  DP(1, m, 0, n);
  ll ans = 0;
  tree.init(n+m);
  int j = 1, z = 0;
  for (int i = 1; i <= m; ++i) {
    while (j <= k[i]) c[++z] = a[j++];
    c[++z] = b[i];
  }
  while (j <= n) c[++z] = a[j++];
  #ifdef DEBUG
  orzarr(a+1, n);
  orzarr(b+1, m);
  orzarr(k+1, m);
  orzarr(c+1, n+m);
  #endif
  for (int i = n+m; i; --i) {
    ans += tree.query(c[i]-1);
    tree.add(c[i], 1);
  }
  cout << ans << '\n';
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