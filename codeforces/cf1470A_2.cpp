/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 21:22:53
 * @LastEditTime: 2021-01-05 23:05:27
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
int a[N], b[N], c[N];

ll f(int x) {
  ll res = 0;
  for (int i = n, j = x; i; --i) {
    j = min(j, a[i]);
    if (j) res += c[j--];
    else res += c[a[i]];
  }
  return res;
}

inline void solve() {
  p.clear();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = 0;
  }
  sort(a+1, a+n+1);
  for (int i = 1; i <= m; ++i) {
    cin >> c[i];
  }
  int l = 0, r = m;
  while (l < r) {
    int mid = (l+r)>>1;
    if (f(mid) < f(mid+1)) r = mid;
    else l = mid+1;
  }
  cout << f(l) << endl;
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