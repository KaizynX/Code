/*
 * @Author: Kaizyn
 * @Date: 2022-06-11 20:13:32
 * @LastEditTime: 2022-06-11 20:22:55
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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e5 + 7;

int n, m;
int s[N], x[N];
ll a[N];
map<ll, int> cnt;

inline void solve() {
  cin >> n >> m;
  a[1] = 0;
  for (int i = 1; i < n; ++i) {
    cin >> s[i];
    a[i + 1] = s[i] - a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> x[i];
    for (int j = 1; j <= n; ++j) {
      ll d = (j & 1) ? x[i] - a[j] : a[j] - x[i];
      cnt[d]++;
    }
  }
  int ans = 0;
  #ifdef DEBUG
  int sum = 0;
  #endif
  for (auto &p : cnt) {
    #ifdef DEBUG
    cout << p.first << ' ' << p.second << '\n';
    sum += p.second;
    #endif
    ans = max(ans, p.second);
  }
  #ifdef DEBUG
  orz(sum);
  assert(sum == n * m);
  #endif
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