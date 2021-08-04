/*
 * @Author: Kaizyn
 * @Date: 2021-08-01 14:05:58
 * @LastEditTime: 2021-08-01 14:10:30
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, k;
int a[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int res = 0;
  for (int i = 1, last = -INF; i <= n; ++i) {
    int cur = max(last+1, a[i]-k);
    #ifdef DEBUG
    cout << cur << " \n"[i==n];
    #endif
    if (cur <= a[i]+k) ++res;
    last = min(cur, a[i]+k);
  }
  cout << res << '\n';
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