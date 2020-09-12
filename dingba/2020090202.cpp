/*
 * @Author: Kaizyn
 * @Date: 2020-09-02 19:02:26
 * @LastEditTime: 2020-09-02 19:39:08
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
string a, b;
int nex[N<<1];

inline void get_next(const string &s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

inline bool kmp(const string &s1, const string &s2, int nex[]) {
  for (int i = 0, j = 0; i < (int)s1.size(); ++i) {
    while (j && s1[i] != s2[j]) j = nex[j];
    if (s1[i] == s2[j]) ++j;
    if (j == (int)s2.size()) return true;
  }
  return false;
}

inline bool solve() {
  cin >> n >> a >> b;
  a = a+a;
  b = b+b;
  get_next(b, nex);
  return kmp(a, b, nex);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}