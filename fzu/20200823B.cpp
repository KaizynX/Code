/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 12:40:06
 * @LastEditTime: 2020-08-23 13:38:10
 */
#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include<chrono>
//#include<unordered_set>
//#include<unordered_map>

// #define DEBUG
using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n, q;
int a[2][N][N];

inline void solve() {
  for (int k = 0; k < 2; ++k)
  for (int i = 1; i <= n; ++i)
  for (int j = 1; j <= n; ++j)
    cin >> a[k][i][j];
  long long res = 0;
  for (int i = 1; i <= n; ++i)
  for (int j = 1; j <= n; ++j)
    res += a[0][i][j]*a[1][j][i];
  for (int i = 1, k, x, y, v; i <= q; ++i) {
    cin >> k >> x >> y >> v;
    res += (v-a[k][x][y])*a[k^1][y][x];
    a[k][x][y] = v;
    cout << res << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> q) solve();
  /*
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  */
  return 0;
}