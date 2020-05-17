/*
 * @Author: Kaizyn
 * @Date: 2020-05-13 09:22:49
 * @LastEditTime: 2020-05-13 09:26:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, k;
int a[N];

inline void solve() {
  int flag = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] < k) a[i] = 0;
    else if (a[i] == k) a[i] = 1, flag |= 1;
    else a[i] = 2;
  }
  if (n == 1) flag |= 2;
  for (int i = 2; i <= n; ++i) {
    if (a[i] && a[i-1]) flag |= 2;
    if (a[i] && a[i-2]) flag |= 2;
  }
  cout << (flag == 3 ? "yes" : "no") << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}