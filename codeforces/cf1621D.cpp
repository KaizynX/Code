/*
 * @Author: Kaizyn
 * @Date: 2022-01-03 23:37:16
 * @LastEditTime: 2022-01-04 00:38:59
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
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 5e2+7;

int n;
int c[N][N];
ll col[N][N], row[N][N];

template <typename T>
void MIN(T &x, const T &y) {
  if (y < x) x = y;
}

ll su(int x, int y) {
  return col[x][y];
}

ll sd(int x, int y) {
  return col[2 * n][y] - col[x - 1][y];
}

ll sl(int x, int y) {
  return row[x][y];
}

ll sr(int x, int y) {
  return row[x][2 * n] - row[x][y - 1];
}

inline void solve() {
  cin >> n;
  ll base = 0, ans = INF;
  for (int i = 1; i <= 2 * n; ++i) {
    for (int j = 1; j <= 2 * n; ++j) {
      cin >> c[i][j];
      if (i > n && j > n) base += c[i][j], c[i][j] = 0;
      row[i][j] = row[i][j - 1] + c[i][j];
      col[i][j] = col[i - 1][j] + c[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x, y; j <= n; ++j) {
      x = i; y = n + j;
      MIN(ans, su(x, y) + sl(x, y) - c[x][y]);
      MIN(ans, su(x, y) + sr(x, y) - c[x][y]);
      MIN(ans, sd(x, y) + sl(x, y) - c[x][y]);
      MIN(ans, sd(x, y) + sr(x, y) - c[x][y]);
      x = n + i; y = j;
      MIN(ans, su(x, y) + sl(x, y) - c[x][y]);
      MIN(ans, su(x, y) + sr(x, y) - c[x][y]);
      MIN(ans, sd(x, y) + sl(x, y) - c[x][y]);
      MIN(ans, sd(x, y) + sr(x, y) - c[x][y]);
    }
  }
  cout << ans + base << '\n';
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