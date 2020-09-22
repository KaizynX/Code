/*
 * @Author: Kaizyn
 * @Date: 2020-09-19 22:49:52
 * @LastEditTime: 2020-09-19 23:04:41
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
int a[N], b[N];

bool check(int m) {
  for (int i = 1; i <= m; ++i) b[i*2] = a[i];
  for (int i = 2*m+1, j = n; i > 0; i -= 2) b[i] = a[j--];
  for (int i = 1; 2*m+1+i <= n; ++i) b[2*m+1+i] = a[m+i];
  int cnt = 0;
  for (int i = 2; i < n; ++i)
    cnt += (b[i] < b[i-1] && b[i] < b[i+1]);
  return cnt >= m;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int l = 0, r = (n-1)/2, m;
  while (l < r) {
    m = (l+r+1)>>1;
    if (check(m)) l = m;
    else r = m-1;
  }
  check(l);
  cout << l << endl;
  for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i==n];
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