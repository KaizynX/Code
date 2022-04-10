/*
 * @Author: Kaizyn
 * @Date: 2022-04-09 19:54:38
 * @LastEditTime: 2022-04-09 20:08:05
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
const int N = 4e5 + 7;

int n, k;
int a[N];
vector<pii> stk;

inline void solve() {
  cin >> n >> k;
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i <= k) continue;
    if (stk.empty() || a[i] > stk.back().first) {
      stk.emplace_back(a[i], i);
    }
  }
  for (int i = 1; i <= k; ++i) {
    auto it = upper_bound(stk.begin(), stk.end(), pii{a[i] + 1, 0});
    if (it == stk.end()) continue;
    int val = it->second - i;
    ans = ~ans ? min(ans, val) : val;
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