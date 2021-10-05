/*
 * @Author: Kaizyn
 * @Date: 2021-10-05 13:04:56
 * @LastEditTime: 2021-10-05 13:17:07
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
const ll INF = 2e18;
const int N = 5e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] = min(tr[i]+v, INF); }
  // void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res = min(res+tr[i], INF); return res; }
  // T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n;
ll k;
int a[N];
ll dp[N];
BinaryIndexedTree<ll> tree;

void discrete() {
  vector<int> v(a+1, a+n+1);
  v.emplace_back(0);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= n; ++i) {
    a[i] = v.end()-lower_bound(v.begin(), v.end(), a[i]);
  }
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  discrete();
  tree.init(n);
  for (int i = n; i; --i) {
    dp[i] = 1;
    if (a[i] > 1) dp[i] += tree.query(a[i]-1);
    tree.add(a[i], dp[i]);
  }
  #ifdef DEBUG
  orzarr(dp+1, n);
  #endif
  vector<int> ans;
  for (int i = 1, val = n+1; i <= n; ++i) {
    if (a[i] >= val) continue;
    if (k > dp[i]) {
      k -= dp[i];
    } else if (k) {
      --k;
      ans.emplace_back(i);
      val = a[i];
    }
  }
  if (k != 0) return cout << "-1\n", void();
  cout << ans.size() << '\n';
  for (int i : ans) cout << i << ' ';
  cout << '\n';
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