/*
 * @Author: Kaizyn
 * @Date: 2020-07-22 15:28:04
 * @LastEditTime: 2020-07-22 19:19:27
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;

int n, L;
int c[N];
long long s[N], dp[N];
long long x[N], y[N];
int q[N], head, tail;
/*************************************
 * dp[i] = dp[j]+(s[i]-s[j]+i-j-1-L)^2
 * y = kx+b
 * dp[j]+(s[j]+j+L+1)^2 = 2(s[i]+i)(s[j]+j+L+1)+dp[i]-(s[i]+i)^2
 * y = dp[j]+(s[j]+j+L+1)^2
 * k = 2(s[i]+i)
 * x = s[j]+j+L+1
 * b = dp[i]-(s[i]+i)^2
 *************************************/

inline long double slope(const int &i, const int &j) {
  return (long double)(y[j]-y[i])/(x[j]-x[i]);
}

inline void solve() {
  cin >> n >> L;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    s[i] = s[i-1]+c[i];
  }
  x[0] = L+1;
  y[0] = (L+1ll)*(L+1ll);
  q[++tail] = 0;
  for (int i = 1; i <= n; ++i) {
    long long k = 2*(s[i]+i);
    /*
    while (tail-head >= 2 && 
        (y[q[head+2]]-y[q[head+1]]) <= 
        k*(x[q[head+2]]-x[q[head+1]])) ++head;
    long long b = y[q[head+1]]-k*y[q[head+1]];
    dp[i] = b+(s[i]+i)*(s[i]+i);
    while (tail-head >= 2 && 
        (y[i]-y[q[tail]])*(x[q[tail]]-x[q[tail-1]]) >= 
        (y[q[tail]]-y[q[tail-1]])*(x[i]-x[q[tail]])) --tail;
    */
    while (tail-head >= 2 && slope(q[head+1], q[head+2]) <= k) ++head;
    int j = q[head+1];
    dp[i] = dp[j]+(s[i]-s[j]+i-j-1-L)*(s[i]-s[j]+i-j-1-L);
    x[i] = s[i]+i+L+1;
    y[i] = dp[i]+(s[i]+i+L+1)*(s[i]+i+L+1);
    while (tail-head >= 2 && slope(q[tail], i) <= slope(q[tail-1], q[tail])) --tail;
    q[++tail] = i;
  }
  cout << dp[n] << endl;
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