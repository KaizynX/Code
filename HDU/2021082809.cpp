/*
 * @Author: Kaizyn
 * @Date: 2021-08-28 12:09:50
 * @LastEditTime: 2021-08-28 12:11:52
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

int n;
char s[N];
map<ll, int> cnt;

inline void solve() {
  scanf("%d%s", &n, s+1);
  cnt.clear();
  cnt[0] = 1;
  ll ans = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'U') {
      cur += 200000;
    } else if (s[i] == 'D') {
      cur -= 200000;
    } else if (s[i] == 'L') {
      cur += 1;
    } else {
      cur -= 1;
    }
    ans += cnt[cur];
    ++cnt[cur];
  }
  printf("%lld\n", ans);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}