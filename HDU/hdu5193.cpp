/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 21:54:08
 * @LastEditTime: 2020-05-15 23:18:58
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e4+7;
const int NN = 2e2+7;

int n, m, t, k;
int a[N];
long long res;

struct Node {
  set<int> st;
  vector<int> vc;
  int& operator [] (const int &x) { return vc[x]; }
} f[NN];

inline void rebuild() {
  res = n = 0;
  for (int i = 0; i <= k; ++i) {
    for (const int &j : f[i].vc) {
      a[n++] = j;
    }
    f[i].st.clear();
    f[i].vc.clear();
  }
  k = (n-1)/t;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i/t; ++j) {
      res += f[j].st.end()-f[j].st.upper_bound(a[i]);
    }
    f[i/t].st.insert(a[i]);
    f[i/t].vc.emplace_back(a[i]);
  }
}

inline pii find_it(int x) {
  int i = 0;
  while (x >= f[i].vc.size()) {
    x -= f[i].vc.size();
    ++i;
  }
  return {i, x};
}

inline int calc(const int &x, const int &y) {
  int i = 0, j = 0, cnt = 0, res = 0;
  for ( ; cnt+f[i].vc.size() <= x; ++i, cnt += f[i].vc.size()) {
    res += f[i].st.end()-f[i].st.upper_bound(y);
  }
  for ( ; cnt < x; ++cnt, ++j) res += f[i][j] > y;
  ++j;
  for ( ; j < (int)f[i].vc.size(); ++j) res += f[i][j] < y;
  ++i;
  for ( ; i <= k; ++i) res += f[i].st.lower_bound(y)-f[i].st.begin();
  return res;
}

inline void insert(const int &x, const int &y) {
  pii pos = find_it(x);
  int i = pos.first, j = pos.second;
  f[i].st.insert(y);
  f[i].vc.insert(f[i].vc.begin()+j, y);
  res += calc(x, y);
}

inline void erase(const int &x) {
  pii pos = find_it(x);
  int i = pos.first, j = pos.second;
  res -= calc(x, f[i][j]);
  f[i].st.erase(f[i][j]);
  f[i].vc.erase(f[i].vc.begin()+j);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) {
    t = sqrt(n*1.5);
    k = 0;
    f[0].vc.resize(n);
    for (int i = 0; i < n; ++i) cin >> f[0][i];
    for (int i = 0, op, x, y; i < m; ++i) {
      if (i%t == 0) rebuild();
      cin >> op;
      if (op == 0) {
        cin >> x >> y;
        insert(x, y);
      } else {
        cin >> x;
        erase(x-1);
      }
    }
  }
  return 0;
}