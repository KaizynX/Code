/*
 * @Author: Kaizyn
 * @Date: 2022-04-24 07:55:55
 * @LastEditTime: 2022-04-24 08:16:28
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
const int N = 2e2 + 7;

constexpr char dc[] = "WNES";
constexpr int dir[] = {0, -1, 0, 1, 0};

int n, m;
char a[N][N];
int vis[N][N];
string str;

void dfs(int x, int y, int d) {
  vis[x][y] = 1;
  for (int i = 0, nx, ny; i < 4; ++i, d = (d + 3) % 4) {
    nx = x + dir[d];
    ny = y + dir[d + 1];
    str += dc[d];
    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
    str += dc[d];
    dfs(nx, ny, d);
    str += dc[(d + 2) % d];
  }
}

inline void solve() {
  str = "";
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i] + 1);
    memset(vis + 1, 0, sizeof(int) * m);
  }
  dfs(1, 1, 3);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == '*' && vis[i][j] == 0) {
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
    cout << "Case %" << t << ": " << str << '\n';
    // printf("Case #%d: %lld\n", t, solve());
  }
  return 0;
}