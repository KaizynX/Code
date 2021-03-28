/*
 * @Author: Kaizyn
 * @Date: 2021-03-26 21:09:30
 * @LastEditTime: 2021-03-26 21:20:22
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
const int N = 1e2+7;

int n;
int a[N];

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int i = 1; i < n; ++i) {
    int k = i;
    for (int j = i; j <= n; ++j) {
      if (a[j] < a[k]) k = j;
    }
    res += k-i+1;
    reverse(a+i, a+k+1);
  }
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << '\n';
  }
  return 0;
}