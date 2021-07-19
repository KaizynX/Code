/*
 * @Author: Kaizyn
 * @Date: 2021-07-19 13:29:32
 * @LastEditTime: 2021-07-19 13:39:24
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
const int N = 8e4+7;
template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}
int n, k;
ll P;
__int128_t res;
int a[N];

void dfs(int x, int l = 0, int g = 0) {
  if (x > k) {
    res = res*g%P;
    return;
  }
  for (int i = l+1; i <= n; ++i) {
    dfs(x+1, i, __gcd(g, a[i]));
  }
}

inline void solve() {
  cin >> n >> k >> P;
  res = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  dfs(1);
  write(res); puts("");
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}