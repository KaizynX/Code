/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 12:50:28
 * @LastEditTime: 2021-07-12 13:05:33
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
const int N = 1e5+7;

int n, d[3];
int a[N][3];
set<int> st[3];

inline void solve() {
  cin >> n;
  for (int i = 0; i < 3; ++i) cin >> d[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) cin >> a[i][j];
  }
  int id = 0;
  for (int i = 1; i <= n; ++i) {
    int flag = 0;
    for (int j = 0; j < 3; ++j) {
      auto it = st[j].lower_bound(a[i][j]-d[j]);
      if (it != st[j].end() && *it <= a[i][j]+d[j]) {
        flag = 1;
        break;
      }
      st[j].insert(a[i][j]);
    }
    if (flag) {
      id = i;
      break;
    }
  }
  cout << id << '\n';
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