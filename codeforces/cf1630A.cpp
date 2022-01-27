/*
 * @Author: Kaizyn
 * @Date: 2022-01-27 22:33:20
 * @LastEditTime: 2022-01-27 23:04:10
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
const int N = (1 << 16) + 7;

int n, k;

inline void solve() {
  cin >> n >> k;
  // ll sum = (n - 1ll) * n / 2 - k;
  // 0 (n - 1 - k)
  if (k == n - 1) {
    if (n == 4) {
      cout << -1 << '\n';
      return;
    } else {
      cout << "3 " << n - 1 << '\n';
      cout << "0 " << n - 4 << '\n';
      cout << "2 1\n";
      cout << n - 2 << ' ' << n - 3 << '\n';
      for (int i = 4; i < n / 2; ++i) {
        cout << i << ' ' << n - 1 - i << '\n';
      }
    }
    return;
  }
  cout << "0 " << (n - 1 - k) << '\n';
  if (k) cout << n - 1 << ' ' << k << '\n';
  for (int i = 1; i < n / 2; ++i) {
    if (i != k && i != n - 1 - k) {
      cout << i << ' ' << n - 1 - i << '\n';
    }
  }
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