/*
 * @Author: Kaizyn
 * @Date: 2022-03-12 11:21:55
 * @LastEditTime: 2022-03-12 13:17:01
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

int n, m;
int a[N], p[N];
vector<pii> ans;
#ifdef DEBUG
set<pii> vis;
#endif

void f(int x, int y) {
  swap(a[x], a[y]);
  ans.emplace_back(x, y);
  #ifdef DEBUG
  cout << x << "->" << y << '\n';
  if (vis.count({x, y}) || vis.count({y, x})) {
    cerr << "wrong answer!\n";
  }
  vis.insert({x, y});
  #endif
}

void my_swap(int x, int y) {
  f(x, n + 1);
  f(y, n + 2);
  f(y, n + 1);
  f(x, n + 2);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]] = i;
  }
  if (is_sorted(a + 1, a + n + 1)) return cout << "0 0\n", void();
  a[n + 1] = n + 1;
  a[n + 2] = n + 2;
  m = 2;
  for (int i = 1; i <= n; ++i) if (i != a[i]) {
    f(i, n + 1);
    while (a[a[n + 1]] != i) {
      f(a[n + 1], n + 1);
    }
    f(a[n + 1], n + 2);
    f(i, n + 2);
    f(a[n + 1], n + 1);
  }
  if (a[n + 1] != n + 1) f(n + 1, n + 2);
  cout << m << ' ' << ans.size() << '\n';
  for (auto &pr : ans) cout << pr.first << ' ' << pr.second << '\n';
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
3
2 3 1
*/