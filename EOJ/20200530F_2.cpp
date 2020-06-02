/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 15:24:29
 * @LastEditTime: 2020-05-30 16:30:02
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
int g[N];
long long a[N];

bool check(int x, int y) {
  bool res = true;
  for (int i = 1; i <= n; ++i) {
    if (__gcd(a[i], a[y]) != 1 && g[i] == g[x]) {
      res = false;
    }
  }
  return res;
}

int solve() {
  int cnt = 0;
  memset(g, 0, sizeof g);
  for (int i = 1; i <= n; ++i) {
    if (g[i] != 0) continue;
    g[i] = ++cnt;
    for (int j = i+1; j <= n; ++j) {
      if (g[j] == 0 && check(i, j)) g[j] = cnt;
    }
  }
  return cnt;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}