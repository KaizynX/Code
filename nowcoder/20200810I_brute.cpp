/*
 * @Author: Kaizyn
 * @Date: 2020-08-10 14:11:52
 * @LastEditTime: 2020-08-10 16:03:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e2+7;

int n;
vector<pii> vec;

void print(const vector<pii> &v) {
  for (const pii &p : v) {
    printf("(%d,%d)", p.first, p.second);
  }
  puts("");
}

// int f(auto &vec) {
int f() {
  static int st[N], cnt[N];
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    st[i] = -1;
    cnt[i] = 0;
  }
  for (int i = 0; i < (int)vec.size(); ++i) {
    int x = vec[i].first, y = vec[i].second;
    if (st[x] == -1) st[x] = i;
    if (st[y] == -1) st[y] = i;
    if (++cnt[x] == n-1) res += i-st[x]+1;
    if (++cnt[y] == n-1) res += i-st[y]+1;
  }
  return res;
}

inline void solve() {
  n = 7;
  /*
  vec.emplace_back(1, 2);
  vec.emplace_back(1, 3);
  vec.emplace_back(2, 3);
  for (int i = 4; i <= n; ++i) vec.emplace_back(1, i);
  for (int i = 2; i <= n; ++i) {
    for (int j = i == 2 ? 4 : i+1; j <= n; ++j) {
      vec.emplace_back(i, j);
    }
  }
  */
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      vec.emplace_back(i, j);
    }
  }
  int res = INF;
  do {
    int cost = f();
    if (cost < res) {
    // if (cost == 33) {
      res = cost;
      cout << res << endl;
      print(vec);
    }
  } while (next_permutation(vec.begin()+1, vec.end()));
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}