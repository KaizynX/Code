/*
 * @Author: Kaizyn
 * @Date: 2020-08-12 22:31:41
 * @LastEditTime: 2020-08-12 22:44:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, d, m;
int a[N];

inline void solve() {
  cin >> n >> d >> m;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt += a[i] > m;
  }
  sort(a+1, a+n+1);
  long long muz = max(0ll, (cnt-1ll)*d);
  long long res = 0;
  if (muz <= n-cnt) {
    for (int i = muz+1; i <= n; ++i) res += a[i];
  } else {
    int cnt = (n+d)/(d+1);
    for (int i = n; i > n-cnt; --i) res += a[i];
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