/*
 * @Author: Kaizyn
 * @Date: 2021-07-22 23:07:48
 * @LastEditTime: 2021-07-22 23:13:50
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
const int N = 1e5+7;

string s, t;
vector<int> v[26];

inline bool solve() {
  cin >> s >> t;
  int n = s.size(), m = t.size();
  for (int i = 0; i < 26; ++i) v[i].clear();
  for (int i = 0; i < n; ++i) {
    v[s[i]-'a'].emplace_back(i);
  }
  for (int i = m-1, l = n; i >= 0; --i) {
    int c = t[i]-'a';
    while (v[c].size() && v[c].back() > l) v[c].pop_back();
    while (v[c].size() && (l-v[c].back())%2 == 0) v[c].pop_back();
    if (v[c].empty()) return false;
    l = v[c].back();
    v[c].pop_back();
  }
  return true;
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