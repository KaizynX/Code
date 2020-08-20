/*
 * @Author: Kaizyn
 * @Date: 2020-08-09 22:53:50
 * @LastEditTime: 2020-08-09 23:15:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n, m;
vector<string> a;
int dp[N][8], check[4][8][8];

void shift() {
  vector<string> b;
  swap(n, m);
  b.resize(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      b[i] += a[j][i];
    }
  }
  swap(a, b);
#ifdef DEBUG
  cout << "a:***********\n";
  for (int i = 0; i < n; ++i) cout << a[i] << endl;
  cout << "a:***********\n";
#endif
}

int differ(const string &s, const int &x) {
  int res = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    res += s[i]-'0' != (x>>i&1);
  }
  return res;
}

inline int solve() {
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n >= 4 && m >= 4) return -1;
  if (n == 1 || m == 1) return 0;
  if (n < m) shift();
  // make n >= m, m <= 3
  memset(dp, 0x3f, sizeof dp);
  for (int j = 0; j < 1<<m; ++j) dp[0][j] = differ(a[0], j);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 1<<m; ++j) {
      for (int k = 0; k < 1<<m; ++k) if (check[m][j][k]) {
        dp[i][j] = min(dp[i][j], dp[i-1][k]+differ(a[i], j));
      }
    }
  }
  int res = n*m;
  for (int j = 0; j < 1<<m; ++j) res = min(res, dp[n-1][j]);
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      check[2][i][j] = (__builtin_popcount(i)+__builtin_popcount(j))&1;
#ifdef DEBUG
      cout << check[2][i][j] << " \n"[j==3];
#endif
    }
  }
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      check[3][i][j] =
          (__builtin_popcount(i&3)+__builtin_popcount(j&3))&1 &&
          (__builtin_popcount(i>>1)+__builtin_popcount(j>>1))&1;
#ifdef DEBUG
      cout << check[3][i][j] << " \n"[j==7];
#endif
    }
  }
  cout.flush();
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}