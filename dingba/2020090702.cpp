/*
 * @Author: Kaizyn
 * @Date: 2020-09-07 20:03:04
 * @LastEditTime: 2020-09-07 20:05:32
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e6+7;

int n, k;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i < n-k; ++i) {
    cout << i << " ";
  }
  int l = n-k, r = n;
  while (l <= r) {
    cout << l << " ";
    if (l != r) cout << r << " ";
    ++l; --r;
  }
  cout << endl;
  return 0;
}