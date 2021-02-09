/*
 * @Author: Kaizyn
 * @Date: 2021-01-08 22:33:17
 * @LastEditTime: 2021-01-08 22:50:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e5+7;

int n;
int a[N], b[N];

int check(int x) {
  if (x <= 1 || x >= n) return 0;
  if (a[x] < a[x+1] && a[x] < a[x-1]) return 1;
  if (a[x] > a[x+1] && a[x] > a[x-1]) return 1;
  return 0;
}

inline void solve() {
  cin >> n;
  int cnt = 0, mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  b[0] = b[n+1] = 0;
  for (int i = 1; i <= n; ++i) {
    b[i] = check(i);
  }
  for (int i = 2; i < n; ++i) {
    cnt += b[i];
    int tmp = a[i];
    a[i] = a[i-1];
    mx = max(mx, b[i-1]+b[i]+b[i+1]-check(i-1)-check(i)-check(i+1));
    a[i] = a[i+1];
    mx = max(mx, b[i-1]+b[i]+b[i+1]-check(i-1)-check(i)-check(i+1));
    a[i] = tmp;
  }
  cout << cnt-mx << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}