/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 22:13:36
 * @LastEditTime: 2020-08-30 23:12:28
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

inline bool solve() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a+1, a+n+1);
  if (n == 1 || sum%2 == 1 || a[n] > sum-a[n]) return true;
  return false;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "T" : "HL") << endl;
  }
  return 0;
}