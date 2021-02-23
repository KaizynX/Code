/*
 * @Author: Kaizyn
 * @Date: 2021-02-15 16:52:14
 * @LastEditTime: 2021-02-15 17:24:39
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e2+7;
const int M = 10;

int n, m;
vector<int> v1, v2; // m = 10, size 60 2129
int a[N], dp[2][1<<20];

void init() {
  for (int i = 0; i < 1<<m; ++i) {
    int flag = 1;
    for (int j = 0, last = -6; j < m; ++j) if ((i>>j)&1) {
      if (j-last <= 2) flag = 0;
      last = j;
    }
    if (flag) v1.emplace_back(i);
  }
  for (int &i : v1) {
    for (int &j : v1) {
      if (i&j) continue;
      v2.emplace_back((i<<m)|j);
    }
  }
#ifndef ONLINE_JUDGE
  cout << v1.size() << ' ' << v2.size() << '\n';
#endif
}

template <typename T>
void update(T &x, const T &y) {
  if (y > x) x = y;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    static string str;
    cin >> str;
    for (int j = 0; j < m; ++j) {
      a[i] = a[i]*2+(str[j] == 'H');
    }
  }
  init();
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    memset(dp[i&1], -1, sizeof dp[0]);
    for (int &j : v1) { // i'th row is [j]
      if (j&a[i]) continue;
      for (int &k : v2) {
        if (dp[~i&1][k] == -1) continue;
        if (((k>>m)|(k&((1<<m)-1)))&j) continue;
        update(dp[i&1][(j<<m)|(k>>m)], dp[~i&1][k]+__builtin_popcount(j));
#ifndef ONLINE_JUDGE
        cout << i << ' ' << bitset<8>((j<<m)|(k>>m)) << ' ' << dp[i&1][(j<<m)|(k>>m)] << '\n';
#endif
      }
    }
  }
  int res = 0;
  for (int &i : v2) update(res, dp[n&1][i]);
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}