/*
 * @Author: Kaizyn
 * @Date: 2020-11-16 21:55:30
 * @LastEditTime: 2020-11-16 22:07:12
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;
const int M = 1e2+7;

int n;
int a[N];
int buf[N<<1], *last = buf+N;
int cnt[M];

int calc(int D, int V) {
  int res = 0;
  memset(buf, -1, sizeof buf);
  last[0] = 0;
  for (int i = 1, s = 0; i <= n; ++i) {
    if (a[i] == D) --s;
    else if (a[i] == V) ++s; 
    if (~last[s]) res = max(res, i-last[s]);
    else last[s] = i;
  }
  return res;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int mx = 0, D, V, mxt = 0;
  for (int i = 1; i <= n; ++i) {
    ++cnt[a[i]];
    if (cnt[a[i]] > mx) {
      mx = cnt[a[i]];
      mxt = 1;
      D = a[i];
    } else if (cnt[a[i]] == mx) {
      ++mxt;
      V = a[i];
    }
  }
  if (mxt > 1) return cout << calc(D, V) << endl, void();
  int res = 0;
  for (V = 1; V <= 100; ++V) if (D != V) {
    res = max(res, calc(D, V));
  }
  cout << res << endl;
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