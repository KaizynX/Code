/*
 * @Author: Kaizyn
 * @Date: 2020-08-27 18:34:19
 * @LastEditTime: 2020-08-27 20:41:19
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
const int M = 1e6+7;

int n;
string s[N];
int nex[M][26], num[M][26], tot;

void insert(const string &s) {
  static int cnt[26];
  // memset(cnt, 0, sizeof cnt);
  for (const char &c : s) ++cnt[c-'a'];
  int p = 0;
  for (int i = s.size()-1, c; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) if (cnt[j]) ++num[p][j];
    c = s[i]-'a';
    if (!nex[p][c]) nex[p][c] = ++tot;
    p = nex[p][c];
    --cnt[c];
  }
}

int query(const string &s) {
  int p = 0;
  for (int i = s.size()-1, c; i; --i) {
    c = s[i]-'a';
    if (!nex[p][c]) return 0;
    p = nex[p][c];
  }
  return num[p][s[0]-'a']; // minus itself
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  sort(s+1, s+n+1, [](const string &s1, const string &s2) {
    return s1.size() < s2.size();
  });
  for (int i = 1; i <= n; ++i) {
    insert(s[i]);
  }
  long long res = -n; // (i, -i)
  for (int i = 1; i <= n; ++i) {
    res += query(s[i]);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}