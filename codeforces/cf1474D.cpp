/*
 * @Author: Kaizyn
 * @Date: 2021-02-05 15:04:25
 * @LastEditTime: 2021-02-05 15:22:13
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
const int N = 2e5+7;

int n;
int a[N], suf[N], pre[N];

inline void solve() {
  cin >> n;
  pre[0] = suf[n+1] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (pre[i-1] < 0) pre[i] = -1;
    else pre[i] = a[i]-pre[i-1];
  }
  for (int i = n; i; --i) {
    if (suf[i+1] < 0) suf[i] = -1;
    else suf[i] = a[i]-suf[i+1];
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << pre[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << suf[i] << " \n"[i==n];
  #endif
  int res = pre[n] == 0;
  for (int i = 1; i < n; ++i) {
    // swap(a[i], a[i+1]);
    if (pre[i-1] < 0 || suf[i+2] < 0) continue;
    if (a[i+1] < pre[i-1] || a[i] < suf[i+2]) continue;
    if (a[i+1]-pre[i-1] == a[i]-suf[i+2]) res |= 1;
  }
  cout << (res ? "YES" : "NO") << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
1
5
2 2 2 1 3
*/