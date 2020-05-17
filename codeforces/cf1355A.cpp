/*
 * @Author: Kaizyn
 * @Date: 2020-05-16 19:25:35
 * @LastEditTime: 2020-05-16 20:56:27
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

long long k;
int flag;
long long res;
long long a[N];

inline long long f(long long x) {
  long long y = x;
  int mind = 9, maxd = 0;
  do {
    mind = min(mind, int(x%10));
    maxd = max(maxd, int(x%10));
    x /= 10;
  } while (x);
  // cout << mind << " " << maxd << " " << x+mind*maxd << endl;
  if (mind == 0) {
    flag = 1;
    res = y+mind*maxd;
  }
  return y+mind*maxd;
}

inline void solve() {
  flag = 0;
  cin >> a[1] >> k;
  for (int i = 2; i <= k; ++i) {
    a[i] = f(a[i-1]);
    if (flag) { break; }
  }
  cout << (flag ? res : a[k]) << endl;
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