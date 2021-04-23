/*
 * @Author: Kaizyn
 * @Date: 2021-04-16 23:32:25
 * @LastEditTime: 2021-04-16 23:40:41
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

int n;
ll k;
int a[N];

inline void solve() {
  cin >> n >> k;
  if (n <= 61 && 1ll<<(n-1) < k) return cout << -1 << endl, void();
  --k;
  iota(a+1, a+n+1, 1);
  for (int i = 60, j; i >= 0; i = j) {
    j = i-1;
    if (~(k>>i)&1) continue;
    while (j >= 0 && ((k>>j)&1)) --j;
    reverse(a+n-1-i, a+n-j);
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " \n"[i==n];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}