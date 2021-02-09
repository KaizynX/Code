/*
 * @Author: Kaizyn
 * @Date: 2021-02-03 16:31:49
 * @LastEditTime: 2021-02-03 17:16:19
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
const int N = 1e5+7;
const string ans[2] = {"First", "Second"};

int n;
int a[N];

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  return rand()%2;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  if (T == 1) {
    cout << ans[0] << endl;
    return 0;
  }
  for (int t = 1; t <= T; ++t) {
    cout << ans[solve()] << endl;
  }
  return 0;
}