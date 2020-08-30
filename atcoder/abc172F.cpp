/*
 * @Author: Kaizyn
 * @Date: 2020-08-27 13:47:53
 * @LastEditTime: 2020-08-27 14:45:25
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e2+7;

int n;
long long a[N];

inline long long solve() {
  cin >> n;
  long long presum = 0, sufsum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sufsum ^= a[i];
  }
  sufsum ^= a[1]^a[2];
  presum = a[1]+a[2];
  if (presum < sufsum) return -1;
  presum -= sufsum;
  if (presum&1) return -1;
  presum >>= 1;
  if (presum&sufsum) return -1;
  // a[1] += presum, a[2] += presum
  // distribute sufsum to a[1], a[2]
  if (presum >= a[2]) return presum-a[2];
  a[2] -= presum;
  if (sufsum < a[2]) return -1;
  if ((sufsum&a[2]) == a[2]) return 0;
  // get subset from sufsum >= a[2]
  long long res = sufsum-a[2], cur = 0;
  for (int i = 40; i >= 0; --i) if ((sufsum>>i)&1) {
    if (cur+(1ll<<i) <= a[2]) {
      cur += (1ll<<i);
    } else {
      res = min(res, cur+(1ll<<i)-a[2]);
    }
  }
  if (cur == a[2]) res = 0;
  if (res == a[1]) return -1; // a[1] = 0
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}