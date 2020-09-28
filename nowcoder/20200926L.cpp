/*
 * @Author: Kaizyn
 * @Date: 2020-09-26 15:40:16
 * @LastEditTime: 2020-09-26 15:41:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
char s[N];

inline void solve() {
  n = strlen(s+1);
}

signed main() {
  while (gets(s+1) && s[1] != '#') solve();
  return 0;
}