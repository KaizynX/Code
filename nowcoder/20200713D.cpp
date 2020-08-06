/*
 * @Author: Kaizyn
 * @Date: 2020-07-13 12:03:11
 * @LastEditTime: 2020-07-13 12:06:44
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

struct Time {
  int h, m, s;
  friend bool operator <(const Time &t1, const Time &t2) {
    if (t1.h != t2.h) return t1.h < t2.h;
    if (t1.m != t2.m) return t1.m < t2.m;
    return t1.s < t2.s;
  }
};

Time t1, t2;

inline void solve() {
  scanf("%d:%d:%d", &t1.h, &t1.m, &t1.s);
  scanf("%d:%d:%d", &t2.h, &t2.m, &t2.s);
  if (t2 < t1) swap(t1, t2);
  int res = 0;
  // t2-t1
  if (t2.s < t1.s) --t2.m, t2.s += 60;
  res += t2.s-t1.s;
  if (t2.m < t1.m) --t2.h, t2.m += 60;
  res += (t2.m-t1.m)*60;
  res += (t2.h-t1.h)*3600;
  printf("%d\n", res);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}