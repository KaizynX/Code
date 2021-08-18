/*
 * @Author: Kaizyn
 * @Date: 2021-08-18 22:42:44
 * @LastEditTime: 2021-08-18 23:02:22
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
#define log(x) (31-__builtin_clz(x))
const int N = 20;

int n, k;
int has[N];
string s;

int get_nex(int bit, int x) {
  if (x == 9) return -1;
  if (__builtin_popcount(bit) < k) return x+1;
  for (int i = x+1; i < 10; ++i) {
    if ((bit>>i)&1) return i;
  }
  return -1;
}

int get_min(int bit) {
  if (__builtin_popcount(bit) < k) return 0;
  for (int i = 0; i < 10; ++i) {
    if ((bit>>i)&1) return i;
  }
  return -1;
}

inline void solve() {
  cin >> s >> k;
  n = s.size();
  has[0] = 0;
  for (int i = 1, c; i <= n; ++i) {
    c = s[i-1]-'0';
    has[i] = has[i-1]|(1<<c);
    #ifdef DEBUG
    cout << bitset<10>(has[i]) << " \n"[i==n];
    #endif
  }
  if (__builtin_popcount(has[n]) <= k) {
    cout << s << '\n';
    return;
  }
  for (int i = n; i; --i) {
    // 前i-1位相同,第i位开始 >
    if (__builtin_popcount(has[i-1]) > k) continue;
    int nex = get_nex(has[i-1], s[i-1]-'0');
    if (nex == -1) continue;
    // find the sol
    for (int j = 1; j < i; ++j) cout << s[j-1];
    cout << nex;
    nex = get_min(has[i-1]|(1<<nex));
    for (int j = i+1; j <= n; ++j) cout << nex;
    cout << '\n';
    return;
  }
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