/*
 * @Author: Kaizyn
 * @Date: 2021-01-14 10:11:20
 * @LastEditTime: 2021-01-14 10:14:53
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

int n, m;
int a[N];
ll s[N];

inline void solve() {
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = s[i-1]+a[i];
  }
  for (int _ = m, l, r; _; --_) {
    cin >> l >> r;
    if (l > r) swap(l, r);
    cout << s[r]-s[l-1] << endl;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  while (cin >> n >> m) solve();
  return 0;
}