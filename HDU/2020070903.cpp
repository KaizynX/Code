/*
 * @Author: Kaizyn
 * @Date: 2020-07-09 18:07:11
 * @LastEditTime: 2020-07-09 18:09:55
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

struct Node {
  string name;
  int num, time;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.num == rhs.num ? lhs.time < rhs.time : lhs.num > rhs.num;
  }
};

int n;
Node a[N];

inline void solve() {
  cin >> n;
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].name >> a[i].num >> a[i].time;
    if (a[i] < a[res]) res = i;
  }
  cout << a[res].name << " " << a[res].num << " " << a[res].time << endl;
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