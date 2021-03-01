/*
 * @Author: Kaizyn
 * @Date: 2021-02-28 20:56:09
 * @LastEditTime: 2021-02-28 22:35:04
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
const int N = 5e3+7;

int n;
int a[N];
ll add[N];

void f(int l, int r, ll x) {
  if (l > r) return;
  add[l] += x;
  if (r+1 <= n) add[r+1] -= x;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    add[i] = 0;
  }
  ll cur = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    cur += add[i];
    if (cur < a[i]-1) {
      res += a[i]-cur-1;
      f(i+2, i+a[i], 1);
    } else {
      f(i+2, i+a[i], 1);
      f(i+1, i+1, cur-a[i]+1);
    }
    #ifdef DEBUG
    cout << cur << " | " << res << '\n';
    #endif
  }
  cout << res << '\n';
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