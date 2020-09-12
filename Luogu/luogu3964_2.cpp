/*
 * @Author: Kaizyn
 * @Date: 2020-09-09 13:26:32
 * @LastEditTime: 2020-09-09 13:36:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;

int n;
int x[N], y[N];

long long calc(int a[]) {
  int m = (1+n)/2;
  nth_element(a+1, a+m, a+n+1);
  long long res = 0, mid = a[m];
  for (int i = 1; i <= n; ++i) res += abs(mid-a[i]);
  return res;
}

signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", x+i, y+i);
    // (x, y) -> (x+y, x-y)
    x[i] += y[i];
    y[i] = x[i]-y[i]-y[i];
  }
  cout << (calc(x)+calc(y))/2 << endl;
  return 0;
}