/*
 * @Author: Kaizyn
 * @Date: 2021-11-01 12:32:29
 * @LastEditTime: 2021-11-01 12:36:35
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
int a[N], cnt[32];

inline void solve() {
  cin >> n;
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 0; j < 30; ++j) {
      cnt[j] += (a[i]>>j)&1;
    }
  }
  int g = 0;
  for (int i = 0; i < 30; ++i) {
    g = __gcd(g, cnt[i]);
  }
  for (int i = 1; i <= n; ++i) {
    if (g == 0 || g%i == 0) cout << i << " ";
  }
  cout << '\n';
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