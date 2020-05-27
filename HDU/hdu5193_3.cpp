/*
 * @Author: Kaizyn
 * @Date: 2020-05-19 10:31:38
 * @LastEditTime: 2020-05-19 16:39:37
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e4+7;
const int NN = 2e2+7;

struct Node {
  int rk[NN<<1], vc[NN<<1], n;
  int& operator [](const int &x) { return vc[x]; }
  void clear() { n = 0; }
  int size() { return n; }
  int* begin() { return rk; }
  int* end() { return rk+n; }
  void push_back(const int &x) { vc[n++] = x; }
  int* lower_bound(const int &val) { return std::lower_bound(rk, rk+n, val); }
  int* upper_bound(const int &val) { return std::upper_bound(rk, rk+n, val); }
  void insert(const int &x, const int &y) {
    int p = std::lower_bound(rk, rk+n, y)-rk;
    for (int i = n-1; i >= p; --i) rk[i+1] = rk[i];
    rk[p] = y;
    for (int i = n-1; i >= x; --i) vc[i+1] = vc[i];
    vc[x] = y;
    ++n;
  }
  void erase(const int &x) {
    int p = std::lower_bound(rk, rk+n, vc[x])-rk;
    for (int i = p; i < n-1; ++i) rk[i] = rk[i+1];
    for (int i = x; i < n-1; ++i) vc[i] = vc[i+1];
    --n;
  }
};

int n, m, t, k, res;
int a[N];
Node f[NN];

inline void rebuild(const int &flag = 1) {
  if (flag) {
    n = 0;
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j < f[i].size(); ++j) a[n++] = f[i][j];
      f[i].clear();
    }
  }
  k = max(0, (n-1)/t);
  for (int i = 0; i < n; ++i) f[i/t].push_back(a[i]);
  for (int i = 0; i <= k; ++i) {
    memcpy(f[i].rk, f[i].vc, sizeof(int)*f[i].size());
    sort(f[i].begin(), f[i].end());
  }
}

inline pii find_it(int x) {
  int i = 0;
  while (i < k && x >= f[i].size()) {
    x -= f[i].size();
    ++i;
  }
  return {i, x};
}

inline int calc(const int &x) {
  pii pos = find_it(x);
  int i = pos.first, j = pos.second, val = f[i][j], cnt = 0;
  for (int l = 0; l < i; ++l) cnt += f[l].end()-f[l].upper_bound(val);
  for (int l = 0; l < j; ++l) cnt += f[i][l] > val;
  for (int l = j+1; l < f[i].size(); ++l) cnt += f[i][l] < val;
  for (int l = i+1; l <= k; ++l) cnt += f[l].lower_bound(val)-f[l].begin();
  return cnt;
}

inline void insert(const int &x, const int &y) {
  pii pos = find_it(x);
  int i = pos.first, j = pos.second;
  f[i].insert(j , y);
  res += calc(x);
}

inline void erase(const int &x) {
  pii pos = find_it(x);
  int i = pos.first, j = pos.second;
  res -= calc(x);
  f[i].erase(j);
}

signed main() {
  while (scanf("%d %d", &n, &m) == 2) {
    t = sqrt(n+m)+1;
    for (int i = 0; i < n; ++i) scanf("%d", a+i);
    rebuild(0);
    res = 0;
    for (int i = 0; i < n; ++i) res += calc(i);
    res /= 2;

    for (int i = 1, op, x, y; i <= m; ++i) {
      scanf("%d", &op);
      if (op == 0) {
        scanf("%d %d", &x, &y);
        insert(x, y);
      } else {
        scanf("%d", &x);
        erase(x-1);
      }
      printf("%d\n", res);
      if (i%t == 0) rebuild();
    }
    for (int i = 0; i <= k; ++i) f[i].clear();
  }
  return 0;
}