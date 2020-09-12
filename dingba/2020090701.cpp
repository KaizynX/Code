/*
 * @Author: Kaizyn
 * @Date: 2020-09-07 19:51:20
 * @LastEditTime: 2020-09-07 19:52:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int a[10];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n = 8;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  cout << (a[n]+a[n-1] > a[1]+a[2]+a[3] ? "Yes" : "No") << endl;
  return 0;
}