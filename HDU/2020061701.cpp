/*
 * @Author: Kaizyn
 * @Date: 2020-06-17 18:28:46
 * @LastEditTime: 2020-06-17 18:32:11
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n;
int a[N];

inline void solve() {
  cin >> n;
  int sum = 0, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i <= n; ++i) {
    // if (a[i] > sum/n)
    if (a[i]*n >= sum) ++cnt;
  }
  printf("%.2f %d\n", 1.0*sum/n, cnt);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}