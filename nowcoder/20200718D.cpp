/*
 * @Author: Kaizyn
 * @Date: 2020-07-18 13:44:15
 * @LastEditTime: 2020-07-18 14:26:43
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n, m;
int mv[N], mx[N], my[N];

inline void init() {
  memset(mv, 0x3f, sizeof mv);
  for (int x = 2; x <= 25; ++x) {
    for (int y = 2; x*y <= 50; ++y) {
      int val = (x+y-1)*2+2;
      for (int k = x+y-1; k <= x*y; ++k) {
        if (val < mv[k]) {
          mv[k] = val;
          mx[k] = x;
          my[k] = y;
        }
      }
    }
  }
  mv[1] = 4;
  mv[2] = 6;
  mv[3] = 8;
  #ifdef DEBUG
  for (int i = 1; i <= 50; ++i) {
    cout << mv[i] << " \n"[i==50];
  }
  cout.flush();
  #endif
}

inline void print(const int &x, const int &y) {
  cout << x << " " << y << endl;
}

inline void solve() {
  cin >> n >> m;
  if (m%2 || 4*n < m || mv[n] > m) return cout << "No" << endl, void();
  cout << "Yes" << endl;
  if (4*n == m) {
    for (int i = 1; i <= n; ++i) print(i, i);
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if ((i*2+2)+(n-i)*4 == m) {
      for (int j = 1; j <= i; ++j) print(1, j);
      for (int j = 1; j <= n-i; ++j) print(1000000+j, 1000000+j);
      return;
    }
  }
  for (int s = 0; s <= n && s*4 <= m; ++s) {
    if (mv[n-s] <= m-4*s && m-4*s <= (n-s)*2+2) {
      for (int i = 1; i <= s; ++i) print(1000000+i, 1000000+i);
      n -= s;
      m -= s*4;
      int x = mx[n], y = my[n];
      for (int i = 2; i <= y; ++i) print(1, i);
      for (int i = 1; i <= x; ++i) print(i, 1);
      n -= x+y-1;
      m -= (x+y-1)*2+2;
      for ( ; m; m -= 2, --n) print(++x, 1);
      for (int i = 2; i <= x; ++i) {
        for (int j = 2; j <= y; ++j) {
          if (!n) return;
          print(i, j);
          --n;
        }
      }
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // for (int i = 1; i <= 50; ++i) getmin(i);
  init();
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}