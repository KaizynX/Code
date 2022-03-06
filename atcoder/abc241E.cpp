/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 20:12:50
 * @LastEditTime: 2022-02-26 20:33:42
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

int n;
int a[N];
int seq[N], vis[N];
ll k;
ll val[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memset(vis, -1, sizeof(int) * n);
  int m = 0;
  val[0] = 0;
  vis[0] = 0;
  while (k--) {
    val[m + 1] = val[m] + a[val[m] % n];
    int y = val[++m] % n;
    if (~vis[y]) break;
    vis[y] = m;
  }
  #ifdef DEBUG
  orz(m);
  orzarr(vis, n);
  orzarr(val, m + 1);
  for (int i = 0; i <= m; ++i) {
    cout << val[i] % n << " \n"[i == m];
  }
  #endif
  if (k < 0) {
    cout << val[m] << '\n';
    return;
  }
  // vis[m], m
  int last = vis[val[m] % n];
  int gap = m - last;
  ll dis = val[m] - val[last];
  #ifdef DEBUG
  orz(gap);
  orz(dis);
  #endif
  ll ans = val[m] + k / gap * dis
      + val[last + k % gap] - val[last];
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