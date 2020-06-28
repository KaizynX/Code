/*
 * @Author: Kaizyn
 * @Date: 2020-06-25 23:01:30
 * @LastEditTime: 2020-06-26 18:33:55
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int sum[N], vis[N];
int res[200][20];

inline int f(long long x) {
  int res = 0;
  while (x) {
    res += x%10;
    x /= 10;
  }
  return res;
}

inline void init() {
  memset(res, -1, sizeof res);
  sum[0] = 0;
  for (int i = 1; i < N; ++i) {
    sum[i] = sum[i-1]+f(i);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  init();
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> n >> k;
    cout << res[n][k] << endl;
  }
  return 0;
}