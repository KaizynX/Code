/*
 * @Author: Kaizyn
 * @Date: 2020-09-12 22:04:37
 * @LastEditTime: 2020-09-12 22:12:41
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

int n, q;
int a[N], b[N], c[N];

inline int brute() {
  b[1] = 0;
  c[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    if (a[i] >= a[i-1]) {
      c[i] = c[i-1];
      b[i] = b[i-1]+(a[i]-a[i-1]);
    } else {
      b[i] = b[i-1];
      c[i] = c[i-1]+(a[i]-a[i-1]);
    }
  }
  return ceil((b[n]+c[1])/2.0);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cout << brute() << endl;
  cin >> q;
  for (int i = 1, l, r, x; i <= q; ++i) {
    cin >> l >> r >> x;
    for (int j = l; j <= r; ++j) a[j] += x;
    cout << brute() << endl;
  }
  return 0;
}