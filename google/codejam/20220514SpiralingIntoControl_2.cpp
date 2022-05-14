/*
 * @Author: Kaizyn
 * @Date: 2022-05-14 22:37:17
 * @LastEditTime: 2022-05-14 23:21:37
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
const int N = 1e4 + 7;
const int dir[] = {0,1,0,-1,0};

int n, k;

inline void solve() {
  cin >> n >> k;
  /*
  a[n / 2][n / 2] = n * n;
  for (int cen = 1, x = 0, y = 0, id = 1; cen <= n; ++cen) {
    for (int d = 0; d < 4; ++d) {
      for (int i = 0; i < n - cen; ++i) {
        a[x][y] = id++;
        x += dir[d];
        y += dir[d + 1];
      }
    }
  }
  */
  int dis = n * n - 1 - k;
  vector<pii> ans;
  for (int cen = n - 1, base = 0, i = n * 4 - 6; cen > 0; cen -= 2) {
    for (int j = 1, flag = 1; j <= 4; ++j, i -= 2, base += cen) {
      if (flag && dis >= i && i) {
        dis -= i;
        ans.emplace_back(base + 2, base + 3 + i);
        flag = 0;
      }
    }
  }
  if (dis) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << ans.size() << '\n';
    for (auto &i : ans) {
      cout << i.first << ' ' << i.second << '\n';
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
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}