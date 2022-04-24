/*
 * @Author: Kaizyn
 * @Date: 2022-04-24 08:19:52
 * @LastEditTime: 2022-04-24 08:59:34
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
const int N = 4e2 + 7;

constexpr char dc[] = "WNES";
constexpr int dir[] = {0, -1, 0, 1, 0};

int n, m, ex, ey;
vector<pii> stk;
char a[N][N];
int visa[N][N], visb[N][N], step[N][N];
string str;

void dfs(int x, int y, int d) {
  ex = x; ey = y;
  visb[x][y] = 1;
  if (visa[x / 2][y / 2] == 0) {
    visa[x / 2][y / 2] = 1;
    stk.emplace_back(x / 2, y / 2);
  }
  for (int i = 0, nx, ny; i < 4; ++i, d = (d + 3) % 4) {
    nx = x + dir[d];
    ny = y + dir[d + 1];
    if (nx < 0 || nx >= 2 * n || ny < 0 || ny >= 2 * m || a[nx / 2][ny / 2] == '#' || visb[nx][ny]) continue;
    if (nx / 2 == x / 2 && ny / 2 == y / 2) continue;
    if (visa[nx / 2][ny / 2]) continue;
    str += dc[d];
    if (++step[x / 2][y / 2] == 4) stk.pop_back();
    dfs(nx, ny, d);
  }
  for (int i = 0, nx, ny; i < 4; ++i, d = (d + 3) % 4) {
    nx = x + dir[d];
    ny = y + dir[d + 1];
    if (nx < 0 || nx >= 2 * n || ny < 0 || ny >= 2 * m || a[nx / 2][ny / 2] == '#' || visb[nx][ny]) continue;
    if (nx / 2 != x / 2 || ny / 2 != y / 2) {
      if (stk.size() < 2u) continue;
      if (nx / 2 != stk.end()[-2].first || ny / 2 != stk.end()[-2].second) continue;
    }
    if (++step[x / 2][y / 2] == 4) stk.pop_back();
    str += dc[d];
    dfs(nx, ny, d);
  }
}

inline void solve() {
  stk.clear();
  str = "";
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < 2 * m; ++j) {
      visa[i][j] = visb[i][j] = step[i][j] = 0;
    }
  }
  dfs(0, 0, 3);
  for (int d = 0, nx, ny; d < 4; ++d) {
    nx = ex + dir[d];
    ny = ey + dir[d + 1];
    if (nx == 0 && ny == 0) str += dc[d];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '*' && visa[i][j] == 0) {
        str = "IMPOSSIBLE";
        return;
      }
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T;
  // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    cout << "Case #" << t << ": " << str << '\n';
    // printf("Case #%d: %lld\n", t, solve());
  }
  return 0;
}