/*
 * @Author: Kaizyn
 * @Date: 2020-07-16 10:52:48
 * @LastEditTime: 2020-07-16 11:50:11
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 14;

int n, m;
int a[N][N];
unordered_map<int, long long> dp[2];

inline void solve() {
  int ex, ey, cnt = 0;
  memset(a, 0, sizeof a);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      cnt += a[i][j];
      if (a[i][j]) ex = i, ey = j;
    }
  }
  if (!cnt) return cout << 1 << endl, void();
  int u = 0, base = (1<<2*m+3)-1;
  long long res = 0;
  dp[u].clear();
  dp[u][0] = 1;
  for (int i = 1; i <= n; ++i) {
    // add a null b1
    dp[u ^= 1].clear();
    for (const auto &p : dp[u^1]) dp[u].insert({(p.first<<2)&base, p.second});
    for (int j = 1; j <= m; ++j) {
      dp[u ^= 1].clear();
      for (const auto &p : dp[u^1]) {
        int bit = p.first;
        long long val = p.second;
        // b1 right b2 down
        int b1 = (bit>>j*2-2)%4, b2 = (bit>>j*2)%4;
        if (!a[i][j]) {
          if (!b1 && !b2) dp[u][bit] += val;
        } else if (!b1 && !b2) {
          if (a[i+1][j] && a[i][j+1]) dp[u][bit+(1<<j*2-2)+(1<<j*2+1)] += val;
        } else if (!b1 && b2) {
          if (a[i][j+1]) dp[u][bit] += val;
          if (a[i+1][j]) dp[u][bit+(1<<j*2-2)*b2-(1<<j*2)*b2] += val;
        } else if (b1 && !b2) {
          if (a[i+1][j]) dp[u][bit] += val;
          if (a[i][j+1]) dp[u][bit-(1<<j*2-2)*b1+(1<<j*2)*b1] += val;
        } else if (b1 == 1 && b2 == 1) {
          // dp[u][bit-(1<<j*2-2)-(1<<j*2)-(1<<k*2)] += val;
          for (int k = j+1, t = 1; k <= m; ++k) {
            if ((bit>>k*2)%4 == 1) ++t;
            if ((bit>>k*2)%4 == 2) --t;
            if (!t) { dp[u][bit-(1<<j*2-2)-(1<<j*2)-(1<<k*2)] += val; break; }
          }
        } else if (b1 == 2 && b2 == 2) {
          // dp[u][bit-(1<<j*2-1)-(1<<j*2+1))] += val;
          for (int k = j-2, t = 1; k >= 0; --k) {
            if ((bit>>k*2)%4 == 1) --t;
            if ((bit>>k*2)%4 == 2) ++t;
            if (!t) { dp[u][bit-(1<<j*2-1)-(1<<j*2+1)+(1<<k*2)] += val; break; }
          }
        } else if (b1 == 2 && b2 == 1) {
          dp[u][bit-(1<<j*2-1)-(1<<j*2)] += val;
        } else if (b1 == 1 && b2 == 2) {
          if (i == ex && j == ey) res += val;
          else dp[u][bit-(1<<j*2-2)-(1<<j*2+1)] += val;
        }
      }
    }
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}