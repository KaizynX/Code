/*
 * @Author: Kaizyn
 * @Date: 2021-07-11 22:31:59
 * @LastEditTime: 2021-07-12 00:32:52
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
int a[N], d[N];
pii b[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = pii{a[i], i};
  }
  sort(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) {
    d[i] = abs(b[i].second-i)&1;
  }
  int flag = 0;
  for (int i = 1; i < n; ++i) {
    if (d[i] && b[i].first == b[i+1].first) {
      d[i] ^= 1;
      d[i+1] ^= 1;
    }
    flag += d[i];
  }
  flag += d[n];
  cout << (flag == 0 ? "YES" : "NO") << '\n';
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