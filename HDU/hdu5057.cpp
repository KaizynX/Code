/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 11:01:35
 * @LastEditTime: 2020-05-15 13:07:56
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
const int NN = 300;

int n, m, t;
int a[N];
int b[N][10], f[NN][10][10];

inline void add(const int &x) {
  for (int i = 0, v = a[x]; i < 10; ++i) {
    b[x][i] = v%10;
    ++f[x/t][i][b[x][i]];
    v /= 10;
  }
}

inline void del(const int &x) {
  for (int i = 0; i < 10; ++i) {
    --f[x/t][i][b[x][i]];
  }
}

inline int query(const int &l, const int &r, const int &d, const int &p) {
  int res = 0, x = l;
  for ( ; x <= r && x%t; ++x) res += b[x][d] == p;
  for ( ; x*t+t-1 <= r; x += t) res += f[x/t][d][p];
  for ( ; x <= r; ++x) res += b[x][d] == p;
  return res;
}

inline void solve() {
  memset(f, 0, sizeof f);
  scanf("%d %d", &n, &m);
  // t = sqrt(n)+.5;
  t = 400;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    add(i);
  }
  char op;
  for (int i = 1, l, r, d, p; i <= m; ++i) {
    // scanf("%s", op);
    getchar(); scanf("%c", &op);
    if (op == 'Q') {
      scanf("%d %d %d %d", &l, &r, &d, &p);
      printf("%d\n", query(l-1, r-1, d-1, p));
    } else {
      scanf("%d %d", &l, &r);
      --l;
      del(l);
      a[l] = r;
      add(l);
    }
  }
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}