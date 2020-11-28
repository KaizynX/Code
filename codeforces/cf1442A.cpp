/*
 * @Author: Kaizyn
 * @Date: 2020-11-02 22:16:09
 * @LastEditTime: 2020-11-02 22:45:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e4+7;

int n;
int a[N];

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int p = 2;
  while (p <= n && a[p-1] >= a[p]) ++p;
  if (p > n)  return true;
  // a[p] > a[p-1]
  a[p] -= a[p-1];
  int q = n;
  while (q > p && a[q] >= a[q-1]) --q;
  return q <= p;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}