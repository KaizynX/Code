/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 23:40:02
 * @LastEditTime: 2020-06-08 00:19:54
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;

int n;
int a[N], b[N], c[N];

inline bool check() {
  for (int i = 1; i <= n; ++i) if (b[i] != c[i]) return false;
  return true;
}

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];

  for (int i = 1; i <= n/2; ++i) {
    if (b[i] > b[n-i+1]) swap(b[i], b[n-i+1]);
  }
  for (int i = 0; i <= n/2; ++i) {
    for (int j = 1; j <= i; ++j) c[j] = a[n-i+j], c[n-i+j] = a[j];
    for (int j = i+1; j <= n-i; ++j) c[j] = a[j];
    for (int j = 1; j <= n/2; ++j) if (c[j] > c[n-j+1]) swap(c[j], c[n-j+1]);
    if (check()) return true;
  }
  return false;
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