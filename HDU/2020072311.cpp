/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 11:54:09
 * @LastEditTime: 2020-07-23 12:55:11
 */ 
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 55;

typedef long long ll;
ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}

int n, k;
vector<int> id[N];
long long a[N], s, res;

void f(const int &u) {
  if (u > k) {
    long long tmp = 1, sum = s;
    for (int i = 1; i <= 4; ++i) {
      tmp *= sum%(1<<16);
      sum >>= 16;
    }
    res = max(res, tmp);
    return;
  }
  if (!id[u].size()) f(u+1);
  else for (auto &i : id[u]) {
    s += a[i];
    f(u+1);
    s -= a[i];
  }
}

inline void solve() {
  n=read(),k=read();
  for (int i = 1, t; i <= n; ++i) {
    t=read();
    a[i] = 0;
    for (int j = 1, b; j <= 4; ++j) {
      b=read();
      a[i] = (a[i]<<16)+b;
    }
    id[t].emplace_back(i);
  }
  res = 0;
  s = (((((100ll<<16)+100ll)<<16)+100ll)<<16)+100ll;
  f(1);
  printf("%lld\n",res);
  for (int i = 1; i <= n; ++i) {
    id[i].clear();
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  T=read();
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}