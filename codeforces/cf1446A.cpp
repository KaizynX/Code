/*
 * @Author: Kaizyn
 * @Date: 2020-11-15 22:25:24
 * @LastEditTime: 2020-11-15 22:45:39
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
long long w;
int a[N], rk[N];

inline void solve() {
  cin >> n >> w;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  // sort(a+1, a+n+1);
  long long sum = 0, w2 = (w+1)/2;;
  for (int i = 1; i <= n; ++i) if (a[i] <= w) {
    sum += a[i];
    if (a[i] >= w2) {
      cout << 1 << endl << i << endl;
      return;
    }
  }
  if (sum < w2) return cout << -1 << endl, void();
  for (int i = 1; i <= n; ++i) rk[i] = i;
  sort(rk+1, rk+n+1, [](int x, int y) { return a[x] < a[y]; });
  vector<int> res;
  sum = 0;
  for (int i = 1; i <= n; ++i) {
    res.push_back(rk[i]);
    sum += a[rk[i]];
    if (sum >= w2) break;
  }
  if (sum >= w2 && sum <= w) {
    cout << res.size() << endl;
    for (int &i : res) cout << i << " ";
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}