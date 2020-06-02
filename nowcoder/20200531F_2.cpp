/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 15:37:47
 * @LastEditTime: 2020-05-31 16:45:54
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e2+7;

ull a;
ull b[N];

inline int solve() {
  cin >> a;
  if (a == 1) return 1;
  b[1] = b[2] = 1;
  a -= 2;
  for (int i = 3; ; ++i) {
    if (a < b[i-1] || a-b[i-1] < b[i-2]) return i-1;
    b[i] = b[i-1]+b[i-2];
    a -= b[i];
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}