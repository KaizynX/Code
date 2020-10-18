/*
 * @Author: Kaizyn
 * @Date: 2020-10-10 22:48:30
 * @LastEditTime: 2020-10-10 23:16:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, k;
char s[N];

int calc() {
  int res = 0;
  for (int i = 1, cnt = 0; i <= n; ++i) {
    if (s[i] == 'W') ++cnt;
    if (s[i] == 'L' || i == n) {
      if (cnt) res += 2*cnt-1;
      cnt = 0;
    }
  }
  return res;
}

inline int solve() {
  scanf("%d%d%s", &n, &k, s+1);
  int l = 1, r = n;
  vector<int> vec;
  while (l <= r && s[l] == 'L') ++l;
  while (l <= r && s[r] == 'L') --r;
  if (l > r) return max(0, k*2-1);
  for (int i = l, cnt = 0; i <= r; ++i) {
    if (s[i] == 'W') {
      if (cnt) vec.emplace_back(cnt);
      cnt = 0;
    } else {
      ++cnt;
    }
  }
  sort(vec.begin(), vec.end());
  int res = calc();
  for (int &i : vec) {
    if (k >= i) {
      res += 2*i+1;
      k -= i;
    } else {
      res += 2*k;
      k = 0;
      break;
    }
  }
  res += min(k, l-1+n-r)*2;
  return res;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("%d\n", solve());
  }
  return 0;
}