/*
 * @Author: Kaizyn
 * @Date: 2020-09-27 23:03:40
 * @LastEditTime: 2020-09-27 23:41:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e4+7;
const int M = 1e5+7;

struct Node {
  int i, j, x;
};

int n;
int a[N];
vector<Node> res;

inline void solve() {
  cin >> n;
  long long target = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    target += a[i];
  }
  if (target%n) return cout << -1 << endl, void();
  res.clear();
  target /= n;
  for (int i = 2, x; i <= n; ++i) {
    x = a[i]/i;
    a[1] += x*i;
    a[i] -= x*i;
    res.push_back(Node{i, 1, x});
  }
  for (int i = 2, x; i <= n; ++i) {
    if (a[i] > target) {
      // a[i]+x-i == target
      x = target+i-a[i];
      if (x > a[1]) return cout << -1 << endl, void();
      res.push_back(Node{1, i, x});
      res.push_back(Node{i, 1, 1});
      a[i] = target;
      a[1] += -x+i;
    }
  }
  for (int i = 2, x; i <= n; ++i) {
    if (a[i] < target) {
      x = target-a[i];
      if (x > a[1]) return cout << -1 << endl, void();
      res.push_back(Node{1, i, x});
      a[i] = target;
      a[1] -= x;
    }
  }
  assert((int)res.size() <= 3*n);
  for (int i = 1; i <= n; ++i) assert(a[i] == target);
  cout << res.size() << endl;
  for (auto &r : res) {
    cout << r.i << " " << r.j << " " << r.x << endl;
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