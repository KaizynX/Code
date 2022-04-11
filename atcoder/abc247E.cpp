/*
 * @Author: Kaizyn
 * @Date: 2022-04-10 20:07:52
 * @LastEditTime: 2022-04-10 20:12:52
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

int n, x, y;
int a[N];
vector<int> px, py, pz;

inline void solve() {
  cin >> n >> x >> y;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    if (a == x) {
      px.emplace_back(i);
    }
    if (a == y) {
      py.emplace_back(i);
    }
    if (a < y || a > x) {
      pz.emplace_back(i);
    }
  }
  px.emplace_back(n + 1);
  py.emplace_back(n + 1);
  pz.emplace_back(n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int qx = *lower_bound(px.begin(), px.end(), i);
    int qy = *lower_bound(py.begin(), py.end(), i);
    int qz = *lower_bound(pz.begin(), pz.end(), i);
    #ifdef DEBUG
    orz(qx);
    orz(qy);
    orz(qz);
    #endif
    if (qx > n || qy > n || qx > qz || qy > qz) continue;
    ans += qz - max(qx, qy);
  }
  cout << ans << '\n';
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