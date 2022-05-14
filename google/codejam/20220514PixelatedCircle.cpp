/*
 * @Author: Kaizyn
 * @Date: 2022-05-14 23:05:55
 * @LastEditTime: 2022-05-14 23:48:47
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
const int N = 1e5 + 7;
const int R = 50;

bool vis[N];
ll ans[N], pw[N];

inline void solve() {
  for (int i = 1; i < N; ++i) pw[i] = 1ll * i * i;
  for (int x = 1, y = R; x <= R; ++x) {
    while (pw[y] + pw[x] > pw[R]) --y;
    memset(vis, 0, y + 1);
    for (int r = x; r <= R; ++r) {
      vis[(int)sqrt(pw[r] - pw[x])] = true;
    }
    for (int i = 1; i <= y; ++i) {
      if (!vis[i]) ++ans[R];
    }
    /*
    int last = 0, tail = 1;
    ll x2 = 1ll * x * x;
    for (int r = x; r <= R; ++r) {
      ll r2 = 1ll * r * r;
      int y = sqrt(r2 - x2);
      if (y > last + 1) ++ans[r];
      while (1ll * tail * tail + x2 <= r2) ++tail;
      if (tail > last + 1) ++ans[r];
      last = y;
      cout << y << " \n"[r == R];
    }
    */
  }
  cout << "{";
  for (int i = 1; i <= R; ++i) {
    cout << ans[i] << ",}"[i == R];
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