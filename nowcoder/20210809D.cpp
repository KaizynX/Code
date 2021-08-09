/*
 * @Author: Kaizyn
 * @Date: 2021-08-09 12:54:44
 * @LastEditTime: 2021-08-09 13:39:37
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
#ifdef DEBUG
const int B = 3;
using BT = bitset<3>;
#endif

int n;
int b[N], c[N], d[N], e[N], f[N];

inline ll solve() {
  cin >> n;
  for (int i = 2; i <= n; ++i) cin >> b[i];
  for (int i = 2; i <= n; ++i) cin >> c[i];
  d[1] = c[2]-b[2];
  e[1] = b[2];
  d[n] = c[n]-b[n];
  e[n] = b[n];
  for (int i = 2; i < n; ++i) {
    d[i] = (c[i]-b[i])|(c[i+1]-b[i+1]);
    e[i] = b[i]&b[i+1];
  }
  for (int i = 1; i <= n; ++i) {
    if ((e[i]|d[i]) > e[i]) return 0;
    f[i] = e[i]^d[i];
    #ifdef DEBUG
    cout << i << ':' << BT(d[i]) << ' ' << BT(e[i]) << ' ' << BT(f[i]) << '\n';
    #endif
  }
  for (int i = 2; i <= n; ++i) {
    if ((d[i-1]|d[i]|b[i]) > b[i]) return 0;
    // b[i] ^= d[i-1]|d[i];
    int bb = b[i]^(d[i-1]|d[i]);
    // c[i] -= d[i-1]+d[i];
    // if (c[i] < 0) return 0;
    d[i-1] |= bb^(bb&f[i]);
    d[i] |= bb^(bb&f[i-1]);
    f[i-1] ^= f[i-1]&d[i];
    f[i] ^= f[i]&d[i-1];
  }
  for (int i = 2; i <= n; ++i) {
    if ((d[i-1]|d[i]|b[i]) > b[i]) return 0;
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << i << ':' << BT(d[i]) << ' ' << BT(e[i]) << ' ' << BT(f[i]) << '\n';
  }
  #endif
  ll res = 1;
  for (int i = 2; i <= n; ++i) {
    res *= 1ll<<__builtin_popcount(f[i]^f[i-1]);
  }
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}