/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 14:34:36
 * @LastEditTime: 2020-05-30 15:21:35
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
const int prime[] = {0,2,3,5,7,11,13,19,23,29,31,37,41,43,47,53,59,61,67};

int k, n;
int g[N];
long long a[N];

inline void solve() {
  cin >> k;
  if (k == 1) return cout << "4 2\n8 3 45 100\n1 2 1 2\n", void();
  n = 3*k;
  long long mul = 1;
  for (int i = 1; i <= 2*k; ++i) mul *= prime[i];
  /*
  for (int i = 1; i <= k; ++i) {
    a[i*3-2] = prime[(k-i)*2+1];
    g[i*3-2] = k-i+1;
    a[i*3-1] = prime[(k-i)*2+2];
    g[i*3-1] = k-i+1;
    a[i*3] = mul/prime[i*2-1]/prime[i*2];
    g[i*3] = i;
  }
  */
  for (int i = 1; i <= k; ++i) {
    a[i*3] = mul/prime[i*2-1]/prime[i*2];
    g[i*3] = i;
    a[i*3-1] = prime[i*2+1];
    g[i*3-1] = i+1;
    a[i*3+1] = prime[i*2+2];
    g[i*3+1] = i+1;
  }
  a[1] = prime[2];
  g[1] = 1;
  a[3*k-1] = prime[1];
  g[3*k-1] = 1;
  cout << n << " " << k << endl;
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << g[i] << " \n"[i==n];
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