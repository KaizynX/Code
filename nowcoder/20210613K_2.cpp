/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 13:08:34
 * @LastEditTime: 2021-06-13 13:10:11
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
const int N = 20;

int n;
int a[N], b[N], c[N];

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int i = 1; i <= n; ++i) c[i] = i;
  int res = 0;
  do {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      cnt += __gcd(a[i], b[c[i]]) > 1;
    }
    res = max(res, cnt);
  } while (next_permutation(c+1, c+n+1));
  cout << res << '\n';
  return 0;
}