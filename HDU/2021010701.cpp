/*
 * @Author: Kaizyn
 * @Date: 2021-01-07 10:17:18
 * @LastEditTime: 2021-01-07 10:19:32
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

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  ll n, res, k, p[4] = {2, 3, 5, 7};
  while (cin >> n && n) {
    res = 1;
    for (int i = 0; i < 4; ++i) {
      k = 1;
      while (n%p[i] == 0) n /= p[i], ++k;
      res *= k;
    }
    cout << res << endl;
  }
  return 0;
}
/*
一个数，如果他的素数因子只包括2,3,5,7，则称这个数为萌数
*/