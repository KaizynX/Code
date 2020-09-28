/*
 * @Author: Kaizyn
 * @Date: 2020-09-26 13:47:38
 * @LastEditTime: 2020-09-26 13:51:48
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
// int a[N];
map<int, int> mp;

inline int solve() {
  mp.clear();
  cin >> n;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    ++mp[a];
  }
  for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    int x = it->first, t = it->second;
    if (x == mp.begin()->first) return t%2 ? -1 : x;
    else if (t&1) return x;
  }
  return -1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}