/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 12:55:24
 * @LastEditTime: 2020-09-06 13:00:39
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

int n, m, p1, p2, s1, s2;
int a[N];
long long v[N], sum1, sum2;

long long calc(int p) {
  if (p < m) return abs(1ll*abs(p-m)*s2+sum1-sum2);
  if (p > m) return abs(1ll*abs(p-m)*s2+sum2-sum1);
  return abs(sum1-sum2);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> m >> p1 >> s1 >> s2;
  a[p1] += s1;
  for (int i = 1; i <= n; ++i) {
    v[i] = 1ll*abs(i-m)*a[i];
    if (i < m) sum1 += v[i];
    if (i > m) sum2 += v[i];
  }
  p2 = m;
  for (int i = 1; i <= n; ++i) if (i != m) {
    if (calc(i) < calc(p2)) p2 = i;
  }
  cout << p2 << endl;
  return 0;
}