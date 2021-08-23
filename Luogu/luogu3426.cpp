/*
 * @Author: Kaizyn
 * @Date: 2021-08-23 15:05:19
 * @LastEditTime: 2021-08-23 15:17:52
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

int n;
char s[N];
int nex[N];

vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

inline void get_next() {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0, l = strlen(s); i < l; ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

inline bool check(int x) {
  int last = x-1;
  for (int i = x, j = nex[x]; i < n; ++i){
    while (j && s[i] != s[j]) j = nex[j];
    if (s[i] == s[j]) ++j;
    if (j == x) {
      #ifdef DEBUG
      cout << i << " ";
      #endif
      if (i-last > x) return false;
      last = i;
      j = nex[j];
    }
  }
  #ifdef DEBUG
  cout << "check" << x << '\n';
  #endif
  return last == n-1;
}

inline void solve() {
  scanf("%s", s);
  n = strlen(s);
  get_next();
  int l = 1, r = n, mid;
  while (l < r) {
    mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  #ifdef DEBUG
  check(8);
  #endif
  printf("%d\n", l);
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