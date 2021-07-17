/*
 * @Author: Kaizyn
 * @Date: 2021-07-17 12:09:25
 * @LastEditTime: 2021-07-17 12:11:47
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e3+7;

int n, m;
string a[N];
string str;

inline void solve() {
  cin >> n >> m;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int cnt = 0;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '1') cnt = 0;
      else ++cnt;
      res += cnt >= m;
    }
    for (int j = m; j < n; ++j) {
      if (a[i][j] == '1') cnt = 0;
      else ++cnt;
      res += cnt >= m;
    }
  }
  cin >> str;
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}