/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 15:56:40
 * @LastEditTime: 2020-06-13 16:25:27
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

int n, q;
long long m, k;
long long sum[64];
int a[N], cnt[64];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 0; j <= 30; ++j) {
      cnt[j] += (a[i]>>j)&1;
    }
  }
  #ifdef DEBUG
  for (int i = 0; i <= 30; ++i) {
    cout << cnt[i] << " \n"[i==30];
  }
  #endif
  for (int i = 0; i <= 50; ++i) {
    sum[i+1] = sum[i]+min(cnt[i], n-cnt[i])*(1ll<<i);
  }
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> m;
    k = 0;
    /*
    for (int j = 50; j > 30; --j) {
      if ((1ll<<j) <= (m-sum[31])/n) {
        k += 1ll<<j;
        m -= (1ll<<j)*n;
      }
    }
    */
    for (int j = 50; j >= 0 && m >= 0; --j) {
      // if ((1ll<<j)*(n-cnt[j])+sum[j] <= m) {
      if (cnt[j] == n || (1ll<<j) <= (m-sum[j])/(n-cnt[j])) {
        k += 1ll<<j;
        m -= (1ll<<j)*(n-cnt[j]);
      } else {
        m -= (1ll<<j)*cnt[j];
      }
    }
    cout << (m >= 0 ? k : -1) << endl;
  }
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