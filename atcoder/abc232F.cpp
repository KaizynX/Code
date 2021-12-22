/*
 * @Author: Kaizyn
 * @Date: 2021-12-19 20:45:31
 * @LastEditTime: 2021-12-19 20:58:00
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
// const int INF = 0x3f3f3f3f;
const ll INF = 2e18;
const int N = 18;

int n;
ll x, y;
int a[N], b[N];
ll dp[1<<N];

int cost(int bit, int i) {
  return i - __builtin_popcount(bit & ((1 << i) - 1));
}

inline void solve() {
  cin >> n >> x >> y;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int used = 1, num; used < 1<<n; ++used) {
    dp[used] = INF;
    num = __builtin_popcount(used);
    for (int i = 0, last; i < n; ++i) if ((used >> i) & 1) {
      last = used ^ (1 << i);
      dp[used] = min(dp[used], dp[last] + y * cost(last, i) + x * abs(a[i] - b[num - 1]));
    }
  }
  cout << dp[(1 << n) - 1] << '\n';
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