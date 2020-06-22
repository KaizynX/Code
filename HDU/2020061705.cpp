/*
 * @Author: Kaizyn
 * @Date: 2020-06-17 18:42:20
 * @LastEditTime: 2020-06-17 18:51:00
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

int n, rt, m;
int v[N], l[N], r[N];

void add_point(int &x, const int &val) {
  if (!x) {
    x = ++m;
    v[x] = val;
    return;
  }
  if (val < v[x]) add_point(l[x], val);
  if (val > v[x]) add_point(r[x], val);
}

void print(const int &x) {
  if (!x) return;
  print(l[x]);
  print(r[x]);
  cout << v[x] << " ";
}

inline void solve() {
  rt = m = 0;
  memset(l, 0, sizeof l);
  memset(r, 0, sizeof r);
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    add_point(rt, a);
  }
  print(rt);
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) solve();
  return 0;
}