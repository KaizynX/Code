/*
 * @Author: Kaizyn
 * @Date: 2020-08-01 23:41:23
 * @LastEditTime: 2020-08-02 13:59:59
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n;
int a[N];
int k1[N], k2[N];
// a[j] <= a[i]+p-sqrt(|i-j|)
// p >= a[j]-a[i]+sqrt(|i-j|)

double f(const int &i, const int &j) {
  return a[i]-a[j]-sqrt(abs(i-j));
}

// suppose j <= i
// p = -min{a[i]-a[j]-sqrt(i-j)}
void solve1(const int &l, const int &r, const int &kl, const int &kr) {
  if (l > r) return;
  int mid = (l+r)>>1;
  k1[mid] = mid;
  for (int i = kl; i < mid && i <= kr; ++i) {
    if (f(mid, i) < f(mid, k1[mid])) k1[mid] = i;
  }
  solve1(l, mid-1, kl, k1[mid]);
  solve1(mid+1, r, k1[mid], kr);
}

// suppose j >= i
// p = -min{a[i]-a[j]-sqrt(j-i)}
void solve2(const int &l, const int &r, const int &kl, const int &kr) {
  if (l > r) return;
  int mid = (l+r)>>1;
  k2[mid] = mid;
  for (int i = kr; i > mid && i >= kl; --i) {
    if (f(mid, i) < f(mid, k2[mid])) k2[mid] = i;
  }
  solve2(l, mid-1, kl, k2[mid]);
  solve2(mid+1, r, k2[mid], kr);
}

signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  solve1(1, n, 1, n);
  solve2(1, n, 1, n);
  for (int i = 1; i <= n; ++i) {
    #ifdef DEBUG
    printf("%d %d | ", k1[i], k2[i]);
    #endif
    printf("%d\n", (int)ceil(-min(f(i, k1[i]), f(i, k2[i]))));
  }
  return 0;
}
/*
6
4 5 0 1 3 0
*/