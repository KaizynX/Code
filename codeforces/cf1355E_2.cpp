/*
 * @Author: Kaizyn
 * @Date: 2020-05-16 21:00:03
 * @LastEditTime: 2020-05-16 22:01:17
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int N = 1e5+7;

int n, add, del, mov;
int a[N];
long long sum[N];

inline long long calc(const int &val) {
  int i = lower_bound(a+1, a+n+1, val)-a;
  long long pre = 1ll*val*(i-1)-sum[i-1];
  long long suf = (sum[n]-sum[i-1])-1ll*val*(n-i+1);
  long long res = pre*add+suf*del;
  long long tmp = min(pre, suf);
  pre -= tmp; suf -= tmp;
  return min(res, pre*add+suf*del+tmp*mov);
}

inline void solve() {
  cin >> n >> add >> del >> mov;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i-1]+a[i];
  }
  long long res = INF;
  int l = 0, r = 1e9;
  while (r-l > 3) {
    int mid = (l+r)>>1;
    if (calc(mid) < calc(mid+1)) r = mid;
    else l = mid+1;
  }
  for (int i = l; i <= r; ++i) res = min(res, calc(i));
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}