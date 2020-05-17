/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 11:01:35
 * @LastEditTime: 2020-05-15 13:15:16
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int NN = 400;
const int pw10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int n, m, t;
int a[N];
int f[NN][11][11];

inline void update(const int &x, const int &k) {
  for (int i = 0, v = a[x]; i < 10; ++i, v /= 10) {
    f[x/t][i][v%10] += k;
  }
}

inline int query(const int &l, const int &r, const int &d, const int &p) {
  int res = 0, x = l;
  for ( ; x <= r && x%t; ++x) res += a[x]/pw10[d]%10 == p;
  for ( ; x*t+t-1 <= r; x += t) res += f[x/t][d][p];
  for ( ; x <= r; ++x) res += a[x]/pw10[d]%10 == p;
  return res;
}

inline void solve() {
  scanf("%d%d", &n, &m);
  // t = sqrt(n)+.5;
  t = 400;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    update(i, 1);
  }
  char op;
  for (int i = 1, l, r, d, p; i <= m; ++i) {
    getchar(); scanf("%c", &op);
    if (op == 'Q') {
      scanf("%d%d%d%d", &l, &r, &d, &p);
      printf("%d\n", query(l-1, r-1, d-1, p));
    } else {
      scanf("%d%d", &l, &r);
      --l;
      update(l, -1);
      a[l] = r;
      update(l, 1);
    }
  }
  for (int i = 0; i < n; ++i) update(i, -1);
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}