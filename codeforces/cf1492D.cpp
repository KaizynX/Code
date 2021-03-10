/*
 * @Author: Kaizyn
 * @Date: 2021-02-23 17:03:16
 * @LastEditTime: 2021-02-23 18:02:02
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

int a, b, k;

inline void solve() {
  cin >> a >> b >> k;
  if (k >= a+b) return cout << "NO\n", void();
  if (a == 0 || b == 1) {
    if (k) return cout << "NO\n", void();
    cout << "YES\n";
    cout << string(b, '1') << string(a, '0') << '\n';
    cout << string(b, '1') << string(a, '0') << '\n';
    return;
  }
  if (k == a+b-1 && b <= 2) return cout << "NO\n", void();
  if (k <= b-1) {
    cout << "YES\n";
    cout << string(b-k, '1') << string(a-1, '0') << string(k, '1') << "0\n";
    cout << string(b-k, '1') << string(a, '0') << string(k, '1') << '\n';
    return;
  }
  if (a-1 < k-b+1) return cout << "NO\n", void();
  cout << "YES\n";
  cout << '1' << string(a-1-(k-b+1), '0') << '1' << string(k-b+1, '0') << string(b-2, '1') << "0\n";
  cout << '1' << string(a, '0') << string(b-1, '1') << '\n';
  // return cout << "NO\n", void();
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