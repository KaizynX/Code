/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 15:17:20
 * @LastEditTime: 2020-08-30 15:39:53
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

int n;
int aa[N], bb[N], a[N<<1], b[N], res[N], tmp[N];
int nex[N<<1];

inline void get_next(int s[], int sz) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0; i < sz; ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

inline void kmp() {
  for (int i = 0, j = 0; i < 2*n; ++i) {
    while (j && a[i] != b[j]) j = nex[j];
    if (a[i] == b[j]) ++j;
    if (j == n) {
      tmp[i-n+1] |= 1;
      j = nex[j];
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> aa[i];
  for (int i = 0; i < n; ++i) cin >> bb[i];
  for (int i = 0; i < n; ++i) res[i] = 1;
  for (int k = 0; k < 30; ++k) {
    for (int i = 0; i < n; ++i) {
      a[i] = a[i+n] = (aa[i]>>k)&1;
      b[i] = (bb[i]>>k)&1;
      tmp[i] = 0;
    }
    get_next(b, n);
    kmp();
    for (int i = 0; i < n; ++i) b[i] ^= 1;
    kmp();
    for (int i = 0; i < n; ++i) res[i] &= tmp[i];
  }
  for (int i = 0; i < n; ++i) {
    if (res[i]) cout << i << " " << (aa[i]^bb[0]) << endl;
  }
  return 0;
}