/*
 * @Author: Kaizyn
 * @Date: 2020-12-07 01:00:28
 * @LastEditTime: 2020-12-07 01:12:16
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
int a[N], cnt[N];

inline void solve() {
  cin >> n;
  memset(cnt+1, 0, sizeof(int)*n);
  int flag = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (++cnt[a[i]] > (n+1)/2) flag = 0;
  }
  if (!flag) return cout << -1 << endl, void();
  memset(cnt+1, 0, sizeof(int)*n);
  int k = 0, mxi = 0, mxt = 0;
  for (int i = 1, j; i <= n; i = j) {
    j = i+1;
    while (j <= n && a[j] != a[j-1]) ++j;
    ++cnt[a[i]];
    ++cnt[a[j-1]];
    ++k;
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << cnt[i] << " \n"[i==n];
  cout <<"k=" <<k<<endl;
  #endif
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > mxt) {
      mxt = cnt[i];
      mxi = i;
    }
  }
  cnt[0] = cnt[1] = cnt[2] = 0;
  for (int i = 1; i < n; ++i) if (a[i] != a[i+1]) {
    ++cnt[(a[i] != mxi)+(a[i+1] != mxi)];
  }
  while (mxt > k+1) {
    if (cnt[2]) {
      --cnt[2];
      ++k;
    } else if (cnt[1]) {
      --cnt[1];
      ++k;
      ++mxt;
    } else {
      break;
    }
  }
  if (mxt <= k+1)  cout << k-1 << endl;
  else cout << -1 << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}