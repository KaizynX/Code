/*
 * @Author: Kaizyn
 * @Date: 2020-12-21 19:42:09
 * @LastEditTime: 2020-12-21 20:05:24
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 1e5+7;

int n, x, y;
int a[N], cntl[2], cntr[2];
ll k[2][2];
ll vall, valr, res;
string s;
vector<int> p;

ll calc() {
  return vall+valr+cntl[0]*cntr[1]*k[0][1]+cntl[1]*cntr[0]*k[1][0];
}

inline void solve() {
  // x 01, y 10
  cin >> s >> x >> y;
  if (x > y) {
    swap(x, y);
    for (char &c : s) {
      if (c == '1') c = '0';
      else if (c == '0') c = '1';
    }
  }
  n = s.size();
  k[0][1] = x;
  k[1][0] = y;
  for (int i = 1; i <= n; ++i) {
    a[i] = s[i-1] == '?' ? 0 : s[i-1]-'0';
    vall += k[a[i]^1][a[i]]*cntl[a[i]^1];
    ++cntl[a[i]];
  }
  res = calc();
#ifdef DEBUG
  printf("initial:%lld\n", res);
#endif
  for (int i = n; i >= 1; --i) {
    --cntl[a[i]];
    vall -= k[a[i]^1][a[i]]*cntl[a[i]^1];
    if (s[i-1] == '?') a[i] = 1;
    valr += k[a[i]][a[i]^1]*cntr[a[i]^1];
    ++cntr[a[i]];
    res = min(res, calc());
#ifdef DEBUG
    printf("%d:%lld l(%d,%d,%lld), r(%d,%d,%lld)\n", i, calc(), cntl[0], cntl[1], vall, cntr[0], cntr[1], valr);
#endif
  }
  cout << res << endl;
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}