/*
 * @Author: Kaizyn
 * @Date: 2020-08-17 00:31:56
 * @LastEditTime: 2020-08-17 01:09:12
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
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

long long a[N], b[N], c[N], d[N];

bool f(const int &n) {
  int flag = 0;
  memset(c, 0, sizeof(int)*n);
  for (int i = 1; i < n; ++i) {
    if (b[i] >= 2) {
      ++c[i-1];
      ++c[i+1];
      b[i] -= 2;
      flag = 1;
    }
    c[i] += b[i];
  }
  memcpy(b, c, sizeof(int)*n);
  return flag;
}

void print(long long *arr, const int &n) {
  for (int i = 1; i <= n; ++i) printf("%lld%c", arr[i], " \n"[i==n]);
}

bool f2(const int &n) {
  int flag = 0;
  memset(c, 0, sizeof(int)*n);
  for (int i = 1; i < n; ++i) {
    if (a[i+1]-a[i] > 2) {
      c[i] = 1;
      flag = 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (c[i]) {
      a[i]++;
      a[i+1]--;
    }
  }
  return flag;
}

void brute(const int &n) {
  a[0] = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i-1]+rnd()%10;
    // a[i] = a[i-1]+3+rnd()%7;
    b[i-1] = a[i]-a[i-1];
    d[i-1] = b[i-1]&1;
  }
  print(a, n);
  print(b, n-1);
  while (f(n));
  print(b, n-1);
  // for (int i = 1; i < n; ++i) assert(d[i] == b[i]);
}

signed main() {
  // scanf("%d", &n);
  int t = 1;
  cin >> t;
  while (t--) brute(10);
  return 0;
}