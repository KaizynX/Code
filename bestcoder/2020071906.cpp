/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 19:39:16
 * @LastEditTime: 2020-07-19 20:22:27
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 10;

int a[N];
long long k;

inline long long calc(const long long &l, const long long &d) {
  if (2*l <= d) return (l*2+1)*(l*2+1);
  if (d <= l) return 1+(d+1)*d*2;
  return (l*2+1)*(l*2+1)-(1+2*l-d)*(2*l-d)*2;
}

inline long long count(const long long &mid) {
  long long cnt = 0;
  for (int i = 4; i; --i) {
    long long d = mid/i;
    cnt += calc(a[i], d)-calc(a[i+1], d);
  }
  return cnt+1; // +(0, 0)
}

inline void solve() {
  a[5] = 0;
  for (int i = 4; i; --i) cin >> a[i];
  cin >> k;
  if (k == 0) return cout << 0 << endl, void();
  long long l = 0, r = 4e9, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (count(mid) >= k) r = mid;
    else l = mid+1;
  }
  cout << l << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  /*
  for (int i = 1; i <= 5; ++i) {
    for (int j = 0; j <= 2*i; ++j) {
      cout << i << " " << j << " " << calc(i, j) << endl;
    }
  }
  */
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}