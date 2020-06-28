/*
 * @Author: Kaizyn
 * @Date: 2020-06-25 23:15:44
 * @LastEditTime: 2020-06-25 23:38:49
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
int a[N], b[N], c[N];

inline void my_rotate() {
  static int ta[N], tb[N];
  int p = 0;
  for (int i = 1; i < n; ++i) {
    if (b[i]-a[i] > b[p]-a[p]) p = i;
  }
  memcpy(ta, a, sizeof(int)*n);
  memcpy(tb, b, sizeof(int)*n);
  for (int i = 0; i < n; ++i) {
    a[i] = ta[(i+p)%n];
    b[i] = tb[(i+p)%n];
  }
  #ifdef DEBUG
  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];
  for (int i = 0; i < n; ++i) cout << b[i] << " \n"[i==n-1];
  #endif
}

inline bool solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  my_rotate();
  c[0] = a[0]-b[0];
  for (int i = 1; i < n; ++i) {
    if (b[i] < c[i-1]) return false;
    c[i] = max(-b[i], a[i]-b[i]+c[i-1]);
  }
  #ifdef DEBUG
  for (int i = 0; i < n; ++i) cout << c[i] << " \n"[i==n-1];
  #endif
  if (c[n-1] <= 0) return true;
  if (b[0] < c[n-1]) return false;
  b[0] -= c[n-1];
  a[n-1] -= c[n-1];
  a[0] -= b[0];
  for (int i = 1; i < n; ++i) {
    if (b[i] < a[i-1]) return false;
    a[i] = max(-b[i], a[i]-b[i]+a[i-1]);
  }
  #ifdef DEBUG
  for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];
  #endif
  return true;
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