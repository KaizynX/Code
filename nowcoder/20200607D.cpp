/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 13:41:11
 * @LastEditTime: 2020-06-07 13:56:30
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
int a[N], d[N];

inline bool solve() {
  cin >> n;
  int cnt = 0, minv = INF;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt += a[i] == 0;
    minv = min(minv, a[i]);
  }
  if (cnt == n) return true;
  if (cnt > 1) return false;
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += a[i] == minv;
  }
  if (cnt == n) return true;
  if (minv+1 < cnt) return false;
  cnt = 0;
  for (int i = 1; i < n; ++i) {
    d[i] = a[i+1]-a[i];
    cnt += d[i] == 0;
    if (d[i]%n) return false;
  }
  return true;
  if (cnt == n-1) return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}