/*
 * @Author: Kaizyn
 * @Date: 2021-08-28 14:04:25
 * @LastEditTime: 2021-08-28 14:34:09
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
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;
const int M = 55;

ll A, B, C, D, n;
ll ans, K1, K2;
vector<int> v[M];

inline int g(int x) {
  int ans = 0;
  while (x) {
    ans += x%10;
    x /= 10;
  }
  return ans;
}

void init() {
  for (int i = 1; i <= 1000000; ++i) {
    v[g(i)].emplace_back(i);
  }
}

inline void update(int x) {
  if (x > n) return;
  ll v = K1*x*x+K2*x;
  ans = min(ans, v);
  #ifdef DEBUG
  printf("f(%d)=%lld\n", x, v);
  #endif
}

inline void solve() {
  cin >> A >> B >> C >> D >> n;
  ans = 9e18;
  for (int g = 1; g < M; ++g) {
    K1 = A*g+B;
    K2 = C*g*g+D*g;
    // K1*x^2+K2*x
    if (v[g].size()) update(v[g][0]);
    auto it = upper_bound(v[g].begin(), v[g].end(), n);
    if (it != v[g].begin()) update(*(--it));
    if (K1 == 0) continue;
    ll P = -K2/(K1*2);
    int p = lower_bound(v[g].begin(), v[g].end(), P)-v[g].begin();
    for (int i = max(0, p-3); i < min((int)v[g].size(), p+3); ++i) {
      update(v[g][i]);
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  init();
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}