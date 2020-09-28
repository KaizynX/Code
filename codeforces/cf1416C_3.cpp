/*
 * @Author: Kaizyn
 * @Date: 2020-09-28 13:55:14
 * @LastEditTime: 2020-09-28 14:14:27
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

int n;
int a[N], tmp[N];
vector<pii> q[2];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int x = 0;
  long long inversions = 0;
  q[1].emplace_back(1, n);
  for (int b = 30; b >= 0; --b) {
    long long t0 = 0, t1 = 0;
    q[b&1].clear();
    for (pii &p : q[~b&1]) {
      int l = p.first, r = p.second;
      int c0 = 0, c1 = 0;
      for (int i = l; i <= r; ++i) {
        if ((a[i]>>b)&1) ++c1, t1 += c0;
        else ++c0, t0 += c1;
      }
    }
    if (t0 <= t1) inversions += t0;
    else x |= 1<<b, inversions += t1;
    for (pii &p : q[~b&1]) {
      int l = p.first, r = p.second, k = l;
      for (int i = l; i <= r; ++i)
        if ((((a[i]^x)>>b)&1) == 0) tmp[k++] = a[i];
      if (l < k) q[b&1].emplace_back(l, k-1);
      if (k < r) q[b&1].emplace_back(k, r);
      for (int i = l; i <= r; ++i)
        if ((((a[i]^x)>>b)&1) == 1) tmp[k++] = a[i];
    }
    memcpy(a+1, tmp+1, sizeof(int)*n);
  }
  cout << inversions << " " << x << endl;
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