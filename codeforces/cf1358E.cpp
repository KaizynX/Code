/*
 * @Author: Kaizyn
 * @Date: 2020-05-27 00:04:52
 * @LastEditTime: 2020-05-27 19:17:39
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n;
int a[N], b[N];
long long suf_sum[N];

inline solve() {
  cin >> n;
  for (int i = 1; i <= (n+1)/2; ++i) cin >> a[i];
  cin >> a[n];
  for (int i = (n+1)/2+1; i < n; ++i) a[i] = a[n];
  for (int i = n; i; --i) {
    b[i] = a[i]-a[n];
    suf_sum[i] = suf_sum[i+1]+a[i];
  }
  // k >= (n+1)/2
  long long cur = 0;
  for (int i = 0; i <= n/2; ++i) {
    cur += b[i];
    #ifdef DEBUG
    cout << cur << " " << suf_sum[i+1] << endl;
    #endif
    if (suf_sum[i+1] > 0 && suf_sum[i+1]+cur > 0) return n-i;
  }
  return -1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}