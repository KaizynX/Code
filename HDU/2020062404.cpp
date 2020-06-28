/*
 * @Author: Kaizyn
 * @Date: 2020-06-24 18:27:25
 * @LastEditTime: 2020-06-24 18:52:09
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, m;
int a[N];
long long sum[N];

void solve() {
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum[i] = sum[i-1]+a[i];
  }
  for (int i = 1, l, r; i <= m; ++i) {
    cin >> l >> r;
    if (l > r) swap(l, r);
    l = max(1, l);
    r = min(r, n);
    cout << sum[r]-sum[l-1] << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) solve();
  return 0;
}