/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 14:30:55
 * @LastEditTime: 2020-05-31 14:33:52
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

int n;
int a[N];
int q[N], tail;

inline void solve() {
  tail = 0;
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    --a[i];
    if (a[i] > q[tail]) res += a[i]-q[tail];
    while (tail && q[tail] >= a[i]) --tail;
    q[++tail] = a[i];
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}