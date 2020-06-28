/*
 * @Author: Kaizyn
 * @Date: 2020-06-24 15:40:10
 * @LastEditTime: 2020-06-24 17:23:16
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n;
int w[N], l[N], dp[N][2];
long long s[N], e[N];

int win(const long long &si, const long long &ei) {
  if (ei%2) return si%2 != 1;
  if (si > ei/2) return si%2;
  if (si > ei/4) return 1;
  return win(si, ei/4);
}

int lose(const long long &si, const long long &ei) {
  if (si*2 > ei) return 1;
  return win(si, ei/2);
}

inline void solve() {
  cin >> n;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i] >> e[i];
    w[i] = win(s[i], e[i]);
    l[i] = lose(s[i], e[i]);
    if (dp[i-1][1]) { // the other start
      dp[i][1] |= w[i]^1;
      dp[i][0] |= l[i]^1;
    }
    if (dp[i-1][0]) {
      dp[i][1] |= w[i];
      dp[i][0] |= l[i];
    }
  }
  cout << dp[n][1] << " " << dp[n][0] << endl;
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