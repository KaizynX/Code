/*
 * @Author: Kaizyn
 * @Date: 2020-11-29 15:48:58
 * @LastEditTime: 2020-11-29 16:33:51
 */
#include <bits/stdc++.h>

// #define DEBUG
// #define int long long

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n, k;
int a[N];
long long s[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  a[n+1] = 0;
  sort(a+1, a+n+1);
  long long res = -1e18, cur = 0, sum = 0;
  ++k;
  int p = 1;
  while (p <= n && a[p] < 0) ++p;
  for (int i = 1; i < p; ++i) {
    s[i] = s[i-1]+(i-1ll)/k*a[i];
  }
  #ifdef DEBUG
  cout << "s:";
  for (int i = 1; i < p; ++i) cout << s[i] << " \n"[i==p-1];
  cout.flush();
  #endif
  cur = sum = 0;
  for (int i = n; i > p; --i) {
    sum += cur;
    cur += a[i];
  }
  for (int i = p; i; --i) {
    sum += cur;
    cur += a[i];
    long long tmp = sum+s[i-1]+(i-1ll)/k*cur;
    res = max(res, tmp);
    if ((i-1)%k && cur > 0) res = max(res, tmp+cur);
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