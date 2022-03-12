/*
 * @Author: Kaizyn
 * @Date: 2022-03-06 17:47:52
 * @LastEditTime: 2022-03-06 18:02:49
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e5 + 7;

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
vector<pii> p[N];
// vector<vector<int>> c;
BinaryIndexedTree<ll> cnt, sa, sm;

inline void solve() {
  cin >> n >> m;
  // c = vector<vector<int>>(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0, c; j < m; ++j) {
      // cin >> c[i][j];
      cin >> c;
      p[c].emplace_back(i + 1, j + 1);
    }
  }
  sa.init(m);
  sm.init(m);
  cnt.init(m);
  ll ans = 0;
  for (int c = 0; c < N; ++c) if (p[c].size()) {
    for (auto &pos : p[c]) {
      int x = pos.first;
      int y = pos.second;
      ans += sa.query(y, m) + cnt.query(y, m) * (x - y);
      if (y > 1) ans += sm.query(1, y - 1) + cnt.query(1, y - 1) * (x + y);
      cnt.add(y, 1);
      sa.add(y, -x + y);
      sm.add(y, -x - y);
    }
    for (auto &pos : p[c]) {
      int x = pos.first;
      int y = pos.second;
      cnt.add(y, -1);
      sa.add(y, x - y);
      sm.add(y, x + y);
    }
  }
  cout << ans << '\n';
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