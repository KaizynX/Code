/*
 * @Author: Kaizyn
 * @Date: 2020-07-24 22:22:54
 * @LastEditTime: 2020-07-25 10:10:17
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
int a[N];

inline void solve() {
  cin >> n;
  int s = 0;
  int cnt[2] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s ^= a[i];
  }
  if (!s) return cout << "DRAW" << endl, void();
  int b = 1<<(31-__builtin_clz(s));
  for (int i = 1; i <= n; ++i) ++cnt[bool(a[i]&b)];
  if (cnt[1]%4 == 3 && cnt[0]%2 == 0) cout << "LOSE" << endl;
  else cout << "WIN" << endl;
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