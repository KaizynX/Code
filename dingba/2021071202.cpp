/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 13:15:08
 * @LastEditTime: 2021-07-12 13:33:52
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

int n, k;
int a[N], cnt[N][2], b[N];

inline void solve() {
  int res = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt[i%k][a[i]];
    if (i < k) sum ^= a[i];
  }
  for (int i = 0; i < k; ++i) {
    res += min(cnt[i][0], cnt[i][1]);
  }
  if (sum) {
    int tmp = n;
    for (int i = 0; i < k; ++i) {
      tmp = min(tmp, abs(cnt[i][0]-cnt[i][1]));
    }
    res += tmp;
  }
  cout << res << '\n';
}

void brute() {
  int res = n;
  for (int i = 0; i < 1<<k; ++i) {
    int sum = 0, cnt = __builtin_popcount(i);
    memcpy(b, a, sizeof a);
    for (int j = 0; j < k; ++j) {
      b[j] ^= (i>>j)&1;
      sum ^= b[j];
    }
    if (sum) continue;
    for (int j = k; j < n; ++j) {
      if (b[j-k]^b[j]) {
        ++cnt;
        b[j] ^= 1;
      }
    }
    res = min(res, cnt);
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
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] &= 1;
    }
    if (k > 5) solve();
    else brute();
  }
  return 0;
}