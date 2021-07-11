/*
 * @Author: Kaizyn
 * @Date: 2021-07-11 21:52:45
 * @LastEditTime: 2021-07-11 22:24:16
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
    if (b[i].first == b[i-1].first && d[i] == 1 && d[i-1] == 1) {
      d[i-1] = d[i] = 0;
    }
  }
  int flag = 1;
  for (int i = 1; i <= n; ++i) {
    flag &= d[i] == 0;
  }
  cout << (flag ? "YES" : "NO") << '\n';
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