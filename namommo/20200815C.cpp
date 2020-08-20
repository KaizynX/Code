/*
 * @Author: Kaizyn
 * @Date: 2020-08-15 19:15:20
 * @LastEditTime: 2020-08-15 19:26:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n;
int a[N], cnt[2];

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++cnt[a[i]&1];
  }
  // n-1 turns
  if (n == 1) return cnt[0];
  if (n%2 == 1 || cnt[0] == n) return 1;
  return (cnt[1]+1)/2 <= (n-2)/2;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}