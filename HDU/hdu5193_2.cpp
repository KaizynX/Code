/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 21:54:08
 * @LastEditTime: 2020-05-16 19:17:43
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e4+7;
const int NN = 3e2+7;

struct Node {
  vector<int> rk, vc;
  int& operator [](const int &x) { return vc[x]; }
  vector<int>::iterator lower_bound(const int &val) {
    return std::lower_bound(rk.begin(), rk.end(), val);
  }
  vector<int>::iterator upper_bound(const int &val) {
    return std::upper_bound(rk.begin(), rk.end(), val);
  }
  vector<int>::iterator begin() { return rk.begin(); }
  vector<int>::iterator end() { return rk.end(); }
  void clear() { rk.clear(); vc.clear(); }
  int size() { return vc.size(); }
  void insert(const int &x, const int &y) {
    rk.insert(std::lower_bound(rk.begin(), rk.end(), y), y);
    vc.insert(vc.begin()+x, y);
  }
  void erase(const int &x) {
    rk.erase(std::lower_bound(rk.begin(), rk.end(), vc[x]));
    vc.erase(vc.begin()+x);
  }
};

int n, m, t, k;
int a[N];
long long res;
Node f[NN];

inline void rebuild() {
  n = 0;
  for (int i = 0; i <= k; ++i) {
    for (const int &j : f[i].vc) a[n++] = j;
    f[i].clear();
  }
  t = sqrt(n*1.233)+1;
  k = (n-1)/t;
  for (int i = 0; i <= k; ++i) f[i].clear();
  for (int i = 0; i < n; ++i) f[i/t].vc.emplace_back(a[i]);
  for (int i = 0; i <= k; ++i) {
    f[i].rk = f[i].vc;
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
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) {
    f[0].vc.resize(n);
    for (int i = 0; i < n; ++i) cin >> f[0][i];
    k = 0;
    rebuild();
    res = 0;
    for (int i = 0; i < n; ++i) res += calc(i);
    res /= 2;

    for (int i = 1, op, x, y, cir = sqrt(m)+1; i <= m; ++i) {
      if (i%cir == 0) rebuild();
      cin >> op;
      if (op == 0) {
        cin >> x >> y;
        insert(x, y);
      } else {
        cin >> x;
        erase(x-1);
      }
      cout << res << endl;
    }
    for (int i = 0; i <= k; ++i) f[i].clear();
  }
  return 0;
}