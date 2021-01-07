/*
 * @Author: Kaizyn
 * @Date: 2021-01-07 10:20:22
 * @LastEditTime: 2021-01-07 10:28:52
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 50;

int n;
ll add[N], del[N];

inline void solve() {
  cin >> n;
  ll res = 0;
  memset(add, 0, sizeof(add));
  memset(del, 0, sizeof(del));
  add[1] = 1;
  for (int i = 1; i <= n; ++i) {
    res += add[i]-del[i];
    add[i+2] += 4*add[i];
    add[i+3] += 4*add[i];
    add[i+4] += 4*add[i];
    del[i+5] += add[i];
  }
  cout << res << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
/*
在2010年1月1日，他买了一只刚出生的母猪幼仔，假设每只小母猪从第3个年头开始，每年的第一天都会生出4只小母猪
，同时，钱哥会在每年的12月31日售出所有差一天就要年满5周岁的猪。
请计算：在第N年（2010年是第1年，2011是第2年，依次类推）的今天（5月4日），钱哥的养猪场会存栏多少只猪?
*/