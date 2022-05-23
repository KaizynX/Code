/*
 * @Author: Kaizyn
 * @Date: 2022-05-23 22:42:48
 * @LastEditTime: 2022-05-23 23:56:29
 */
#include <bits/stdc++.h>

// #define DEBUG

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
const ll INF = 1e18;

#define _log(x) (31-__builtin_clz(x))
const int N = 2e5 + 7;
const int LOGN = _log(N) + 2;
const int dirx[] = {1, 0};
const int diry[] = {0, 1};

int n, m;
int dx[2][N], dy[2][N];
ll dis[2][2][LOGN][N];
// dis[i][j][k][l] from l's i door to (l-(1<<k)+1)'s j door

int calc_dis(int xi, int yi, int xj, int yj) {
  #ifdef DEBUG
  // cerr << "calc_dis: " << abs(xi - xj) + abs(yi - yj) << '\n';
  #endif
  return abs(xi - xj) + abs(yi - yj);
}

/*
int calc_dis(int x, int xi, int y, int yi) {
  return abs(dx[xi][x] - dx[yi][y]) + abs(dy[xi][x] - dy[yi][y]);
}
*/

int calc(int x, int di, int dj) {
  // return calc_dis(x, di, x - 1, dj);
  // if (di == dj) return 0;
  return calc_dis(dx[di][x], dy[di][x], dx[dj][x - 1] + dirx[dj], dy[dj][x - 1] + diry[dj]);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    for (int j : {0, 1}) {
      cin >> dx[j][i] >> dy[j][i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int di : {0, 1}) {
      dis[di][di][0][i] = 1;
      dis[di][di ^ 1][0][i] = INF;
    }
    for (int j = 0; (1 << (j + 1)) <= i; ++j) {
      for (int di : {0, 1}) for (int dj : {0, 1}) {
        ll &cur = dis[di][dj][j + 1][i];
        cur = inf<ll>;
        for (int dk : {0, 1}) for (int dl : {0, 1}) {
          cur = min(cur, calc(i - (1 << j), dk, dl)
              + dis[di][dk][j][i] + dis[dl][dj][j][i - (1 << j)]);
        }
      }
    }
  }
  cin >> m;
  ll tmp[2][2][2];
  for (int _ = m, bx, by, ex, ey, bl, el; _; --_) {
    cin >> bx >> by >> ex >> ey;
    bl = max(bx, by);
    el = max(ex, ey);
    if (bl > el) {
      swap(bl, el);
      swap(bx, ex);
      swap(by, ey);
    }
    if (el == bl) {
      cout << calc_dis(bx, by, ex, ey) << '\n';
      continue;
    }
    memset(tmp, 0, sizeof tmp);
    int cur = 0;
    for (int i = _log(el - bl), u = el, fir = 1; i >= 0; --i) if ((1 << i) <= u - bl) {
      for (int di : {0, 1}) for (int dj : {0, 1}) {
        if (fir) {
          tmp[cur ^ 1][di][dj] = dis[di][dj][i][u];
          continue;
        }
        ll& now = tmp[cur ^ 1][di][dj];
        now = inf<ll>;
        for (int dk : {0, 1}) for (int dl : {0, 1}) {
          now = min(now, calc(u, dk, dl)
              + tmp[cur][di][dk] + dis[dl][dj][i][u]);
        }
      }
      fir = 0;
      cur ^= 1;
      u -= 1 << i;
    }
    ll ans = inf<ll>;
    for (int di : {0, 1}) for (int dj : {0, 1}) {
      #ifdef DEBUG
      cout << "(" << di << "," << dj << ") "
           << tmp[cur][di][dj] << ","
           << calc_dis(bx, by, dx[dj][bl], dy[dj][bl]) << ","
           << calc_dis(ex, ey, dx[di][el - 1] + dirx[di], dy[di][el - 1] + diry[di]) << '\n';
      #endif
      ans = min(ans, tmp[cur][di][dj]
          + calc_dis(bx, by, dx[dj][bl], dy[dj][bl])
          + calc_dis(ex, ey, dx[di][el - 1] + dirx[di], dy[di][el - 1] + diry[di]));
    }
    cout << ans << '\n';
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