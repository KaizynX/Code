/*
 * @Author: Kaizyn
 * @Date: 2020-12-07 18:44:30
 * @LastEditTime: 2020-12-07 18:50:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e2+7;

int n;
char a[N][N];
int cnt[2][3];

void print(char a[N][N]) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
}

void fuck(int x, int o) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] == 'X' && (i+j)%3 == x) a[i][j] = 'O';
      else if (a[i][j] == 'O' && (i+j)%3 == o) a[i][j] = 'X';
    }
  }
}

inline void solve() {
  cin >> n;
  int k = 0;
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i]+1);
    for (int j = 1; j <= n; ++j) if (a[i][j] != '.') {
      ++cnt[a[i][j] == 'O'][(i+j)%3];
      ++k;
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) if (i != j) {
      if (cnt[0][i]+cnt[1][j] <= k/3) {
        fuck(i, j);
        print(a);
        return;
      }
    }
  }
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