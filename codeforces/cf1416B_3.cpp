/*
 * @Author: Kaizyn
 * @Date: 2020-09-27 23:03:40
 * @LastEditTime: 2020-09-28 13:38:27
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

bool add_res(int i, int j, int x) {
  if (!x) return true;
  if (a[i] < i*x) return false;
  a[i] -= i*x;
  a[j] += i*x;
  res.push_back(Node{i, j, x});
  return true;
}

inline void solve() {
  cin >> n;
  int target = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    target += a[i];
  }
  if (target%n) return cout << -1 << endl, void();
  res.clear();
  target /= n;
  for (int i = 2; i <= n; ++i) {
    add_res(1, i, (i-a[i]%i)%i);
    add_res(i, 1, a[i]/i);
  }
  for (int i = 2; i <= n; ++i) {
    add_res(1, i, target);
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