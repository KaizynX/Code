/*
 * @Author: Kaizyn
 * @Date: 2021-12-27 23:54:39
 * @LastEditTime: 2021-12-28 00:08:10
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
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n;
ll k;
ll a[N];

inline void solve() {
  cin >> n >> k;
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  ll ans = sum, tmp = 0; // tmp = presum[i - 1]
  for (int i = 1; i <= n; ++i) {
    // a[n] -= b
    // do a[1 ~ i - 1] = a[n]
    // (i - 1) * (a[n] - b) + sum - tmp - b <= k
    // -i * b <= k - sum + tmp - (i - 1) * a[n]
    // b >= ((i - 1) * a[n] + sum - k - tmp) / i
    ll b = (i - 1) * a[n] + sum - k - tmp;
    if (b <= 0) b = 0;
    else b = (b + i - 1) / i;
    ans = min(ans, b + i - 1);
    tmp += a[i];
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