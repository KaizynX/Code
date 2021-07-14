/*
 * @Author: Kaizyn
 * @Date: 2021-07-14 16:41:05
 * @LastEditTime: 2021-07-14 16:53:18
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

struct Node {
  int x, y;
};

int n;
int f[N];
Node a[N];

inline ll w(int i, int j) {
  return ll(a[i].x-a[j].x)*(a[i].x-a[j].x)+ll(a[i].y-a[j].y)*(a[i].y-a[j].y);
}

void DP(int l, int r, int k_l, int k_r) {
  int mid = (l + r) / 2, k = k_r;
  ll wk = w(k, mid);
  for (int i = k_l; i != k_r; i = (i+1)%n) {
    ll wi = w(i, mid);
    if (wi > wk || (wi == wk && i < k)) {
      k = i;
      wk = wi;
    }
  }
  f[mid] = k;
  if (l < mid) DP(l, mid - 1, k_l, k);
  if (r > mid) DP(mid + 1, r, k, k_r);
}

int brute(int x) {
  int k = 0;
  for (int i = 1; i < n; ++i) {
    if (w(x, i) > w(x, k)) k = i;
  }
  return k;
}

inline void fuck() {
  for (int i = 0; i < n; ++i) {
    int k = 0;
    for (int j = 0; j < n; ++j) {
      if (w(i, j) > w(i, k)) k = j;
    }
    cout << k+1 << '\n';
  }
}

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  if (n <= 5000) return fuck();
  f[0] = brute(0);
  f[n-1] = brute(n-1);
  DP(0, n-1, f[0], f[n-1]);
  for (int i = 0; i < n; ++i) {
    cout << f[i]+1 << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}