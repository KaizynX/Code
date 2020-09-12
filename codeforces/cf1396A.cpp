/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 22:13:26
 * @LastEditTime: 2020-08-30 22:50:21
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

int n;
int a[N];
long long b1[N], b2[N];

template <typename T>
T exgcd(const int a, const int b, T &x, T &y) {
  if (!b) { x = 1; y = 0; return a; }
  T d = exgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << "1 1\n0\n1 1\n0\n1 1\n";
    cout << -a[1] << endl;
    return ;
  }
  for (int i = 1; i < n; ++i) {
    // n*b1[i] + (n-1)*b2[i] = 1
    exgcd(n, n-1, b1[i], b2[i]);
    // n*b1[i] + (n-1)*b2[i] = -a[i]
    b1[i] = -1ll*a[i]*b1[i]*n;
    b2[i] = -1ll*a[i]*b2[i]*(n-1);
  }
  cout << 1 << " " << n << endl;
  for (int i = 1; i < n; ++i) cout << b1[i] << " ";
  cout << 0 << endl;
  cout << 1 << " " << n-1 << endl;
  for (int i = 1; i < n; ++i) cout << b2[i] << " \n"[i==n-1];
  cout << n << " " << n << endl;
  cout << -a[n] << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}