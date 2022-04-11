/*
 * @Author: Kaizyn
 * @Date: 2022-04-10 20:00:59
 * @LastEditTime: 2022-04-10 20:04:09
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

int n, q;
deque<pii> a;

inline void solve() {
  cin >> q;
  for (int i = 1, op, x, c; i <= q; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> x >> c;
      a.push_back({x, c});
    } else {
      cin >> c;
      ll ans = 0;
      while (c) {
        int x = a.front().first;
        int cc = a.front().second;
        a.pop_front();
        int t = min(cc, c);
        c -= t;
        cc -= t;
        if (cc) a.push_front({x, cc});
        ans += 1ll * t * x;
      }
      cout << ans << '\n';
    }
  }
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