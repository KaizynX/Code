/*
 * @Author: Kaizyn
 * @Date: 2022-05-21 19:59:27
 * @LastEditTime: 2022-05-21 20:13:00
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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e2 + 7;

int n;
int a[N][N];

inline void solve() {
  cin >> n;
  string s;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 0; j < 10; ++j) {
      int k = s[j] - '0';
      a[k][j]++;
    }
  }
  int ans = inf<int>;
  for (int i = 0; i < 10; ++i) {
    int cur = 0;
    for (int j = 0; j < 10; ++j) {
      cur = max(cur, (a[i][j] - 1) * 10 + j);
    }
    ans = min(ans, cur);
    #ifdef DEBUG
    cout << i << ' ' << cur << '\n';
    #endif
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