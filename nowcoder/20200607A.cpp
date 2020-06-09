/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 13:00:30
 * @LastEditTime: 2020-06-07 13:02:34
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

struct Node {
  int id, v;
  friend bool operator <(const Node &l, const Node &r) {
    if (l.v != r.v) return l.v > r.v;
    else return l.id < r.id;
  }
};

int n;
Node a[N];

inline void solve() {
  cin >> n;
  for (int i = 1, r, g, b; i <= n; ++i) {
    cin >> a[i].id >> r >> g >> b;
    a[i].v = r+2*g+3*b;
  }
  sort(a+1, a+n+1);
  cout << a[1].id << " " << a[1].v << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}