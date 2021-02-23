/*
 * @Author: Kaizyn
 * @Date: 2021-02-19 14:10:12
 * @LastEditTime: 2021-02-19 14:29:09
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

int n, k;
int a[N], s[N];

// big <= len/2 && small <= (len-1)/2
// cnt[>=] > cnt[<]
// presum(cnt[>=]-cnt[<]) > 0

bool check(int x) {
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i-1]+(a[i] >= x ? 1 : -1);
  }
  for (int i = k, last = 0; i <= n; ++i) { // len >= k
    last = min(last, s[i-k]);
    if (s[i]-last > 0) return true;
  }
  return false;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int l = 1, r = n;
  while (l < r) {
    int mid = (l+r+1)>>1;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}