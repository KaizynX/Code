/*
 * @Author: Kaizyn
 * @Date: 2020-07-20 11:56:57
 * @LastEditTime: 2020-07-20 16:57:15
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, D, dep;
int f[N], k[N];
vector<int> e[N];

int get_depth(const int &u) {
  int ddd = 0;
  for (const int &v : e[u]) {
    ddd = max(ddd, get_depth(v));
  }
  return ddd+1;
}

int dfs(const int &u = 1) {
  int son = 0;
  for (const int &v : e[u]) {
    son = max(son, dfs(v));
  }
  if (u == 1 || son >= dep) ++k[dep], son = 0;
  return son+1;
}

inline int check(const int &mid) {
  if (k[mid]) return k[mid];
  dep = mid;
  dfs(1);
  return k[mid];
}

inline void solve() {
  for (int i = 2; i <= n; ++i) {
    cin >> f[i];
    e[f[i]].emplace_back(i);
  }
  D = get_depth(1);
  long long res = 0; // dep == 0
  if (D <= 1000) {
  // if (0) {
    int kk = n;
    for (dep = 1; dep < D; ++dep) {
      dfs(1);
      // [ k[dep], kk )
      res += 1ll*(kk-k[dep])*dep;
      kk = k[dep];
    }
  } else {
    int kk = n;
    // for (dep = 1; dep < kk*16 && dep < D; ++dep) {
    for (dep = 1; dep <= 1000; ++dep) {
      dfs(1);
      res += 1ll*(kk-k[dep])*dep;
      kk = k[dep];
    }
    // when k = kk, dep = 1000
    for (int kkk = 1, L = dep-1, R = D-1, l, r, mid; kkk < kk; ++kkk) {
      l = L;
      r = R;
      while (l < r) {
        mid = (l+r)>>1;
        if (check(mid) <= kkk) r = mid;
        else l = mid+1;
      }
      res += l;
      R = r;
    }
  }
  cout << res << endl;
  // clear
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(e[i]);
    k[i] = 0;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) solve();
  return 0;
}