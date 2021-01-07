/*
 * @Author: Kaizyn
 * @Date: 2021-01-07 10:11:58
 * @LastEditTime: 2021-01-07 10:15:13
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

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T, a, b, c, d[3];
  cin >> T;
  while (T--) {
    for (int i = 0; i < 3; ++i) cin >> d[i];
    sort(d, d+3);
    a = d[0]; b = d[1]; c = d[2];
    if (a+b <= c) cout << "Impossible!\n";
    else if (a*a+b*b == c*c) cout << "Right triangle\n";
    else if (a*a+b*b > c*c) cout << "Acute triangle\n";
    else if (a*a+b*b < c*c) cout << "Obtuse triangle\n";
  }
  return 0;
}
/*
如果能够组成直角三角形，请输出 "Right triangle" ；
如果能够组成锐角三角形，请输出 "Acute triangle" ；
如果能够组成钝角三角形，请输出 "Obtuse triangle" ；
如果不能组成三角形，请输出"Impossible!"；
*/