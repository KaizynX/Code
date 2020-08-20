/*
 * @Author: Kaizyn
 * @Date: 2020-08-17 00:31:56
 * @LastEditTime: 2020-08-17 00:49:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
long long sum;
long long a[N], b[N];

signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a+i);
    sum += a[i];
  }
  for (int i = 2; i <= n; ++i) {
    b[i] = a[i]-a[i-1];
    b[i] &= 1;
    b[i] += b[i-1];
    sum -= b[i];
  }
  assert(sum%n == 0);
  sum /= n;
  for (int i = 1; i <= n; ++i) {
    printf("%lld%c", sum+b[i], " \n"[i==n]);
  }
  return 0;
}