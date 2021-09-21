/*
 * @Author: Kaizyn
 * @Date: 2021-09-05 22:40:32
 * @LastEditTime: 2021-09-06 00:03:01
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
const int N = 2e5+7;

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

int n, q;
int a[N], d[N];
set<int> p;
BinaryIndexedTree<ll> tree;

ll calc(int x) {
  int y = *(--p.lower_bound(x));
  // if (it == p.end() || *it != x) return 0;
  #ifdef DEBUG
  // orz(x);
  // orz((x-y)*(x-y+1ll)/2);
  #endif
  return (x-y)*(x-y+1ll)/2;
}

void my_erase(int x) {
  if (d[x] >= 0) return;
  int y = *p.upper_bound(x);
  tree.add(x, -calc(x));
  tree.add(y, -calc(y));
  p.erase(x);
  tree.add(y, calc(y));
}

void my_insert(int x) {
  if (d[x] >= 0) return;
  int y = *p.upper_bound(x);
  tree.add(y, -calc(y));
  p.insert(x);
  tree.add(x, calc(x));
  tree.add(y, calc(y));
}

inline void solve() {
  cin >> n >> q;
  tree.init(n+1);
  a[0] = INF;
  a[n+1] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    d[i] = a[i]-a[i-1];
  }
  d[n+1] = -a[n];
  p.insert(1);
  for (int i = 2; i <= n+1; ++i) {
    if (d[i] >= 0) continue;
    p.insert(i);
    tree.add(i, calc(i));
  }
  ll ans;
  for (int _ = q, op, x, y; _; --_) {
    cin >> op >> x >> y;
    if (op == 1) {
      /*
      if (d[x+1] < 0) {
        tree.add(x+1, -calc(x+1));
        p.erase(x+1);
      }
      if (x > 1 && d[x] < 0) {
        tree.add(x, -calc(x));
        p.erase(x);
      }
      */
      a[x] = y;
      if (x < n) my_erase(x+1);
      if (x > 1) my_erase(x);
      d[x] = a[x]-a[x-1];
      d[x+1] = a[x+1]-a[x];
      if (x > 1) my_insert(x);
      if (x < n) my_insert(x+1);
      #ifdef DEBUG
      orzeach(p);
      #endif
    } else {
      int l = *p.lower_bound(x);
      int r = *--p.upper_bound(y+1);
      #ifdef DEBUG
      orz(l);
      orz(r);
      #endif
      if (l > r) ans = (r-l+1ll)*(r-l+2ll)/2;
      else ans = tree.query(l+1, r) + (l-x)*(l-x+1ll)/2 + (y-r+1ll)*(y-r+2ll)/2;
      cout << ans << '\n';
    }
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
5 6
3 1 4 1 5
2 2 5
2 1 3
1 4 4
2 2 5
1 2 6
2 2 5

6
4
10 [3 1 4 4 5]
7  [3 6 4 4 5]
*/