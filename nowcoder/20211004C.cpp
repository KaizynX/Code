/*
 * @Author: Kaizyn
 * @Date: 2021-10-04 13:29:35
 * @LastEditTime: 2021-10-04 14:15:03
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
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
const int K = 16;

ll a[N], s[N];

inline ll solve() {
  ll n, ans = 0, x, y;
  cin >> n;
  if (n <= K) return s[n];
#ifdef DEBUG
  cout << s[n] << ' ';
#endif
  ans = s[K];
  for (x = K, y = a[K/2]; x*2 <= n; x *= 2, ++y) {
    ans = (ans+y*x)%MOD;
  }
  n -= x;
  ll cnt = n/4*2+(n%4==3);
  ans = (ans+(y-1)*(n-cnt)+(y+1)*cnt)%MOD;
  return ans;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  s[1] = a[1] = 0;
#ifdef DEBUG
  for (int i = 2; i < N; ++i) {
#else
  for (int i = 2; i <= K; ++i) {
#endif
    a[i] = a[i/2]+(i*(i+1ll)/2%2 ? -1 : 1);
    printf("a[%d]=%lld\n", i, a[i]);
    s[i] = s[i-1]+abs(a[i]);
    // printf("s[%d]=%lld\n", i, s[i]);
  }
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}