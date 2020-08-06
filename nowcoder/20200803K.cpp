/*
 * @Author: Kaizyn
 * @Date: 2020-08-03 11:58:46
 * @LastEditTime: 2020-08-03 12:55:44
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
int a[N], b[N], cnt[N];
int q[N], head, tail;
long long sum[N], res;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];

  head = tail = 0;
  sum[1] = a[1]; cnt[1] = b[1]; q[++tail] = 1;
  for (int i = 2; i <= n; ++i) {
    sum[i] = sum[i-1]+a[i];
    cnt[i] = min(cnt[i-1], b[i]);
    if (sum[i] > sum[q[tail]]) q[++tail] = i;
  }
  res = 0;
  for (int base = 0, i, num; head < tail; --tail) {
    i = q[tail];
    num = cnt[i]-base;
    res += num*sum[i];
    base += num;
    /*
    while (head < tail && cnt[q[tail]] <= base) --tail;
    if (head >= tail) break;
    int num = cnt[q[tail]]-base;
    res += num*sum[q[tail]];
    base += num;
    --tail;
    */
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    cout << "Case #" << t << ": " << b[1] << " " << res << endl;
  }
  return 0;
}