/*
 * @Author: Kaizyn
 * @Date: 2021-03-01 00:16:32
 * @LastEditTime: 2021-03-01 00:21:34
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
const int N = 1e5+7;

int n;
int a[N], cnt[N];

bool dfs(int t) {
  if (t > n+2) return false;
  int flag = 0, check = 0;
  for (int i = 1; i <= n; ++i) {
    flag |= cnt[i]&1;
    check += a[i] == i;
  }
  if (!flag && check == n) return true;
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      ++cnt[a[i]]; ++cnt[a[j]];
      swap(a[i], a[j]);
      if (dfs(t+1)) {
        cout << i << " " << j << '\n';
        swap(a[i], a[j]);
        return true;
      }
      swap(a[i], a[j]);
      --cnt[a[i]]; --cnt[a[j]];
    }
  }
  return false;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  dfs(1);
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