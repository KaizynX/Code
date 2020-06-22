/*
 * @Author: Kaizyn
 * @Date: 2020-06-20 22:23:49
 * @LastEditTime: 2020-06-20 22:55:30
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

int n;
int a[N];
int b[N];
int p[2];

inline void solve() {
  cin >> n;
  p[0] = p[1] = 0;
  for (int i = 1; i <= 2*n; ++i) {
    cin >> a[i];
  }
  int m = 0;
  for (int i = 1; i <= 2*n && m < n-1; ++i) {
    if (p[a[i]&1]) {
      cout << p[a[i]&1] << " " << i << endl;
      p[a[i]&1] = 0;
      ++m;
    } else {
      p[a[i]&1] = i;
    }
  }
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