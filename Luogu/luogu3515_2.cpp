/*
 * @Author: Kaizyn
 * @Date: 2020-08-01 23:41:23
 * @LastEditTime: 2020-08-02 14:12:18
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
int a[N];
double p[N];
int q[N], head, tail;
// a[j] <= a[i]+p-sqrt(|i-j|)
// p >= a[j]-a[i]+sqrt(|i-j|)

double f(const int &i, const int &j) {
  return a[j]+sqrt(abs(i-j));
}

signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  // suppose j <= i
  // p[i] = max{a[j]+sqrt(i-j)}-a[i]
  head = tail = 0;
  for (int i = 1; i <= n; ++i) {
    while (tail-head >= 2 && f(i, q[head]) < f(i, q[head+1])) ++head;
    if (head == tail || a[i] > a[q[tail-1]]) q[++tail] = i;
    p[i] = f(i, q[head])-a[i];
  }
  // suppose j >= i
  // p[i] = max{a[j]+sqrt(j-i)}-a[i]
  head = tail = 0;
  for (int i = n; i; --i) {
    while (tail-head >= 2 && f(i, q[head]) < f(i, q[head+1])) ++head;
    if (head == tail || a[i] > a[q[tail-1]]) q[++tail] = i;
    p[i] = max(p[i], f(i, q[head])-a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", (int)ceil(p[i]));
  }
  return 0;
}