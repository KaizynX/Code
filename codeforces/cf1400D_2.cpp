/*
 * @Author: Kaizyn
 * @Date: 2020-08-25 23:03:29
 * @LastEditTime: 2020-08-26 00:02:59
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e3+7;

int n;
int a[N], precnt[N], sufcnt[N];
long long presum[N][N], sufsum[N][N];

long long C(int p, int q) {
  if (p < q) return 0;
  long long res = 1;
  for (int i = 0; i < q; ++i) res *= p-i;
  for (int i = 2; i <= q; ++i) res /= i;
  return res;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    precnt[i] = sufcnt[i] = 0;
    for (int j = 1; j <= n; ++j) {
      presum[i][j] = sufsum[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++precnt[a[i]];
    for (int j = 1; j <= n; ++j) {
      presum[j][a[i]] += precnt[j];
    }
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    res += C(precnt[i], 4);
  }
  for (int i = n; i; --i) {
    // [1, i-1] | [i, n]
    ++sufcnt[a[i]];
    --precnt[a[i]];
    for (int j = 1; j <= n; ++j) {
      sufsum[a[i]][j] += sufcnt[j];
      presum[j][a[i]] -= precnt[j];
    }
    for (int j = 1; j <= n; ++j) if (j != a[i]) {
      // res += presum[a[i]][j]*sufsum[a[i]][j];
      res += presum[a[i]][j]*sufcnt[j];
    }
  }
  cout << res << endl;
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