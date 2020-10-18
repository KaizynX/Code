/*
 * @Author: Kaizyn
 * @Date: 2020-10-17 21:01:44
 * @LastEditTime: 2020-10-17 22:10:43
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
int a[N], y[N];
vector<pii> res;
vector<int> vec;

inline bool solve() {
  res.clear();
  vec.clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int cnt = n;
  for (int i = n; i; --i) {
    if (a[i] == 1) {
      y[i] = cnt--;
      res.emplace_back(y[i], i);
      vec.push_back(i);
    } else if (a[i] == 2) {
      if (vec.empty()) return false;
      y[i] = y[vec.back()];
      vec.pop_back();
      res.emplace_back(y[i], i);
    }
  }
  for (int i = 1; i <= n; ++i) if (a[i] == 2) vec.push_back(i);
  sort(vec.begin(), vec.end());
  for (int i = n; i; --i) if (a[i] == 3) {
    if (vec.empty() || vec.back() < i) return false;
    res.emplace_back(cnt, i);
    res.emplace_back(cnt, vec.back());
    cnt--;
    vec.pop_back();
    vec.push_back(i);
  }
  cout << res.size() << endl;
  for (auto &p : res) cout << p.first << " " << p.second << endl;
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    if (!solve()) cout << -1 << endl;
  }
  return 0;
}