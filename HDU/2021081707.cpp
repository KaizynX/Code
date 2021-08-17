/*
 * @Author: Kaizyn
 * @Date: 2021-08-17 12:31:45
 * @LastEditTime: 2021-08-17 12:49:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e7+3;

int n;
int a[N], p[N], L[N], R[N], q[N];
char op[10];

inline void solve() {
  scanf("%d", &n);
  int P = 0, nl = 0, nr = 1, np, id = 0, m = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", op);
    if (op[0] == 'L') {
      q[i] = -1;
      ++P;
    } else if (op[0] == 'R') {
      q[i] = -2;
    } else if (op[0] == 'Q') {
      q[i] = -3;
    } else {
      scanf("%d", q+i);
    }
    L[i] = i-1; R[i] = i+1;
  }
  if (q[1] == -1) {
    a[P-nl] = ++id;
    np = p[id] = P-nl;
    ++nl;
    ++m;
  } else if (q[1] == -2) {
    a[P+nr] = ++id;
    np = p[id] = P+nr;
    ++nr;
    ++m;
  }
  for (int i = 2; i <= n; ++i) {
    if (q[i] == -1) {
      a[P-nl] = ++id;
      p[id] = P-nl;
      ++nl;
      if ((++m)&1) np = L[np];
    } else if (q[i] == -2) {
      a[P+nr] = ++id;
      p[id] = P+nr;
      ++nr;
      if ((m++)&1) np = R[np];
    } else if (q[i] == -3) {
      printf("%d\n", a[np]);
    } else {
      int pos = p[q[i]];
      R[L[pos]] = R[pos];
      L[R[pos]] = L[pos];
      if (m&1) {
        if (pos <= np) np = R[np];
      } else {
        if (pos >= np) np = L[np];
      }
      --m;
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}