/*
 * @Author: Kaizyn
 * @Date: 2020-08-27 16:16:35
 * @LastEditTime: 2020-08-27 17:08:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const long long INF = 1e18;
const int N = 53;
const int L = 23;

int n;
int c[N];
long long dp[2][N][L];
string s[2][N];

template <typename T, typename U>
inline void update(T &x, const U &y) {
  if (x == -1 || y < x) x = y;
}

inline bool is_palindrome(const string &str) {
  for (int i = 0, j = str.size()-1; i < j; ++i, --j)
    if (str[i] != str[j]) return false;
  return true;
}

long long dfs(int rev, int id, int pos) {
  if (~dp[rev][id][pos]) return dp[rev][id][pos];
  if (is_palindrome(s[rev][id].substr(pos))) return dp[rev][id][pos] = 0;
  dp[rev][id][pos] = INF; // dead for loop
  long long res = -1;
  int lk = s[rev][id].size();
  for (int i = 1, j, k, lj; i <= n; ++i) {
    lj = s[rev^1][i].size();
    for (j = 0, k = pos; j < lj && k < lk; ++j, ++k) {
      if (s[rev^1][i][j] != s[rev][id][k]) break;
    }
    if (j == lj && k == lk) {
      update(res, c[i]);
    } else if (j == lj) {
      if (~dfs(rev, id, k)) update(res, c[i]+dp[rev][id][k]);
    } else if (k == lk) {
      if (~dfs(rev^1, i, j)) update(res, c[i]+dp[rev^1][i][j]);
    }
  }
  return dp[rev][id][pos] = res;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[0][i] >> c[i];
    s[1][i] = s[0][i];
    reverse(s[1][i].begin(), s[1][i].end());
  }
  long long res = -1;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    // if (is_palindrome(s[0][i])) update(res, c[i]);
    if (~dfs(0, i, 0)) update(res, c[i]+dp[0][i][0]);
  }
  cout << res << endl;
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