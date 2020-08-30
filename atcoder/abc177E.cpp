/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 20:45:48
 * @LastEditTime: 2020-08-29 20:52:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
int a[N], cnt[N];

inline void solve() {
  cin >> n;
  int g = 0, f = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    g = __gcd(a[i], g);
    ++cnt[a[i]];
  }
  for (int i = 2; i < 1000000; ++i) {
    int sum = 0;
    for (int j = i; j <= 1000000; j += i) sum += cnt[j];
    if (sum > 1) f = 0;
  }
  if (f && g == 1) cout << "pairwise coprime" << endl;
  else if (!f && g == 1) cout << "setwise coprime" << endl;
  else cout << "not coprime" << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}