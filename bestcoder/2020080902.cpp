/*
 * @Author: Kaizyn
 * @Date: 2020-08-09 18:51:24
 * @LastEditTime: 2020-08-09 19:57:32
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
int a[N], b[N], nex0[N], sum1[N], dif[N];
string s, t;

int magic(const string &str) {
  int res = 0;
  for (int i = n-1; i >= 0; --i) {
    res = res*2+str[i]-'0';
  }
  return res;
}

inline void solve() {
  cin >> n >> s >> t;
  /*
  if (n < 20) {
    int ss = magic(s), tt = magic(t);
    int res = __builtin_popcount(ss^tt);
    for (int i = 1; i <= res; ++i) {
      res = min(res, __builtin_popcount((ss+i)^tt)+i);
    }
    cout << res << endl;
    return;
  }
  */
  nex0[n] = n;
  dif[n] = 0;
  sum1[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    a[i] = s[i] == '1';
    if (!a[i]) nex0[i] = i;
    else nex0[i] = nex0[i+1];
    dif[i] = dif[i+1]+(s[i] != t[i]);
    sum1[i] = sum1[i+1]+(t[i] == '1');
  }

  int res = dif[0];
  for (int i = 1, j; i <= res; ++i) {
    int x = i, cnt = i;
    b[0] = a[0];
    // s+i
    for (j = 0; x; ++j, x >>= 1) {
      b[j+1] = a[j+1];
      b[j] += x&1;
      b[j+1] += b[j]/2;
      b[j] %= 2;
      cnt += (b[j] != t[j]-'0');
    }
    if (b[j] > 1) { // a[j] == 1, j > 0
      // nex0[j]'th
      if (nex0[j] >= n || t[nex0[j]] != '1') ++cnt;
      // [j, nex0[j])
      cnt += sum1[j]-sum1[nex0[j]];
      j = nex0[j]+1;
    } else {
      // j'th
      if (b[j] != (j >= n) ? 0 : t[j]-'0') ++cnt;
      ++j;
    }
    if (j < n) cnt += dif[j];
    res = min(res, cnt);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}