/*
 * @Author: Kaizyn
 * @Date: 2021-07-04 23:28:45
 * @LastEditTime: 2021-07-04 23:37:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

inline void GetNext(char *s, int *_nex) {
  int len = strlen(s);
  int a = 0, p = 0;
  _nex[0] = len;
  for (int i = 1; i < len; ++i) {
    if (i >= p || i+_nex[i-a] >= p) {
      if (i > p) p = i;
      while (p < len && s[p] == s[p-i]) ++p;
      a = i;
      _nex[i] = p-i;
    } else {
      _nex[i] = _nex[i-a];
    }
  }
}

// extend[i]表示ss与S[i,n-1]的最长公共前缀
inline void GetExtend(char *s, char *ss, int *_ext, int *_nex) {
  int lens = strlen(s), lenss = strlen(ss);
  int a = 0, p = 0;
  for (int i = 0; i < lens; ++i) {
    if (i >= p || i+_nex[i-a] >= p) {
      if (i > p) p = i;
      while (p < lens && p-i < lenss && s[p] == ss[p-i]) ++p;
      a = i;
      _ext[i] = p-i;
    } else {
      _ext[i] = _nex[i-a];
    }
  }
}

int n, k;
char s[N];
int nex[N], ext[N];

inline void solve() {
  cin >> n >> k >> s;
  GetNext(s, nex);
  GetExtend(s, s, ext, nex);
  int m = 0;
  for (int p = 1; p < n; ++p) {
    if (s[p] > s[p%m]) break;
    int t = p-m;
    int l1 = ext[t];
    if (l1 < min(t, m-t)) {
      if (s[l1-1] >= s[t+l1-1]) m = p;
      continue;
    }
    int l2 = ext[m-t];
    if ()
  }
  for (int i = 0; i < k; ++i) cout << s[i%m];
  cout << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}