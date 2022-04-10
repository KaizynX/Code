/*
 * @Author: Kaizyn
 * @Date: 2022-04-09 10:39:04
 * @LastEditTime: 2022-04-09 11:26:38
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
const int N = 100;
using uint = unsigned;

int n, m;
vector<int> a[N], dp[N];
vector<vector<int>> b[N];

int calc_dis(const vector<int> &x, const vector<int> &y) {
  int ans = 0;
  for (unsigned i = 0; i < x.size() && i < y.size(); ++i) {
    if (x[i] != y[i]) break;
    ans = i + 1;
  }
  return x.size() + y.size() - 2 * ans;
}

inline int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    a[i].clear();
    b[i].clear();
    for (int j = 0, k; j < m; ++j) {
      cin >> k;
      while (k--) a[i].emplace_back(j);
    }
    do {
      b[i].emplace_back(a[i]);
    } while (next_permutation(a[i].begin(), a[i].end()));
  }
  b[0].assign({vector<int>()});
  b[n + 1].assign({vector<int>()});
  dp[0].assign({0});
  for (int i = 1; i <= n + 1; ++i) {
    dp[i].assign(b[i].size(), inf<int>);
    for (uint j = 0; j < b[i].size(); ++j) {
      for (uint k = 0; k < b[i - 1].size(); ++k) {
        dp[i][j] = min(dp[i][j], dp[i - 1][k] + calc_dis(b[i - 1][k], b[i][j]));
      }
    }
  }
  return dp[n + 1].front();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << '\n';
  }
  return 0;
}