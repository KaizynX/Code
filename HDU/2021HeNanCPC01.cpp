/*
 * @Author: Kaizyn
 * @Date: 2021-09-18 14:16:18
 * @LastEditTime: 2021-09-21 13:57:46
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
const int N = 1e5+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

struct Node {
  int h, l, r;
  bool operator<(const Node &b) const { return h < b.h; }
};

int n, m;
int h[N], rk[N];
Node a[N];
set<int> st;
DSU dsu;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    rk[i] = i;
  }
  sort(rk+1, rk+n+1, [&](int x, int y) {
    return h[x] < h[y];
  });
  for (int i = 1; i <= m; ++i) {
    cin >> a[i].h >> a[i].l >> a[i].r;
  }
  sort(a+1, a+m+1);
  dsu.init(n+1);
  st.clear();
  st.insert(0);
  st.insert(n+1);
  for (int i = 1, j = 1; i <= m; ++i) {
    while (j <= n && h[rk[j]] <= a[i].h) st.insert(rk[j++]);
    auto l = st.lower_bound(a[i].l-1);
    auto r = --st.upper_bound(a[i].r+1);
    if (*l > *r) continue;
    for (int k = max(a[i].l, dsu[*l]); k <= min(a[i].r, *r); k = dsu[k+1]) {
      h[k] = min(h[k], a[i].h-1);
      dsu.merge(k, k+1);
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) ans += h[i];
  #ifdef DEBUG
  orzarr(h+1, n);
  #endif
  sort(rk+1, rk+n+1, [&](int x, int y) {
    return h[x] < h[y];
  });
  st.clear();
  st.insert(0);
  st.insert(n+1);
  for (int i = 1, j = 1; i <= m; ++i) {
    while (j <= n && h[rk[j]] <= a[i].h) st.insert(rk[j++]);
    auto l = st.lower_bound(a[i].l);
    auto r = --st.upper_bound(a[i].r);
    if (*l > *r) ans -= a[i].r-a[i].l+1;
    else ans -= *l-a[i].l+a[i].r-*r;
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
/*
7 2
4 5 2 3 2 5 4
2 2 6
4 2 6

5 2
2 5 2 5 2
2 2 2 
2 4 4

*/
/*
15
8
*/