/*
 * @Author: Kaizyn
 * @Date: 2020-07-16 13:17:43
 * @LastEditTime: 2020-07-16 15:24:30
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 9+2;

int n, u, ans;
int a[N][N];
unordered_map<int, int> dp[2];

inline int get_bit(const int &state) {
  int bit = 0;
  for (int k = 0; k <= n; ++k) bit |= (state>>k*3)%8;
  return bit;
}

inline void update_ans(const int &state, const int &val) {
  if (__builtin_popcount(get_bit(state)) == 1) ans = max(ans, val);
}

inline void insert(const int &state, const int &val) {
  if (!dp[u].count(state)) dp[u].insert(state, val);
  else dp[u][state] = max(dp[u][statte], val);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  int base = (1<<3*n+3)-1;
  dp[u = 0].clear();
  dp[u][0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[u ^= 1].clear();
    for (const auto &p : dp[u^1]) dp[u].insert({(p.first<<3)&base, p.second});
    for (int j = 1; j <= n; ++j) {
      dp[u ^= 1].clear();
      for (const auto &p : dp[u^1]) {
        int state = p.first, val = p.second;
        cout << val << endl;
        int b1 = (state>>j*3-3)%8, b2 = (state>>j*3)%8;
        // not choose this grid
        if (get_bit(state) == get_bit(state-(1<<j*3-3)*b1-(1<<j*3)*b2))
          dp[u][state-(1<<j*3-3)*b1-(1<<j*3)*b2] += val;
        // choose this grid
        if (!b1 && !b2) {
          int nex = 1, bit = get_bit(state);
          while ((bit>>nex)&1) ++nex;
          dp[u][state+(1<<j*3-3)*nex+(1<<j*3)*nex] += val+a[i][j];
        } else if (!b1 && b2) {
          dp[u][state+(1<<j*3-3)*b2] += val+a[i][j];
        } else if (b1 && !b2) {
          dp[u][state+(1<<j*3)*b1] = val+a[i][j];
        } else if (b1 == b2) {
          dp[u][state] += val+a[i][j];
        } else if (b1 != b2) {
          if (b1 > b2) swap(b1, b2);
          for (int k = 0; k < n; ++k) {
            if ((state>>k*3)%8 == b2) {
              state += (1<<k*3)*(b1-b2);
            }
          }
          dp[u][state] += val+a[i][j];
        }
      }
    }
  }
  for (const auto &p : dp[u]) update_ans(p.first, p.second);
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}