/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 15:39:16
 * @LastEditTime: 2020-05-30 15:50:07
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e7+7;

int n, p;
long long x, y, z, A;
long long b[N];
int q[N], tail = 0;

inline void solve() {
  cin >> n >> p >> x >> y >> z >> b[1];
  long long sum = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    while (tail && b[q[tail]] >= b[i]) {
      sum -= (q[tail]-q[tail-1])*b[q[tail]];
      --tail;
    }
    sum += (i-q[tail])*b[i];
    sum = (sum%MOD+MOD)%MOD;
    q[++tail] = i;
    (A += sum) %= MOD;
    b[i+1] = (x*A+y*b[i]+z)%p;
    res ^= A;
  }
  cout << res << endl;
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