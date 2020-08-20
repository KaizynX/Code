/*
 * @Author: Kaizyn
 * @Date: 2020-08-12 22:31:58
 * @LastEditTime: 2020-08-14 14:35:57
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
const int N = 2e5+7;
const int K = 10;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

struct HashNumber {
  static const int HN = 2;
  int a[HN], mod[HN] = {25165843, 50331653};
  HashNumber() { memset(a, 0, sizeof a); }
  template <typename U> HashNumber(const U &x) {
    for (int i = 0; i < HN; ++i) a[i] = x%mod[i];
  }
  friend bool operator ==(const HashNumber &lhs, const HashNumber &rhs) {
    for (int i = 0; i < HN; ++i) if (lhs.a[i] != rhs.a[i]) return false;
    return true;
  }
  friend bool operator !=(const HashNumber &lhs, const HashNumber &rhs) {
    return !(lhs == rhs);
  }
  HashNumber& operator +=(const HashNumber &hs) {
    for (int i = 0; i < HN; ++i) (a[i] += hs.a[i]) %= mod[i];
    return *this;
  }
  HashNumber& operator *=(const HashNumber &hs) {
    for (int i = 0; i < HN; ++i) a[i] = (1ll*a[i]*hs.a[i])%mod[i];
    return *this;
  }
  friend HashNumber operator +(const HashNumber &lhs, const HashNumber &rhs) {
    HashNumber res = lhs;
    return res += rhs;
  }
  friend HashNumber operator *(const HashNumber &lhs, const HashNumber &rhs) {
    HashNumber res = lhs;
    return res *= rhs;
  }
};

int n, m, k, res;
vector<pii> e[N];
vector<int> otdeg[K];
HashNumber ha[K][K], hm[K][K], hv[N], sum, mlt;

void dfs(const int &d, const HashNumber &add, const HashNumber &mul) {
  if (d > k) return res += add == sum && mul == mlt, void();
  for (int c = 0; c < d; ++c) {
    dfs(d+1, add+ha[d][c], mul*hm[d][c]);
  }
}

signed main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    e[u].emplace_back(w, v);
  }
  sum = 0;
  mlt = 1;
  for (int i = 1; i <= n; ++i) {
    hv[i] = rnd();
    sum += hv[i];
    mlt *= hv[i];
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < k; ++j) {
      hm[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    sort(e[i].begin(), e[i].end());
    int d = e[i].size();
    for (int c = 0; c < d; ++c) {
      int v = e[i][c].second;
      ha[d][c] += hv[v];
      hm[d][c] *= hv[v];
    }
  }
  dfs(1, 0, 1);
  printf("%d\n", res);
  return 0;
}