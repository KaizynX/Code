/*
 * @Author: Kaizyn
 * @Date: 2022-01-22 20:46:10
 * @LastEditTime: 2022-01-22 21:01:14
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
const int N = 2e5 + 7;

int n, m, k;
int a[N], b[N];

inline ll solve() {
  cin >> n >> m >> k;
  int va = m * (k - 1ll) % k, vb = n * (k - 1ll) % k;
  ll sa = 0, sb = 0;
  for (int i = 1, t; i <= n; ++i) {
    cin >> a[i];
    t = (va - a[i] + k) % k;
    sa += t;
  }
  for (int i = 1, t; i <= m; ++i) {
    cin >> b[i];
    t = (vb - b[i] + k) % k;
    sb += t;
  }
  if ((sa - sb) % k != 0) return -1;
  return (k - 1ll) * n * m - max(sa, sb);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}