/*
 * @Author: Kaizyn
 * @Date: 2021-01-07 10:02:31
 * @LastEditTime: 2021-01-07 10:09:00
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

ll vis[N][N][N], dp[N][N][N];

ll f(int a, int b, int c) {
  if (vis[a][b][c]) return dp[a][b][c];
  if (min({a, b, c}) <= 0) return dp[a][b][c] = 1;
  if (max({a, b, c}) > 20) return f(20, 20, 20);
  vis[a][b][c] = 1;
  if (a < b && b < c) return dp[a][b][c] = f(a, b, c-1)+f(a, b-1, c-1)-f(a, b-1, c);
  return dp[a][b][c] = f(a-1, b, c)+f(a-1, b-1, c)+f(a-1, b, c-1)-f(a-1, b-1, c-1);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int a, b, c;
  while (cin >> a >> b >> c) cout << f(a, b, c) << endl;
  return 0;
}
/*
已知w（a,b,c）依次有四种不同的返回值
1）当a,b,c 存在一个小于等于0时返回1
2）当a,b,c 存在一个大于20时返回w(20,20,20)
3）当a<b,且b<c 时返回w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
4）其余情况返回w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
给出a,b,c,求出w(a,b,c)
0<a,b,c<30
*/