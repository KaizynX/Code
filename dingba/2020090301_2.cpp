/*
 * @Author: Kaizyn
 * @Date: 2020-09-03 19:00:05
 * @LastEditTime: 2020-09-03 21:50:03
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
int dis[N][N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> dis[i][j];
    }
  }
  int res = n*(n-1)/2;
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) if (i != k && j != k) {
        if (dis[i][j] == dis[i][k]+dis[k][j]) {
          --res;
          break;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}