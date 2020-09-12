/*
 * @Author: Kaizyn
 * @Date: 2020-09-09 19:06:14
 * @LastEditTime: 2020-09-09 19:20:27
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

int n, m;
char s[N], t[N];
int nex[N][26];

int match(int beg) {
  int cur = beg-1;
  for (int i = 1; i <= m; ++i) {
    cur = nex[cur+1][t[i]-'a'];
    if (cur > n) return n+1;
  }
  return cur;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  scanf("%s%s", s+1, t+1);
  n = strlen(s+1);
  m = strlen(t+1);
  for (int i = 0; i < 26; ++i) nex[n+1][i] = n+1;
  for (int i = n; i; --i) {
    memcpy(nex[i], nex[i+1], sizeof(nex[i]));
    nex[i][s[i]-'a'] = i;
  }
  long long res = (n+1ll)*n/2;
  for (int i = 1; i <= n; ++i) {
    int j = match(i);
    #ifdef DEBUG
    cout << i << " " << j << endl;
    #endif
    res -= j-i;
    // res -= (j-i+1ll)*(j-i)/2;
  }
  cout << res << endl;
  return 0;
}