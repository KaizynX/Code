/*
 * @Author: Kaizyn
 * @Date: 2022-05-14 23:48:33
 * @LastEditTime: 2022-05-15 00:27:18
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 15;

struct Node {
  int x, y;
  friend ll calc_dis(const Node& lhs, const Node& rhs) {
    return 1ll * (lhs.x - rhs.x) * (lhs.x - rhs.x)
         + 1ll * (lhs.y - rhs.y) * (lhs.y - rhs.y);
  }
};

int n;
pii dp[1<<10][1<<10];
ll dis[N][N];
Node a[N], b[N];

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  cin >> b[n].x >> b[n].y;
  for (int i = 0; i < n; ++i) {
    cin >> b[i].x >> b[i].y;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dis[i][j] = calc_dis(a[i], b[j]);
    }
  }
  for (int b = 0; b < (1 << n); ++b) {
    int k = __builtin_popcount(b);
    int s=(1<<k)-1;
    while(s<(1<<n)){
      dp[b][s] = pii{-1,-1};
      if (s == 0) break;
      int x=s&-s,y=s+x;
      s=((s&~y)/x>>1)|y; //这里有一个位反~
    }
  }
  dp[0][0] = pii{0, 0};
  for (int b = 0; b < (1 << n); ++b) {
    // 枚举n + 1个元素,大小为k的二进制子集
    int k = __builtin_popcount(b);
    int s=(1<<k)-1;
    while(s<(1<<n)){
      // cout << b << ' ' << s << '\n';
      if (dp[b][s].first != -1)
      for (int i = 0; i < n; ++i) if (((b >> i) & 1) == 0) {
        ll mn = inf<ll>;
        for (int j = 0; j <= n; ++j) if (((s >> j) & 1) == 0) {
          mn = min(mn, dis[i][j]);
        }
        for (int j = 0; j < n; ++j) if (((s >> j) & 1) == 0) {
          if (dis[i][j] != mn) continue;
          pii &to = dp[b ^ (1 << i)][s ^ (1 << j)];
          if (to.first != -1) continue;
          dp[b ^ (1 << i)][s ^ (1 << j)] = pii{i, j};
          #ifdef DEBUG
          cout << b << ' ' << s << " {"
              << (b ^ (1 << i)) << ' ' << (s ^ (1 << j)) << '}'
           << i << ' ' << j << '\n';
          #endif
        }
      }
      if (s == 0) break;
      int x=s&-s,y=s+x;
      s=((s&~y)/x>>1)|y; //这里有一个位反~
    }
  }
  #ifdef DEBUG
  for (int i = 0; i < (1 << n); ++i)
  for (int j = 0; j < (1 << n); ++j) {
    cout << i << ' ' << j << dp[i][j] << '\n';
  }
  #endif
  if (dp[(1 << n) - 1][(1 << n) - 1].first != -1) {
    cout << "POSSIBLE\n";
    vector<pii> ans;
    for (int _ = 0, i = (1 << n) - 1, j = (1 << n) - 1; _ < n; ++_) {
      ans.emplace_back(dp[i][j]);
      int tmp = dp[i][j].second;
      #ifdef DEBUG
      cout << i << ' ' << j << dp[i][j] << '\n';
      assert(~dp[i][j].first);
      assert(~dp[i][j].second);
      #endif
      i ^= 1 << dp[i][j].first;
      j ^= 1 << tmp;
    }
    reverse(ans.begin(), ans.end());
    for (auto &p : ans) cout << p.first + 1 << ' ' << p.second + 2 << '\n';
  } else {
    cout << "IMPOSSIBLE\n";
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