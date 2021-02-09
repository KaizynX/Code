/*
 * @Author: Kaizyn
 * @Date: 2021-02-09 13:44:40
 * @LastEditTime: 2021-02-09 14:19:20
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

int f(int x) {
  if (~a[x]) return a[x];
  cout << "? " << x << endl;
  cin >> a[x];
  return a[x];
}

inline void solve() {
  cin >> n;
  memset(a+1, -1, sizeof(int)*n);
  a[0] = a[n+1] = INF;
  int l = 1, r = n;
  while (l < r) {
    int mid = (l+r)/2;
    if (f(mid) < f(mid+1)) r = mid;
    else l = mid+1;
  }
  for (int i = max(1, l-5); i <= min(n, l+5); ++i) f(i);
  for (int i = max(1, l-5); i <= min(n, l+5); ++i) {
    if (a[i] < a[i-1] && a[i] < a[i+1]) {
      return cout << "! " << i << endl, void();
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}