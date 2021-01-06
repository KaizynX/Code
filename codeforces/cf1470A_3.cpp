/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 23:20:09
 * @LastEditTime: 2021-01-06 00:12:12
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
const int N = 3e5+7;

int n, m;
int a[N], c[N];

bool check(int x) {
  for (int i = n, j = x; j; --i, --j) {
    if (j >= a[i]) return false;
  }
  return true;
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  for (int i = 1; i <= m; ++i) {
    cin >> c[i];
  }
  int l = 0, r = min(m, n);
  while (l < r) {
    int mid = (l+r+1)>>1;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  ll res = 0;
  while (l && a[n-l+1] <= l) --l;
  for (int i = 1; i <= l; ++i) res += c[i];
  for (int i = 1; i <= n-l; ++i) res += c[a[i]];
  /*
  for (int i = n, j = l; i; --i, --j) {
    if (j) res += c[j];
    else res += c[a[i]];
  }
  */
  cout << res << endl;
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