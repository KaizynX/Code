/*
 * @Author: Kaizyn
 * @Date: 2021-02-14 16:18:20
 * @LastEditTime: 2021-02-14 17:19:38
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

void work(int a = 1) {
  res[1] = res[a]^x[a];
  for (int i = 2; i <= n; ++i) res[i] = res[1]^x[i];
}

void answer() {
  cout << "!";
  for (int i = 1; i <= n; ++i) cout << " " << res[i];
  cout << endl;
}

inline void solve() {
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    x[i] = query("XOR", 1, i);
  }
  // a[1]^a[i] == a[1]^a[j]
  // a[i] == a[j]
  vis[0] = 1;
  for (int i = 2; i <= n; ++i) {
    if (vis[x[i]]) {
      int j = vis[x[i]];
      res[i] = res[j] = query("AND", i, j);
      return work(i), answer();
    }
    vis[x[i]] = i;
  }
  // x[] = [1, n-1]
  // a[] = [0, n-1]
  int a1, a0 = 1;
  for (int i = 2; i <= n; ++i) {
    if (x[i] == 1) a1 = i;
  }
  // a[1]^a[a1] = 1
  // a[1] = res[1] or res[1]^1
  res[1] = query("AND", 1, a1);
  for (int i = 2; i <= n; ++i) {
    if (x[i] == res[1]) a0 = i;
  }
  if (query("AND", a0, 1+(a0 == 1))) res[1] ^= 1;
  work(1); answer();
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