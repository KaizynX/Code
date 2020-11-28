/*
 * @Author: Kaizyn
 * @Date: 2020-10-24 22:41:21
 * @LastEditTime: 2020-10-24 22:54:29
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
int a[N], fa[N];
vector<int> p[N];
set<int> st[N];

int getf(int x) {
  return x == fa[x] ? x : fa[x] = getf(fa[x]);
}

void merge(int x, int y) {
  int fx = getf(x), fy = getf(y);
  if (fx == fy) return;
  if (st[fx].size() > st[fy].size()) swap(fx, fy);
  fa[fx] = fy;
  st[fy].insert(st[fx].begin(), st[fx].end());
  st[fx].clear();
}

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    int flag = 0;
    for (int &j : p[i]) {
      fa[j] = j;
      st[j].insert(i);
      if (fa[j-1]) merge(j-1, j);
      if (fa[j+1]) merge(j+1, j);
      falg |= (int)st[getf(j)].size() == i;
    }
    if (!flag) return i;
  }
  return n+1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}