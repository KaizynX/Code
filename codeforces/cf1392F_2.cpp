/*
 * @Author: Kaizyn
 * @Date: 2020-08-17 00:31:56
 * @LastEditTime: 2020-08-19 15:41:12
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
long long a[N];

signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a+i);
    sum += a[i];
  }
  sum -= (n-1ll)*n/2;
  for (int i = 1; i <= n; ++i) {
    printf("%lld%c", i+sum/n-(sum%n < i), " \n"[i==n]);
  }
  return 0;
}