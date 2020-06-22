/*
 * @Author: Kaizyn
 * @Date: 2020-06-18 22:30:13
 * @LastEditTime: 2020-06-18 23:41:23
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  for (int i = 1, x, y; i < n; ++i) {
    x = a[i];
    y = a[i+1];
    a[i] = x&y;
    a[i+1] = x|y;
  }
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += 1ll*a[i]*a[i];
  }
  cout << sum << endl;
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