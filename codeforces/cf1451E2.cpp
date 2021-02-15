/*
 * @Author: Kaizyn
 * @Date: 2021-02-14 16:18:20
 * @LastEditTime: 2021-02-14 17:05:13
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
const int N = (1<<16)+7;

int n;
int res[N], x[N], vis[N];

int query(string q, int x, int y) {
  cout << q << " " << x << " " << y << endl;
  cin >> x;
  return x;
}

void answer() {
  cout << "!";
  for (int i = 1; i <= n; ++i) cout << " " << res[i];
  cout << endl;
}

inline void solve() {
  cin >> n;
  int flag = 0;
  vis[0] = 1;
  for (int i = 2; i <= n; ++i) {
    x[i] = query("XOR", 1, i);
    if (vis[x[i]] && !flag) {
      int j = vis[x[i]];
      // a[1]^a[i] == a[1]^a[j]
      // a[i] == a[j]
      flag = i;
      res[i] = res[j] = query("AND", i, j);
    }
    vis[x[i]] = i;
  }
  if (flag) {
    for (int i = 1; i <= n; ++i) {
      res[i] = res[flag]^x[flag]^x[i];
    }
  } else {
    // n-1 x[] != 0
    // x[] = [1, n-1]
    // a[] = [0, n-1]
    int a1, a0 = 1;
    for (int i = 2; i <= n; ++i) {
      if (x[i] == 1) a1 = i;
    }
    res[1] = query("AND", 1, a1);
    for (int i = 2; i <= n; ++i) {
      if (x[i] == res[1]) a0 = i;
    }
    if (query("AND", a0, n)) res[1] ^= 1;
    for (int i = 2; i <= n; ++i) res[i] = res[1]^x[i];
  }
  answer();
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