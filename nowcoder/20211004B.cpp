/*
 * @Author: Kaizyn
 * @Date: 2021-10-04 16:16:54
 * @LastEditTime: 2021-10-04 16:32:55
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

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e3+7;

struct Node {
  int l, r, w;
  bool operator <(const Node &b) const {
    // return pii{l, r} < pii{b.l, b.r};
    return r < b.r;
  }
};

int n, m;
Node a[N];
int dp[N][N], mn[N][N];

template <typename T>
void MIN(T &x, T y) {
  if (x == -1 || y < x) x = y;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].l >> a[i].r >> a[i].w;
  }
  a[0] = Node{0, 0, 0};
  sort(a+1, a+n+1);
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    memset(dp[i], -1, sizeof(int)*(m+1));
    for (int j = i-1; j >= 0; --j) {
      if (a[j].r < a[i].l-1) break;
      int val = a[j].r+1 == a[i].l ? max(a[i].w, a[j].w) : a[i].w+a[j].w;
      if (~mn[j][a[i].l-1]) MIN(dp[i][a[j].r], max(mn[j][a[i].l-1], val));
    }
    memcpy(mn[i], dp[i], sizeof(int)*(m+1));
    for (int j = 1; j <= m; ++j) {
      if (~mn[i][j-1]) MIN(mn[i][j], mn[i][j-1]);
    }
    #ifdef DEBUG
    orzarr(dp[i], m+1);
    orzarr(mn[i], m+1);
    #endif
    if (a[i].r == m) MIN(ans, mn[i][m]);
  }
  cout << ans << '\n';
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