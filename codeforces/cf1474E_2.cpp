/*
 * @Author: Kaizyn
 * @Date: 2021-02-05 15:42:23
 * @LastEditTime: 2021-02-05 15:49:32
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
const int N = 1e5+7;

int n;
int a[N];

void fake() {
  ll cost = 0;
  for (int i = 1; i < n; ++i) cost += 1ll*i*i;
  cout << cost << '\n';
  for (int i = 1; i < n; ++i) cout << i+1 << " ";
  cout << 1 << '\n' << n-1 << '\n';
  for (int i = 1; i < n; ++i) {
    cout << i << " " << n << '\n';
  }
}

inline void solve() {
  cin >> n;
  if (n <= 3) return fake();
  ll cost = (n-1ll)*(n-1ll);
  a[1] = n-1;
  a[n] = 2;
  for (int i = 2; i <= n/2; ++i) {
    a[i] = i+1;
    cost += 1ll*(n-i)*(n-i);
  }
  for (int i = n-1; i > n/2; --i) {
    a[i] = i-1;
    cost += 1ll*(i-1)*(i-1);
  }
  a[n/2] = 1;
  a[n/2+1] = n;
  cout << cost << '\n';
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  cout << n-1 << '\n';
  for (int i = 2; i <= n/2; ++i) cout << i << " " << n << '\n';
  for (int i = n-1; i > n/2; --i) cout << i << " " << 1 << '\n';
  cout << 1 << " " << n << '\n';
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