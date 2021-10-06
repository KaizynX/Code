/*
 * @Author: Kaizyn
 * @Date: 2021-10-06 12:05:56
 * @LastEditTime: 2021-10-06 12:19:51
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
const int N = 1e7+7;
const int K = 1e2;
typedef unsigned long long ull;

unsigned x, y, z;
unsigned tang() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

int n;
unsigned a[N];

inline ull solve() {
  cin >> n >> x >> y >> z;
  for (int i = 0; i < n; ++i) a[i] = tang();
  int m = max(n-K, 0);
  nth_element(a, a+m, a+n);
  ull ans = 0;
  // for (int i = m; i < n; ++i) {
  for (unsigned *i = a+m; i < a+n; ++i) {
    for (unsigned *j = a+m; j < i; ++j) {
      ans = max(ans, (ull)*i/__gcd(*i, *j)**j);
    }
  }
  return ans;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << '\n';
  }
  return 0;
}