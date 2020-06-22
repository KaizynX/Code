/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 23:01:47
 * @LastEditTime: 2020-06-20 22:22:45
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2100;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, m, k;
int a[N], b[32], id[N];
map<pii, int> mp;

void add(const int &x, const int &v) {
  for (int i = 0; i < k; ++i) {
    if ((v>>i)&1) continue;
    if (b[i]) continue;
    b[i] = x;
    ++m;
  }
}

int query(int x, int y) {
  if (x == y) exit(0);
  if (x > y) swap(x, y);
  if (mp.count({x, y})) return mp[{x, y}];
  int res;
  cout << "? " << x << " " << y << endl;
  cin >> res;
  if (res == -1) exit(0);
  return mp[{x, y}] = res;
}

int magic(const int &x) {
  int res = (1<<k)-1;
  for (int i = 0; i < k; ++i) {
    if (b[i] == x) {
      res &= (1<<11)-1-(1<<i);
    } else {
      res &= query(x, b[i]);
    }
  }
  return res;
}

void answer() {
  cout << "!";
  for (int i = 1; i <= n; ++i) {
    cout << " " << a[i];
  }
  cout << endl;
}

inline void solve() {
  cin >> n;
  while (1<<k < n) ++k;
  // rand order
  for (int i = 1; i <= n; ++i) id[i] = i;
  for (int i = 2, j; i <= n; ++i) {
    j = rnd()%(i-1)+1;
    swap(id[i], id[j]);
  }
  int x = id[1], y = id[2], v = query(x, y);
  add(x, v);
  for (int i = 3, t; i <= n; ++i) {
    t = query(y, id[i]);
    add(y, t);
    if (v < t) {
      continue;
    } else if (v > t) {
      x = id[i];
      v = t;
    } else {
      y = id[i];
      v = query(x, y);
      add(y, v);
    }
  }
  while (m < k) {
    int t1 = rnd()%n+1, t2 = rnd()%(n-1)+1;
    t2 = (t1-1+t2)%n+1;
    add(t1, query(t1, t2));
  }
  if (magic(x)) swap(x, y);
  for (int i = 1; i <= n; ++i) {
    a[i] = (i == x ? 0 : query(i, x));
  }
  answer();
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