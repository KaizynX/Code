/*
 * @Author: Kaizyn
 * @Date: 2021-05-02 13:18:14
 * @LastEditTime: 2021-05-02 13:24:53
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 10;

int a[N];

inline int solve() {
  int res = 0;
  for (int i = 0; i < 1<<3; ++i) {
    int b1 = i&1, b2 = (i>>1)&1, b3 = (i>>2)&1;
    res += (!(a[1]^a[4])||(b1|b2))
        &  (!(a[2]^a[5])||(b1|b3))
        &  (!(a[3]^a[6])||(b2|b3));
  }
  return res;
}

void print(int a[], int n = 6) {
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int cnt[10];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < 1<<6; ++i) {
    for (int j = 0; j < 6; ++j) a[j+1] = (i>>j)&1;
    int res = solve();
    if (res == 5) print(a);
    ++cnt[res];
  }
  print(cnt, 8);
  return 0;
}
/*
8
false false false false false false
true true true true true true
false true false false true false

4
false true true true false false
*/