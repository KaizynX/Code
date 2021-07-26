/*
 * @Author: Kaizyn
 * @Date: 2021-07-25 23:05:49
 * @LastEditTime: 2021-07-26 00:24:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 10;
// const int M = 1e5+7;
#define log(x) (31-__builtin_clz(x))

int n;
int a[N], sum[1<<N];
#ifdef DEBUG
set<int> st;
#endif

int check() {
  for (int i = 1, j; i < 1<<n; ++i) {
    j = i&-i;
    sum[i] = sum[i^j]+a[log(j)];
    #ifdef DEBUG
    st.insert(sum[i]);
    #endif
    if (sum[i] == 0) return 1;
  }
  return 0;
}

inline bool solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    // a[i] = abs(a[i]);
  }
  // if (n == 1) return a[0] == 0;
  for (int i = 0; i < 1<<n; ++i) {
    for (int j = 0; j < n; ++j) if ((i>>j)&1) a[j] = -a[j];
    if (check()) return 1;
    for (int j = 0; j < n; ++j) if ((i>>j)&1) a[j] = -a[j];
  }
  #ifdef DEBUG
  for (int i : st) cout << i << ' ';
  #endif
  return 0;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}