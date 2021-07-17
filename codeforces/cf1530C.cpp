/*
 * @Author: Kaizyn
 * @Date: 2021-07-17 22:24:07
 * @LastEditTime: 2021-07-17 22:57:51
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

int n;
int a[N], b[N];

bool check(int x) {
  int c = (n+x)-(n+x)/4;
  int y = 0, l = 0;
  for (int i = 1; i <= c; ++i) {
    if (i <= n) l += b[n-i+1];
    if (i <= x) y += 100;
    else y += a[n-i+x+1];
  }
  /*
  int y = x*100, l = 0;
  for (int i = 1; x+i <= c; ++i) {
    y += a[n-i+1];
    l += b[n-i+1];
  }
  */
  return y >= l;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  sort(a+1, a+n+1);
  sort(b+1, b+n+1);
  int l = 0, r = n, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  cout << l << '\n';
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