/*
 * @Author: Kaizyn
 * @Date: 2021-10-13 14:15:47
 * @LastEditTime: 2021-10-13 14:28:36
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
const int N = 1e5+7;

int n, m;
ll fac[N]; // i > 2 fac[i] = i!/2

inline void solve() {
  fac[2] = 1;
  for (int i = 3; i <= n; ++i) fac[i] = fac[i-1]*i%m;
  ll ans = 0, cnt2 = 1;
  for (int i = 0; n-i*2 > 2; ++i) {
    ans += cnt2*fac[n-i*2-1]%m;
    cnt2 = (n-i*2)*(n-i*2-1ll)/2%m*cnt2%m;
  }
  cout << ans%m << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  while (cin >> n >> m) solve();
  return 0;
}