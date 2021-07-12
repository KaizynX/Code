/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 13:48:28
 * @LastEditTime: 2021-07-12 13:54:46
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
const int N = 1e6+7;

int n;
int l[N], r[N];
int v[N], t[N], head, tail;

inline void solve() {
  cin >> n;
  int res = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
    while (head < tail && v[head] > r[i]) {
      j = t[head++]+1;
    }
    while (head < tail && v[tail-1] < l[i]) --tail;
    v[tail] = l[i];
    t[tail] = i;
    ++tail;
    res = max(res, i-j+1);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}