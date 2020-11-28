/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 15:02:01
 * @LastEditTime: 2020-10-25 16:14:38
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, m;
int a[N], cnt[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    int res = n;
    for (int l = 1, r; l <= n; ++l) {
      memset(cnt+1, 0, sizeof(int)*m);
      int check = 0;
      for (r = l; r <= n; ++r) {
        if (++cnt[a[r]] == 1 && a[r] <= i && ++check == i) break;
      }
      if (check == i) res = min(res, r-l+1);
    }
    cout << res << " \n"[i==m];
  }
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